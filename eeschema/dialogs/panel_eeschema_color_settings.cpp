/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020 Jon Evans <jon@craftyjon.com>
 * Copyright The KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <regex>

#include <eeschema_settings.h>
#include <gal/gal_display_options.h>
#include <gal/graphics_abstraction_layer.h>
#include <layer_ids.h>
#include <sch_shape.h>
#include <math/vector2wx.h>
#include <page_info.h>
#include <panel_eeschema_color_settings.h>
#include <pgm_base.h>
#include <sch_bus_entry.h>
#include <sch_junction.h>
#include <sch_line.h>
#include <sch_no_connect.h>
#include <sch_painter.h>
#include <sch_preview_panel.h>
#include <sch_sheet_pin.h>
#include <sch_text.h>
#include <settings/color_settings.h>
#include <settings/common_settings.h>
#include <settings/settings_manager.h>
#include <title_block.h>
#include <view/view.h>
#include <drawing_sheet/ds_proxy_view_item.h>
#include <sch_base_frame.h>
#include <widgets/color_swatch.h>
#include <widgets/wx_panel.h>
#include <wx/msgdlg.h>


std::set<int> g_excludedLayers =
        {
            LAYER_NOTES_BACKGROUND,
            LAYER_DANGLING,
            LAYER_NET_COLOR_HIGHLIGHT
        };


PANEL_EESCHEMA_COLOR_SETTINGS::PANEL_EESCHEMA_COLOR_SETTINGS( wxWindow* aParent ) :
        PANEL_COLOR_SETTINGS( aParent ),
        m_preview( nullptr ),
        m_page( nullptr ),
        m_titleBlock( nullptr ),
        m_drawingSheet( nullptr ),
        m_previewItems()
{
    m_colorNamespace = "schematic";

    SETTINGS_MANAGER&  mgr = Pgm().GetSettingsManager();
    COMMON_SETTINGS*   common_settings = Pgm().GetCommonSettings();
    EESCHEMA_SETTINGS* app_settings = mgr.GetAppSettings<EESCHEMA_SETTINGS>( "eeschema" );
    COLOR_SETTINGS*    current = mgr.GetColorSettings( app_settings->m_ColorTheme );

    // Saved theme doesn't exist?  Reset to default
    if( current->GetFilename() != app_settings->m_ColorTheme )
        app_settings->m_ColorTheme = current->GetFilename();

    createThemeList( app_settings->m_ColorTheme );

    m_optOverrideColors->SetValue( current->GetOverrideSchItemColors() );

    m_currentSettings = new COLOR_SETTINGS( *current );

    for( int id = SCH_LAYER_ID_START; id < SCH_LAYER_ID_END; id++ )
    {
        if( g_excludedLayers.count( id ) )
            continue;

        m_validLayers.push_back( id );
    }

    m_backgroundLayer = LAYER_SCHEMATIC_BACKGROUND;

    m_galDisplayOptions.ReadConfig( *common_settings, app_settings->m_Window, this );
    m_galDisplayOptions.m_forceDisplayCursor = false;

    m_galType = static_cast<EDA_DRAW_PANEL_GAL::GAL_TYPE>( app_settings->m_Graphics.canvas_type );
}


PANEL_EESCHEMA_COLOR_SETTINGS::~PANEL_EESCHEMA_COLOR_SETTINGS()
{
    delete m_page;
    delete m_titleBlock;
    delete m_drawingSheet;
    delete m_currentSettings;

    for( EDA_ITEM* item : m_previewItems )
    {
        // Avoid referencing items after they are deleted (we don't control order)
        item->SetParent( nullptr );
        delete item;
    }
}


bool PANEL_EESCHEMA_COLOR_SETTINGS::TransferDataFromWindow()
{
    m_currentSettings->SetOverrideSchItemColors( m_optOverrideColors->GetValue() );

    if( !saveCurrentTheme( true ) )
        return false;

    SETTINGS_MANAGER&  mgr = Pgm().GetSettingsManager();
    EESCHEMA_SETTINGS* cfg = mgr.GetAppSettings<EESCHEMA_SETTINGS>( "eeschema" );

    cfg->m_ColorTheme = m_currentSettings->GetFilename();

    return true;
}


bool PANEL_EESCHEMA_COLOR_SETTINGS::TransferDataToWindow()
{
    zoomFitPreview();
    return true;
}


bool PANEL_EESCHEMA_COLOR_SETTINGS::validateSave( bool aQuiet )
{
    COLOR4D bgcolor = m_currentSettings->GetColor( LAYER_SCHEMATIC_BACKGROUND );

    for( SCH_LAYER_ID layer = SCH_LAYER_ID_START; layer < SCH_LAYER_ID_END; ++layer )
    {
        if( bgcolor == m_currentSettings->GetColor( layer )
            && layer != LAYER_SCHEMATIC_BACKGROUND && layer != LAYER_SHEET_BACKGROUND )
        {
            wxString msg = _( "Some items have the same color as the background\n"
                              "and they will not be seen on the screen.  Are you\n"
                              "sure you want to use these colors?" );

            if( wxMessageBox( msg, _( "Warning" ), wxYES_NO | wxICON_QUESTION,
                              wxGetTopLevelParent( this ) ) == wxNO )
                return false;

            break;
        }
    }

    return true;
}


bool PANEL_EESCHEMA_COLOR_SETTINGS::saveCurrentTheme( bool aValidate)
{
    for( int layer : m_validLayers )
    {
        COLOR4D color = m_currentSettings->GetColor( layer );

        // Do not allow non-background layers to be completely white.
        // This ensures the BW printing recognizes that the colors should be printed black.
        if( color == COLOR4D::WHITE && layer != LAYER_SCHEMATIC_BACKGROUND
                && layer != LAYER_SHEET_BACKGROUND )
        {
            color.Darken( 0.01 );
        }

        m_currentSettings->SetColor( layer, color );
    }

    return PANEL_COLOR_SETTINGS::saveCurrentTheme( aValidate );
}


void PANEL_EESCHEMA_COLOR_SETTINGS::createSwatches()
{
    std::vector<SCH_LAYER_ID> layers;

    for( SCH_LAYER_ID i = SCH_LAYER_ID_START; i < SCH_LAYER_ID_END; ++i )
    {
        if( g_excludedLayers.count( i ) )
            continue;

        layers.push_back( i );
    }

    std::sort( layers.begin(), layers.end(),
               []( SCH_LAYER_ID a, SCH_LAYER_ID b )
               {
                   return LayerName( a ) < LayerName( b );
               } );

    for( int layer : layers )
    {
        wxString name = LayerName( layer );

        if( layer == LAYER_SCHEMATIC_GRID_AXES )
            name += wxS( " " ) + _( "(symbol editor only)" );

        createSwatch( layer, name );
    }

    // Give a minimal width to m_colorsListWindow, in order to always having
    // a full row shown
    int min_width = m_colorsGridSizer->GetMinSize().x;
    const int margin = 20;  // A margin around the sizer
    m_colorsListWindow->SetMinSize( wxSize( min_width + margin, -1 ) );

    m_preview = new SCH_PREVIEW_PANEL( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1, -1 ),
                                       m_galDisplayOptions, m_galType );
    m_preview->SetStealsFocus( false );
    m_preview->ShowScrollbars( wxSHOW_SB_NEVER, wxSHOW_SB_NEVER );
    m_preview->GetGAL()->SetAxesEnabled( false );

    SCH_RENDER_SETTINGS* settings = m_preview->GetRenderSettings();
    settings->m_IsSymbolEditor = true;

    m_colorsMainSizer->Add( m_preview, 1, wxTOP | wxEXPAND, 1 );

    m_colorsMainSizer->Layout();

    updateAllowedSwatches();
    createPreviewItems();
    updatePreview();
    zoomFitPreview();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::onNewThemeSelected()
{
    updatePreview();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::createPreviewItems()
{
    KIGFX::VIEW* view = m_preview->GetView();

    std::vector<DANGLING_END_ITEM> endPointsByType;

    m_page       = new PAGE_INFO( PAGE_INFO::Custom );
    m_titleBlock = new TITLE_BLOCK;
    m_titleBlock->SetTitle( _( "Color Preview" ) );
    m_titleBlock->SetDate( wxDateTime::Now().FormatDate() );

    m_page->SetHeightMils( 5000 );
    m_page->SetWidthMils( 6000 );

    m_drawingSheet = new DS_PROXY_VIEW_ITEM( schIUScale, m_page, nullptr, m_titleBlock, nullptr );
    m_drawingSheet->SetColorLayer( LAYER_SCHEMATIC_DRAWINGSHEET );
    m_drawingSheet->SetPageBorderColorLayer( LAYER_SCHEMATIC_PAGE_LIMITS );
    view->Add( m_drawingSheet );

    // TODO: It would be nice to parse a schematic file here.

    auto addItem = [&]( EDA_ITEM* aItem )
                   {
                       view->Add( aItem );
                       m_previewItems.push_back( aItem );
                   };

    std::vector<std::pair<SCH_LAYER_ID, std::pair<VECTOR2I, VECTOR2I>>> lines = {
                { LAYER_WIRE,  { { 1950, 1500 }, { 2325, 1500 } } },
                { LAYER_WIRE,  { { 1950, 2600 }, { 2350, 2600 } } },
                { LAYER_WIRE,  { { 2150, 1700 }, { 2325, 1700 } } },
                { LAYER_WIRE,  { { 2150, 2000 }, { 2150, 1700 } } },
                { LAYER_WIRE,  { { 2925, 1600 }, { 3075, 1600 } } },
                { LAYER_WIRE,  { { 3075, 1600 }, { 3075, 2000 } } },
                { LAYER_WIRE,  { { 3075, 1600 }, { 3250, 1600 } } },
                { LAYER_WIRE,  { { 3075, 2000 }, { 2150, 2000 } } },
                { LAYER_BUS,   { { 1750, 1300 }, { 1850, 1300 } } },
                { LAYER_BUS,   { { 1850, 2500 }, { 1850, 1300 } } },
                { LAYER_NOTES, { { 2350, 2125 }, { 2350, 2300 } } },
                { LAYER_NOTES, { { 2350, 2125 }, { 2950, 2125 } } },
                { LAYER_NOTES, { { 2950, 2125 }, { 2950, 2300 } } },
                { LAYER_NOTES, { { 2950, 2300 }, { 2350, 2300 } } }
            };

    for( const std::pair<SCH_LAYER_ID, std::pair<VECTOR2I, VECTOR2I>>& line : lines )
    {
        SCH_LINE* wire = new SCH_LINE;
        wire->SetLayer( line.first );
        STROKE_PARAMS stroke = wire->GetStroke();
        stroke.SetWidth( schIUScale.MilsToIU( 6 ) );

        if( line.first != LAYER_NOTES )
        {
            stroke.SetLineStyle( LINE_STYLE::SOLID );

            if( line.first == LAYER_BUS )
                stroke.SetWidth( schIUScale.MilsToIU( 12 ) );

        }

        wire->SetStroke( stroke );

        wire->SetStartPoint( VECTOR2I( schIUScale.MilsToIU( line.second.first.x ),
                                       schIUScale.MilsToIU( line.second.first.y ) ) );
        wire->SetEndPoint( VECTOR2I( schIUScale.MilsToIU( line.second.second.x ),
                                     schIUScale.MilsToIU( line.second.second.y ) ) );
        addItem( wire );
    }

#define MILS_POINT( x, y ) VECTOR2I( schIUScale.MilsToIU( x ), schIUScale.MilsToIU( y ) )

    SCH_NO_CONNECT* nc = new SCH_NO_CONNECT;
    nc->SetPosition( MILS_POINT( 2350, 2600 ) );
    addItem( nc );

    SCH_BUS_WIRE_ENTRY* e1 = new SCH_BUS_WIRE_ENTRY;
    e1->SetPosition( MILS_POINT( 1850, 1400 ) );
    addItem( e1 );

    SCH_BUS_WIRE_ENTRY* e2 = new SCH_BUS_WIRE_ENTRY;
    e2->SetPosition( MILS_POINT( 1850, 2500 ) );
    addItem( e2 );

    SCH_TEXT* t1 = new SCH_TEXT( MILS_POINT( 2650, 2240 ), wxT( "PLAIN TEXT" ) );
    addItem( t1 );

    SCH_LABEL* t2 = new SCH_LABEL( MILS_POINT( 1975, 1500 ), wxT( "LABEL_{0}" ) );
    t2->SetSpinStyle( SPIN_STYLE::SPIN::RIGHT );
    t2->SetIsDangling( false );
    addItem( t2 );

    SCH_LABEL* t3 = new SCH_LABEL( MILS_POINT( 1975, 2600 ), wxT( "LABEL_{1}" ) );
    t3->SetSpinStyle( SPIN_STYLE::SPIN::RIGHT );
    t3->SetIsDangling( false );
    addItem( t3 );

    SCH_GLOBALLABEL* t4 = new SCH_GLOBALLABEL( MILS_POINT( 1750, 1300 ), wxT( "GLOBAL[0..3]" ) );
    t4->SetSpinStyle( SPIN_STYLE::SPIN::LEFT );
    t4->SetIsDangling( false );
    addItem( t4 );

    SCH_HIERLABEL* t5 = new SCH_HIERLABEL( MILS_POINT( 3250, 1600 ), wxT( "HIER_LABEL" ) );
    t5->SetSpinStyle( SPIN_STYLE::SPIN::RIGHT );
    t5->SetIsDangling( false );
    addItem( t5 );

    SCH_JUNCTION* j = new SCH_JUNCTION( MILS_POINT( 3075, 1600 ) );
    addItem( j );

    t2->SetSelected();

    {
        auto mapLibItemPosition =
                []( const VECTOR2I& aLibPosition ) -> VECTOR2I
                {
                    // Currently, the mapping is a no-op.
                    return VECTOR2I( aLibPosition.x, aLibPosition.y );
                };

        LIB_SYMBOL* symbol = new LIB_SYMBOL( wxEmptyString );
        VECTOR2I p( 2625, 1600 );

        SCH_FIELD& ref = symbol->GetReferenceField();

        ref.SetText( wxT( "U1" ) );
        ref.SetPosition( MILS_POINT( p.x + 30, p.y - 260 ) );
        ref.SetHorizJustify( GR_TEXT_H_ALIGN_LEFT );

        SCH_FIELD& value = symbol->GetValueField();

        value.SetText( wxT( "OPA604" ) );
        value.SetPosition( MILS_POINT( p.x + 30, p.y - 180 ) );
        value.SetHorizJustify( GR_TEXT_H_ALIGN_LEFT );

        symbol->SetShowPinNames( true );
        symbol->SetShowPinNumbers( true );
        symbol->SetPinNameOffset( 0 );

        SCH_SHAPE* comp_body = new SCH_SHAPE( SHAPE_T::POLY, LAYER_DEVICE );

        comp_body->SetParent( symbol );
        comp_body->SetUnit( 0 );
        comp_body->SetBodyStyle( 0 );
        comp_body->SetStroke( STROKE_PARAMS( schIUScale.MilsToIU( 10 ), LINE_STYLE::SOLID ) );
        comp_body->SetFillMode( FILL_T::FILLED_WITH_BG_BODYCOLOR );
        comp_body->AddPoint( MILS_POINT( p.x - 200, p.y + 200 ) );
        comp_body->AddPoint( MILS_POINT( p.x + 200, p.y ) );
        comp_body->AddPoint( MILS_POINT( p.x - 200, p.y - 200 ) );
        comp_body->AddPoint( MILS_POINT( p.x - 200, p.y + 200 ) );

        addItem( comp_body );

        SCH_PIN* pin = new SCH_PIN( symbol );

        pin->SetPosition( MILS_POINT( p.x - 300, p.y - 100 ) );
        pin->SetLength( schIUScale.MilsToIU( 100 ) );
        pin->SetOrientation( PIN_ORIENTATION::PIN_RIGHT );
        pin->SetType( ELECTRICAL_PINTYPE::PT_INPUT );
        pin->SetNumber( wxT( "1" ) );
        pin->SetName( wxT( "-" ) );
        pin->SetNumberTextSize( schIUScale.MilsToIU( 50 ) );
        pin->SetNameTextSize( schIUScale.MilsToIU( 50 ) );

        endPointsByType.emplace_back( PIN_END, pin, mapLibItemPosition( pin->GetPosition() ) );
        symbol->AddDrawItem( pin );

        pin = new SCH_PIN( symbol );

        pin->SetPosition( MILS_POINT( p.x - 300, p.y + 100 ) );
        pin->SetLength( schIUScale.MilsToIU( 100 ) );
        pin->SetOrientation( PIN_ORIENTATION::PIN_RIGHT );
        pin->SetType( ELECTRICAL_PINTYPE::PT_INPUT );
        pin->SetNumber( wxT( "2" ) );
        pin->SetName( wxT( "+" ) );
        pin->SetNumberTextSize( schIUScale.MilsToIU( 50 ) );
        pin->SetNameTextSize( schIUScale.MilsToIU( 50 ) );

        endPointsByType.emplace_back( PIN_END, pin, mapLibItemPosition( pin->GetPosition() ) );
        symbol->AddDrawItem( pin );

        pin = new SCH_PIN( symbol );

        pin->SetPosition( MILS_POINT( p.x + 300, p.y ) );
        pin->SetLength( schIUScale.MilsToIU( 100 ) );
        pin->SetOrientation( PIN_ORIENTATION::PIN_LEFT );
        pin->SetType( ELECTRICAL_PINTYPE::PT_OUTPUT );
        pin->SetNumber( wxT( "3" ) );
        pin->SetName( wxT( "OUT" ) );
        pin->SetNumberTextSize( schIUScale.MilsToIU( 50 ) );
        pin->SetNameTextSize( schIUScale.MilsToIU( 50 ) );

        endPointsByType.emplace_back( PIN_END, pin, mapLibItemPosition( pin->GetPosition() ) );
        symbol->AddDrawItem( pin );

        addItem( symbol );
    }

    SCH_SHEET* s = new SCH_SHEET(
            /* aParent */ nullptr,
            /* aPosition */ MILS_POINT( 4000, 1300 ),
            /* aSize */ VECTOR2I( schIUScale.MilsToIU( 800 ), schIUScale.MilsToIU( 1300 ) ) );
    s->GetFields().at( SHEETNAME ).SetText( wxT( "SHEET" ) );
    s->GetFields().at( SHEETFILENAME ).SetText( _( "/path/to/sheet" ) );
    s->AutoplaceFields( nullptr, AUTOPLACE_AUTO );
    addItem( s );

    SCH_SHEET_PIN* sp = new SCH_SHEET_PIN( s, MILS_POINT( 4500, 1500 ), wxT( "SHEET PIN" ) );
    addItem( sp );

    for( EDA_ITEM* item : m_previewItems )
    {
        SCH_ITEM* sch_item = dynamic_cast<SCH_ITEM*>( item );

        if( sch_item && sch_item->IsConnectable() )
        {
            sch_item->AutoplaceFields( nullptr, AUTOPLACE_AUTO );
            sch_item->GetEndPoints( endPointsByType );
        }
    }

    std::vector<DANGLING_END_ITEM> endPointsByPos = endPointsByType;
    DANGLING_END_ITEM_HELPER::sort_dangling_end_items( endPointsByType, endPointsByPos );

    for( EDA_ITEM* item : m_previewItems )
    {
        SCH_ITEM* sch_item = dynamic_cast<SCH_ITEM*>( item );

        if( sch_item && sch_item->IsConnectable() )
            sch_item->UpdateDanglingState( endPointsByType, endPointsByPos, nullptr );
    }

    zoomFitPreview();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::onColorChanged()
{
    updatePreview();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::ResetPanel()
{
    PANEL_COLOR_SETTINGS::ResetPanel();
    updatePreview();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::updatePreview()
{
    if( !m_preview )
        return;

    KIGFX::VIEW* view = m_preview->GetView();
    auto settings = static_cast<SCH_RENDER_SETTINGS*>( view->GetPainter()->GetSettings() );
    settings->LoadColors( m_currentSettings );

    m_preview->GetGAL()->SetClearColor( settings->GetBackgroundColor() );

    view->UpdateAllItems( KIGFX::COLOR );
    auto rect = m_preview->GetScreenRect();
    m_preview->Refresh( true, &rect );
}


void PANEL_EESCHEMA_COLOR_SETTINGS::zoomFitPreview()
{
    if( m_preview )
    {
        KIGFX::VIEW* view = m_preview->GetView();

        view->SetScale( 1.0 );
        VECTOR2D screenSize = view->ToWorld( ToVECTOR2D( m_preview->GetClientSize() ), false );

        VECTOR2I psize( m_page->GetWidthIU( schIUScale.IU_PER_MILS ),
                        m_page->GetHeightIU( schIUScale.IU_PER_MILS ) );
        double scale = view->GetScale() / std::max( fabs( psize.x / screenSize.x ),
                                                    fabs( psize.y / screenSize.y ) );

        view->SetScale( scale * m_galDisplayOptions.m_scaleFactor * 0.8 /* margin */ );
        view->SetCenter( m_drawingSheet->ViewBBox().Centre() );
        m_preview->ForceRefresh();
    }
}


void PANEL_EESCHEMA_COLOR_SETTINGS::OnSize( wxSizeEvent& aEvent )
{
    zoomFitPreview();
    aEvent.Skip();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::updateAllowedSwatches()
{
    // If the theme is not overriding individual item colors then don't show them so that
    // the user doesn't get seduced into thinking they'll have some effect.
    m_labels[ LAYER_SHEET ]->Show( m_currentSettings->GetOverrideSchItemColors() );
    m_swatches[ LAYER_SHEET ]->Show( m_currentSettings->GetOverrideSchItemColors() );

    m_labels[ LAYER_SHEET_BACKGROUND ]->Show( m_currentSettings->GetOverrideSchItemColors() );
    m_swatches[ LAYER_SHEET_BACKGROUND ]->Show( m_currentSettings->GetOverrideSchItemColors() );

    m_colorsGridSizer->Layout();
    m_colorsListWindow->Layout();
}


void PANEL_EESCHEMA_COLOR_SETTINGS::OnOverrideItemColorsClicked( wxCommandEvent& aEvent )
{
    m_currentSettings->SetOverrideSchItemColors( m_optOverrideColors->GetValue() );
    updateAllowedSwatches();
}
