///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "widgets/std_bitmap_button.h"
#include "widgets/wx_grid.h"

#include "dialog_lib_symbol_properties_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_LIB_SYMBOL_PROPERTIES_BASE::DIALOG_LIB_SYMBOL_PROPERTIES_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bUpperSizer;
	bUpperSizer = new wxBoxSizer( wxVERTICAL );

	m_NoteBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0|wxTAB_TRAVERSAL );
	m_PanelBasic = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerBasicPanel;
	bSizerBasicPanel = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_PanelBasic, wxID_ANY, _("Fields") ), wxVERTICAL );

	m_grid = new WX_GRID( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid->CreateGrid( 4, 14 );
	m_grid->EnableEditing( true );
	m_grid->EnableGridLines( true );
	m_grid->EnableDragGridSize( false );
	m_grid->SetMargins( 0, 0 );

	// Columns
	m_grid->SetColSize( 0, 72 );
	m_grid->SetColSize( 1, 120 );
	m_grid->SetColSize( 2, 48 );
	m_grid->SetColSize( 3, 84 );
	m_grid->SetColSize( 4, 70 );
	m_grid->SetColSize( 5, 70 );
	m_grid->SetColSize( 6, 48 );
	m_grid->SetColSize( 7, 48 );
	m_grid->SetColSize( 8, 84 );
	m_grid->SetColSize( 9, 84 );
	m_grid->SetColSize( 10, 84 );
	m_grid->SetColSize( 11, 84 );
	m_grid->SetColSize( 12, 140 );
	m_grid->SetColSize( 13, 48 );
	m_grid->EnableDragColMove( false );
	m_grid->EnableDragColSize( true );
	m_grid->SetColLabelValue( 0, _("Name") );
	m_grid->SetColLabelValue( 1, _("Value") );
	m_grid->SetColLabelValue( 2, _("Show") );
	m_grid->SetColLabelValue( 3, _("Show Name") );
	m_grid->SetColLabelValue( 4, _("H Align") );
	m_grid->SetColLabelValue( 5, _("V Align") );
	m_grid->SetColLabelValue( 6, _("Italic") );
	m_grid->SetColLabelValue( 7, _("Bold") );
	m_grid->SetColLabelValue( 8, _("Text Size") );
	m_grid->SetColLabelValue( 9, _("Orientation") );
	m_grid->SetColLabelValue( 10, _("X Position") );
	m_grid->SetColLabelValue( 11, _("Y Position") );
	m_grid->SetColLabelValue( 12, _("Font") );
	m_grid->SetColLabelValue( 13, _("Color") );
	m_grid->SetColLabelSize( 22 );
	m_grid->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid->EnableDragRowSize( true );
	m_grid->SetRowLabelSize( 0 );
	m_grid->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_CENTER );
	m_grid->SetMinSize( wxSize( -1,160 ) );

	sbSizer4->Add( m_grid, 1, wxALL|wxEXPAND, 5 );

	bButtonSize = new wxBoxSizer( wxHORIZONTAL );

	m_bpAdd = new STD_BITMAP_BUTTON( sbSizer4->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	m_bpAdd->SetToolTip( _("Add field") );

	bButtonSize->Add( m_bpAdd, 0, wxRIGHT|wxLEFT, 5 );

	m_bpMoveUp = new STD_BITMAP_BUTTON( sbSizer4->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	m_bpMoveUp->SetToolTip( _("Move up") );

	bButtonSize->Add( m_bpMoveUp, 0, wxRIGHT, 5 );

	m_bpMoveDown = new STD_BITMAP_BUTTON( sbSizer4->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	m_bpMoveDown->SetToolTip( _("Move down") );

	bButtonSize->Add( m_bpMoveDown, 0, wxRIGHT, 5 );


	bButtonSize->Add( 20, 0, 0, wxEXPAND, 5 );

	m_bpDelete = new STD_BITMAP_BUTTON( sbSizer4->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	m_bpDelete->SetToolTip( _("Delete field") );

	bButtonSize->Add( m_bpDelete, 0, wxRIGHT|wxLEFT, 10 );


	sbSizer4->Add( bButtonSize, 0, wxEXPAND|wxBOTTOM, 5 );


	bSizerBasicPanel->Add( sbSizer4, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	wxBoxSizer* bSizerMidBasicPanel;
	bSizerMidBasicPanel = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizerFPID;
	fgSizerFPID = new wxFlexGridSizer( 4, 2, 3, 0 );
	fgSizerFPID->AddGrowableCol( 1 );
	fgSizerFPID->SetFlexibleDirection( wxBOTH );
	fgSizerFPID->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticText* staticNameLabel;
	staticNameLabel = new wxStaticText( m_PanelBasic, wxID_ANY, _("Symbol name:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticNameLabel->Wrap( -1 );
	fgSizerFPID->Add( staticNameLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 8 );

	m_SymbolNameCtrl = new wxTextCtrl( m_PanelBasic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerFPID->Add( m_SymbolNameCtrl, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxRIGHT, 8 );

	staticKeywordsLabel = new wxStaticText( m_PanelBasic, wxID_ANY, _("Keywords:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticKeywordsLabel->Wrap( -1 );
	fgSizerFPID->Add( staticKeywordsLabel, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 8 );

	m_KeywordCtrl = new wxTextCtrl( m_PanelBasic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerFPID->Add( m_KeywordCtrl, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxRIGHT, 8 );

	m_inheritsStaticText = new wxStaticText( m_PanelBasic, wxID_ANY, _("Derive from symbol:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_inheritsStaticText->Wrap( -1 );
	fgSizerFPID->Add( m_inheritsStaticText, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 8 );

	m_inheritanceSelectCombo = new wxComboBox( m_PanelBasic, wxID_ANY, _("<None>"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	m_inheritanceSelectCombo->SetToolTip( _("Select symbol to derive this symbol from or select\n<None> for root symbol.\n\nDerived symbols were formerly referred to as aliases.\nThis is no longer the case and all symbols are either\nderived from another symbols or they stand alone as\nroot symbols.") );

	fgSizerFPID->Add( m_inheritanceSelectCombo, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxRIGHT, 7 );


	bSizerMidBasicPanel->Add( fgSizerFPID, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	bSizerBasicPanel->Add( bSizerMidBasicPanel, 0, wxEXPAND, 5 );

	bSizerLowerBasicPanel = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizerLeftCol;
	bSizerLeftCol = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerSymbol;
	sbSizerSymbol = new wxStaticBoxSizer( new wxStaticBox( m_PanelBasic, wxID_ANY, _("General") ), wxVERTICAL );

	wxBoxSizer* bSizerUnitCount;
	bSizerUnitCount = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextNbUnits = new wxStaticText( sbSizerSymbol->GetStaticBox(), wxID_ANY, _("Number of units:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNbUnits->Wrap( -1 );
	m_staticTextNbUnits->SetToolTip( _("Enter the number of units for a symbol that contains more than one unit") );

	bSizerUnitCount->Add( m_staticTextNbUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_SelNumberOfUnits = new wxSpinCtrl( sbSizerSymbol->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 64, 1 );
	bSizerUnitCount->Add( m_SelNumberOfUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );


	sbSizerSymbol->Add( bSizerUnitCount, 1, wxEXPAND|wxLEFT, 4 );

	m_OptionPartsInterchangeable = new wxCheckBox( sbSizerSymbol->GetStaticBox(), wxID_ANY, _("All units are interchangeable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_OptionPartsInterchangeable->SetToolTip( _("Check this option when all symbol units have the same function.\nFor instance, this should be checked for a quad NAND gate, while it should not be checked for a dual triode (where unit C is the filament).") );

	sbSizerSymbol->Add( m_OptionPartsInterchangeable, 0, wxALL, 4 );


	sbSizerSymbol->Add( 0, 8, 0, wxEXPAND, 5 );

	m_hasAlternateBodyStyles = new wxCheckBox( sbSizerSymbol->GetStaticBox(), wxID_ANY, _("Has alternate body style (De Morgan)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_hasAlternateBodyStyles->SetToolTip( _("Check this option if the symbol has an alternate body style for a De Morgan logic equivalence.\nFor instance, this should be checked for a NAND gate to provide an alternate representation as an OR gate with inverted inputs.") );

	sbSizerSymbol->Add( m_hasAlternateBodyStyles, 0, wxBOTTOM|wxRIGHT|wxLEFT, 4 );


	sbSizerSymbol->Add( 0, 7, 0, wxEXPAND, 5 );

	m_OptionPower = new wxCheckBox( sbSizerSymbol->GetStaticBox(), wxID_ANY, _("Define as power symbol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_OptionPower->SetToolTip( _("Setting this option makes the symbol in question appear in the\n\"add power symbol\" dialog.  It will lock the value text to protect it\nfrom editing in the schematic.  The symbol will not be included in\nthe BOM and cannot be assigned a footprint.") );

	sbSizerSymbol->Add( m_OptionPower, 0, wxBOTTOM|wxRIGHT|wxLEFT, 4 );


	bSizerLeftCol->Add( sbSizerSymbol, 0, wxEXPAND|wxALL, 5 );


	bSizerLowerBasicPanel->Add( bSizerLeftCol, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerMiddleCol;
	bSizerMiddleCol = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerPinTextOpts;
	sbSizerPinTextOpts = new wxStaticBoxSizer( new wxStaticBox( m_PanelBasic, wxID_ANY, _("Pin Text Options") ), wxVERTICAL );

	m_ShowPinNumButt = new wxCheckBox( sbSizerPinTextOpts->GetStaticBox(), wxID_ANY, _("Show pin number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ShowPinNumButt->SetValue(true);
	m_ShowPinNumButt->SetToolTip( _("Show or hide pin numbers") );

	sbSizerPinTextOpts->Add( m_ShowPinNumButt, 0, wxRIGHT|wxLEFT, 5 );

	m_ShowPinNameButt = new wxCheckBox( sbSizerPinTextOpts->GetStaticBox(), wxID_ANY, _("Show pin name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ShowPinNameButt->SetValue(true);
	m_ShowPinNameButt->SetToolTip( _("Show or hide pin names") );

	sbSizerPinTextOpts->Add( m_ShowPinNameButt, 0, wxTOP|wxRIGHT|wxLEFT, 5 );


	sbSizerPinTextOpts->Add( 0, 12, 0, wxEXPAND, 5 );

	m_PinsNameInsideButt = new wxCheckBox( sbSizerPinTextOpts->GetStaticBox(), wxID_ANY, _("Place pin names inside"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PinsNameInsideButt->SetValue(true);
	m_PinsNameInsideButt->SetToolTip( _("Check this option to have pin names inside the body and pin number outside.\nIf not checked pins names and pins numbers are outside.") );

	sbSizerPinTextOpts->Add( m_PinsNameInsideButt, 0, wxTOP|wxRIGHT|wxLEFT, 5 );

	wxBoxSizer* bSizerNameOffset;
	bSizerNameOffset = new wxBoxSizer( wxHORIZONTAL );

	m_nameOffsetLabel = new wxStaticText( sbSizerPinTextOpts->GetStaticBox(), wxID_ANY, _("Position offset:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_nameOffsetLabel->Wrap( -1 );
	m_nameOffsetLabel->SetToolTip( _("Margin between the pin name position and the symbol body.") );

	bSizerNameOffset->Add( m_nameOffsetLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 24 );

	m_nameOffsetCtrl = new wxTextCtrl( sbSizerPinTextOpts->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerNameOffset->Add( m_nameOffsetCtrl, 1, wxLEFT|wxRIGHT, 5 );

	m_nameOffsetUnits = new wxStaticText( sbSizerPinTextOpts->GetStaticBox(), wxID_ANY, _("units"), wxDefaultPosition, wxDefaultSize, 0 );
	m_nameOffsetUnits->Wrap( -1 );
	bSizerNameOffset->Add( m_nameOffsetUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );


	sbSizerPinTextOpts->Add( bSizerNameOffset, 0, wxBOTTOM|wxEXPAND|wxTOP, 4 );


	sbSizerPinTextOpts->Add( 0, 0, 0, wxEXPAND, 5 );


	bSizerMiddleCol->Add( sbSizerPinTextOpts, 1, wxALL|wxEXPAND, 5 );


	bSizerLowerBasicPanel->Add( bSizerMiddleCol, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerRightCol;
	bSizerRightCol = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerAttributes;
	sbSizerAttributes = new wxStaticBoxSizer( new wxStaticBox( m_PanelBasic, wxID_ANY, _("Attributes") ), wxVERTICAL );

	m_excludeFromSimCheckBox = new wxCheckBox( sbSizerAttributes->GetStaticBox(), wxID_ANY, _("Exclude from simulation"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerAttributes->Add( m_excludeFromSimCheckBox, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	sbSizerAttributes->Add( 0, 10, 0, wxEXPAND, 5 );

	m_excludeFromBomCheckBox = new wxCheckBox( sbSizerAttributes->GetStaticBox(), wxID_ANY, _("Exclude from bill of materials"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerAttributes->Add( m_excludeFromBomCheckBox, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_excludeFromBoardCheckBox = new wxCheckBox( sbSizerAttributes->GetStaticBox(), wxID_ANY, _("Exclude from board"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerAttributes->Add( m_excludeFromBoardCheckBox, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	bSizerRightCol->Add( sbSizerAttributes, 1, wxEXPAND|wxALL, 5 );


	bSizerLowerBasicPanel->Add( bSizerRightCol, 1, wxEXPAND, 5 );


	bSizerBasicPanel->Add( bSizerLowerBasicPanel, 0, wxEXPAND, 5 );


	m_PanelBasic->SetSizer( bSizerBasicPanel );
	m_PanelBasic->Layout();
	bSizerBasicPanel->Fit( m_PanelBasic );
	m_NoteBook->AddPage( m_PanelBasic, _("General"), false );
	m_PanelFootprintFilter = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bPanelFpFilterBoxSizer;
	bPanelFpFilterBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bFpFilterLeftBoxSizer;
	bFpFilterLeftBoxSizer = new wxBoxSizer( wxVERTICAL );

	m_staticTextFootprints = new wxStaticText( m_PanelFootprintFilter, wxID_ANY, _("Footprint filters:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFootprints->Wrap( -1 );
	m_staticTextFootprints->SetToolTip( _("A list of footprints names that can be used for this symbol.\nFootprints names can used wildcards like sm* to allow all footprints names starting by sm.") );

	bFpFilterLeftBoxSizer->Add( m_staticTextFootprints, 0, wxRIGHT|wxLEFT, 5 );

	m_FootprintFilterListBox = new wxListBox( m_PanelFootprintFilter, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_MULTIPLE );
	bFpFilterLeftBoxSizer->Add( m_FootprintFilterListBox, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );

	wxBoxSizer* bFpFilterRightBoxSizer;
	bFpFilterRightBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	m_addFilterButton = new STD_BITMAP_BUTTON( m_PanelFootprintFilter, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );
	m_addFilterButton->SetToolTip( _("Add footprint filter") );

	bFpFilterRightBoxSizer->Add( m_addFilterButton, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_editFilterButton = new STD_BITMAP_BUTTON( m_PanelFootprintFilter, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );
	m_editFilterButton->SetToolTip( _("Edit footprint filter") );

	bFpFilterRightBoxSizer->Add( m_editFilterButton, 0, wxALL, 5 );


	bFpFilterRightBoxSizer->Add( 20, 0, 0, wxEXPAND, 5 );

	m_deleteFilterButton = new STD_BITMAP_BUTTON( m_PanelFootprintFilter, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );
	m_deleteFilterButton->SetToolTip( _("Delete footprint filter") );

	bFpFilterRightBoxSizer->Add( m_deleteFilterButton, 0, wxALL, 5 );


	bFpFilterLeftBoxSizer->Add( bFpFilterRightBoxSizer, 0, 0, 5 );


	bPanelFpFilterBoxSizer->Add( bFpFilterLeftBoxSizer, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );


	m_PanelFootprintFilter->SetSizer( bPanelFpFilterBoxSizer );
	m_PanelFootprintFilter->Layout();
	bPanelFpFilterBoxSizer->Fit( m_PanelFootprintFilter );
	m_NoteBook->AddPage( m_PanelFootprintFilter, _("Footprint Filters"), true );

	bUpperSizer->Add( m_NoteBook, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 10 );


	bMainSizer->Add( bUpperSizer, 1, wxEXPAND|wxBOTTOM, 5 );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );


	bSizer101->Add( 0, 0, 1, wxEXPAND, 5 );

	m_spiceFieldsButton = new wxButton( this, wxID_ANY, _("Edit Simulation Model..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( m_spiceFieldsButton, 0, wxEXPAND|wxALL, 5 );


	bSizer101->Add( 0, 0, 0, wxEXPAND|wxRIGHT|wxLEFT, 15 );

	m_stdSizerButton = new wxStdDialogButtonSizer();
	m_stdSizerButtonOK = new wxButton( this, wxID_OK );
	m_stdSizerButton->AddButton( m_stdSizerButtonOK );
	m_stdSizerButtonCancel = new wxButton( this, wxID_CANCEL );
	m_stdSizerButton->AddButton( m_stdSizerButtonCancel );
	m_stdSizerButton->Realize();

	bSizer101->Add( m_stdSizerButton, 0, wxEXPAND|wxALL, 5 );


	bMainSizer->Add( bSizer101, 0, wxEXPAND, 5 );


	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );

	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnUpdateUI ) );
	m_NoteBook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnPageChanging ), NULL, this );
	m_grid->Connect( wxEVT_SIZE, wxSizeEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSizeGrid ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnAddField ), NULL, this );
	m_bpMoveUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnMoveUp ), NULL, this );
	m_bpMoveDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnMoveDown ), NULL, this );
	m_bpDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnDeleteField ), NULL, this );
	m_SymbolNameCtrl->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSymbolNameKillFocus ), NULL, this );
	m_SymbolNameCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSymbolNameText ), NULL, this );
	m_KeywordCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnText ), NULL, this );
	m_inheritanceSelectCombo->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCombobox ), NULL, this );
	m_inheritanceSelectCombo->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnText ), NULL, this );
	m_SelNumberOfUnits->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSpinCtrl ), NULL, this );
	m_SelNumberOfUnits->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSpinCtrlText ), NULL, this );
	m_OptionPartsInterchangeable->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_hasAlternateBodyStyles->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_OptionPower->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::onPowerCheckBox ), NULL, this );
	m_ShowPinNumButt->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_ShowPinNameButt->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_PinsNameInsideButt->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_nameOffsetCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnText ), NULL, this );
	m_excludeFromSimCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_excludeFromBomCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_excludeFromBoardCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_FootprintFilterListBox->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnFpFilterDClick ), NULL, this );
	m_FootprintFilterListBox->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnEditFootprintFilter ), NULL, this );
	m_addFilterButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnAddFootprintFilter ), NULL, this );
	m_editFilterButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnEditFootprintFilter ), NULL, this );
	m_spiceFieldsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnEditSpiceModel ), NULL, this );
	m_stdSizerButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCancelButtonClick ), NULL, this );
}

DIALOG_LIB_SYMBOL_PROPERTIES_BASE::~DIALOG_LIB_SYMBOL_PROPERTIES_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnUpdateUI ) );
	m_NoteBook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnPageChanging ), NULL, this );
	m_grid->Disconnect( wxEVT_SIZE, wxSizeEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSizeGrid ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnAddField ), NULL, this );
	m_bpMoveUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnMoveUp ), NULL, this );
	m_bpMoveDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnMoveDown ), NULL, this );
	m_bpDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnDeleteField ), NULL, this );
	m_SymbolNameCtrl->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSymbolNameKillFocus ), NULL, this );
	m_SymbolNameCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSymbolNameText ), NULL, this );
	m_KeywordCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnText ), NULL, this );
	m_inheritanceSelectCombo->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCombobox ), NULL, this );
	m_inheritanceSelectCombo->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnText ), NULL, this );
	m_SelNumberOfUnits->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSpinCtrl ), NULL, this );
	m_SelNumberOfUnits->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnSpinCtrlText ), NULL, this );
	m_OptionPartsInterchangeable->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_hasAlternateBodyStyles->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_OptionPower->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::onPowerCheckBox ), NULL, this );
	m_ShowPinNumButt->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_ShowPinNameButt->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_PinsNameInsideButt->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_nameOffsetCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnText ), NULL, this );
	m_excludeFromSimCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_excludeFromBomCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_excludeFromBoardCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCheckBox ), NULL, this );
	m_FootprintFilterListBox->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnFpFilterDClick ), NULL, this );
	m_FootprintFilterListBox->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnEditFootprintFilter ), NULL, this );
	m_addFilterButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnAddFootprintFilter ), NULL, this );
	m_editFilterButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnEditFootprintFilter ), NULL, this );
	m_spiceFieldsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnEditSpiceModel ), NULL, this );
	m_stdSizerButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_LIB_SYMBOL_PROPERTIES_BASE::OnCancelButtonClick ), NULL, this );

}
