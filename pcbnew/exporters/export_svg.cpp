/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2012 Jean-Pierre Charras, jp.charras at wanadoo.fr
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

#include "board.h"
#include "locale_io.h"
#include "export_svg.h"
#include "pcbplot.h"
#include "pgm_base.h"
#include "plotters/plotters_pslike.h"


bool EXPORT_SVG::Plot( BOARD* aBoard, const PCB_PLOT_SVG_OPTIONS& aSvgPlotOptions )
{
    PCB_PLOT_PARAMS plot_opts;
    wxString        outputFile = aSvgPlotOptions.m_outputFile;

    plot_opts.SetPlotFrameRef( aSvgPlotOptions.m_plotFrame );

    if( aSvgPlotOptions.m_sketchPadsOnFabLayers )
    {
        plot_opts.SetSketchPadsOnFabLayers( true );
        plot_opts.SetPlotPadNumbers( true );
    }

    plot_opts.SetHideDNPFPsOnFabLayers( aSvgPlotOptions.m_hideDNPFPsOnFabLayers );
    plot_opts.SetSketchDNPFPsOnFabLayers( aSvgPlotOptions.m_sketchDNPFPsOnFabLayers );
    plot_opts.SetCrossoutDNPFPsOnFabLayers( aSvgPlotOptions.m_crossoutDNPFPsOnFabLayers );

    // Adding drill marks, for copper layers
    if( ( LSET( { aSvgPlotOptions.m_printMaskLayer } ) & LSET::AllCuMask() ).any() )
    {
        switch( aSvgPlotOptions.m_drillShapeOption )
        {
        default:
        case 0:  plot_opts.SetDrillMarksType( DRILL_MARKS::NO_DRILL_SHAPE );    break;
        case 1:  plot_opts.SetDrillMarksType( DRILL_MARKS::SMALL_DRILL_SHAPE ); break;
        case 2:  plot_opts.SetDrillMarksType( DRILL_MARKS::FULL_DRILL_SHAPE );  break;
        }
    }
    else
    {
        plot_opts.SetDrillMarksType( DRILL_MARKS::NO_DRILL_SHAPE );
    }

    plot_opts.SetSkipPlotNPTH_Pads( false );

    plot_opts.SetMirror( aSvgPlotOptions.m_mirror );
    plot_opts.SetNegative( aSvgPlotOptions.m_negative );
    plot_opts.SetFormat( PLOT_FORMAT::SVG );
    plot_opts.SetSvgPrecision( aSvgPlotOptions.m_precision );

    PAGE_INFO savedPageInfo = aBoard->GetPageSettings();
    VECTOR2I  savedAuxOrigin = aBoard->GetDesignSettings().GetAuxOrigin();

    if( aSvgPlotOptions.m_pageSizeMode == 2 ) // Page is board boundary size
    {
        BOX2I     bbox = aBoard->ComputeBoundingBox( false );
        PAGE_INFO currpageInfo = aBoard->GetPageSettings();

        currpageInfo.SetWidthMils( bbox.GetWidth() / pcbIUScale.IU_PER_MILS );
        currpageInfo.SetHeightMils( bbox.GetHeight() / pcbIUScale.IU_PER_MILS );
        aBoard->SetPageSettings( currpageInfo );
        plot_opts.SetUseAuxOrigin( true );
        VECTOR2I origin = bbox.GetOrigin();
        aBoard->GetDesignSettings().SetAuxOrigin( origin );
    }

    if( outputFile.IsEmpty() )
    {
        wxFileName fn = aBoard->GetFileName();
        fn.SetName( fn.GetName() );
        fn.SetExt( wxS( "svg" ) );

        outputFile = fn.GetFullName();
    }

    SETTINGS_MANAGER& mgr = Pgm().GetSettingsManager();

    plot_opts.SetColorSettings( mgr.GetColorSettings( aSvgPlotOptions.m_colorTheme ) );

    LOCALE_IO    toggle;
    PCB_LAYER_ID layer = UNDEFINED_LAYER;
    wxString     layerName;
    //@todo allow controlling the sheet name and path that will be displayed in the title block
    // Leave blank for now
    wxString     sheetName;
    wxString     sheetPath;

    if( aSvgPlotOptions.m_printMaskLayer.size() == 1 )
    {
        layer = aSvgPlotOptions.m_printMaskLayer.front();
        layerName = aBoard->GetLayerName( layer );
    }

    SVG_PLOTTER* plotter = (SVG_PLOTTER*) StartPlotBoard( aBoard, &plot_opts, layer, layerName,
                                                          outputFile, sheetName, sheetPath );

    if( plotter )
    {
        plotter->SetColorMode( !aSvgPlotOptions.m_blackAndWhite );
        PlotBoardLayers( aBoard, plotter, aSvgPlotOptions.m_printMaskLayer, plot_opts );
        plotter->EndPlot();

        delete plotter;

        // reset to the values saved earlier
        aBoard->GetDesignSettings().SetAuxOrigin( savedAuxOrigin );
        aBoard->SetPageSettings( savedPageInfo );

        return true;
    }
    else
    {
        return false;
    }
}
