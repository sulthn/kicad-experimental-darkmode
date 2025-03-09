///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_print_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_PRINT_BASE::DIALOG_PRINT_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bleftSizer;
	bleftSizer = new wxBoxSizer( wxVERTICAL );

	m_checkReference = new wxCheckBox( this, wxID_ANY, _("Print drawing sheet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkReference->SetValue(true);
	m_checkReference->SetToolTip( _("Print (or not) the Frame references.") );

	bleftSizer->Add( m_checkReference, 0, wxTOP|wxBOTTOM, 10 );

	wxBoxSizer* bSizerOttputMode;
	bSizerOttputMode = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Output mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizerOttputMode->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_colorPrintChoices[] = { _("Color"), _("Black and White") };
	int m_colorPrintNChoices = sizeof( m_colorPrintChoices ) / sizeof( wxString );
	m_colorPrint = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_colorPrintNChoices, m_colorPrintChoices, 0 );
	m_colorPrint->SetSelection( 0 );
	bSizerOttputMode->Add( m_colorPrint, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );


	bleftSizer->Add( bSizerOttputMode, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_checkBackgroundColor = new wxCheckBox( this, wxID_ANY, _("Print background color"), wxDefaultPosition, wxDefaultSize, 0 );
	bleftSizer->Add( m_checkBackgroundColor, 0, wxLEFT, 20 );


	bleftSizer->Add( 0, 10, 0, wxEXPAND, 5 );

	m_checkUseColorTheme = new wxCheckBox( this, wxID_ANY, _("Use a different color theme for printing:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkUseColorTheme->SetValue(true);
	bleftSizer->Add( m_checkUseColorTheme, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	wxArrayString m_colorThemeChoices;
	m_colorTheme = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_colorThemeChoices, 0 );
	m_colorTheme->SetSelection( 0 );
	m_colorTheme->Enable( false );

	bSizer4->Add( m_colorTheme, 1, wxEXPAND|wxLEFT, 20 );


	bleftSizer->Add( bSizer4, 1, wxEXPAND, 5 );


	bMainSizer->Add( bleftSizer, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 10 );

	wxBoxSizer* bbuttonsSizer;
	bbuttonsSizer = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPageSetup = new wxButton( this, wxID_ANY, _("Page Setup..."), wxDefaultPosition, wxDefaultSize, 0 );
	bbuttonsSizer->Add( m_buttonPageSetup, 0, wxALIGN_CENTER_VERTICAL, 5 );


	bbuttonsSizer->Add( 20, 0, 1, wxEXPAND, 5 );

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Apply = new wxButton( this, wxID_APPLY );
	m_sdbSizer1->AddButton( m_sdbSizer1Apply );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();

	bbuttonsSizer->Add( m_sdbSizer1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bMainSizer->Add( bbuttonsSizer, 0, wxEXPAND|wxLEFT, 10 );


	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DIALOG_PRINT_BASE::OnCloseWindow ) );
	m_colorPrint->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnOutputChoice ), NULL, this );
	m_checkUseColorTheme->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnUseColorThemeChecked ), NULL, this );
	m_buttonPageSetup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnPageSetup ), NULL, this );
	m_sdbSizer1Apply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnPrintPreview ), NULL, this );
}

DIALOG_PRINT_BASE::~DIALOG_PRINT_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DIALOG_PRINT_BASE::OnCloseWindow ) );
	m_colorPrint->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnOutputChoice ), NULL, this );
	m_checkUseColorTheme->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnUseColorThemeChecked ), NULL, this );
	m_buttonPageSetup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnPageSetup ), NULL, this );
	m_sdbSizer1Apply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_PRINT_BASE::OnPrintPreview ), NULL, this );

}
