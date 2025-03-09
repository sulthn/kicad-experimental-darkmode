///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class STD_BITMAP_BUTTON;

#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/statbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_GENDRILL_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_GENDRILL_BASE : public DIALOG_SHIM
{
	private:

	protected:
		wxBoxSizer* bMainSizer;
		wxStaticText* staticTextOutputDir;
		wxTextCtrl* m_outputDirectoryName;
		STD_BITMAP_BUTTON* m_browseButton;
		wxStaticText* m_formatLabel;
		wxStaticLine* m_staticline1;
		wxRadioButton* m_rbExcellon;
		wxCheckBox* m_Check_Mirror;
		wxCheckBox* m_Check_Minimal;
		wxCheckBox* m_Check_Merge_PTH_NPTH;
		wxCheckBox* m_altDrillMode;
		wxRadioButton* m_rbGerberX2;
		wxCheckBox* m_cbGenerateMap;
		wxChoice* m_choiceDrillMap;
		wxStaticText* m_optionsLabel;
		wxStaticLine* m_staticline2;
		wxStaticText* m_originLabel;
		wxChoice* m_origin;
		wxStaticText* m_unitsLabel;
		wxChoice* m_units;
		wxStaticText* m_zerosLabel;
		wxChoice* m_zeros;
		wxStaticText* m_precisionLabel;
		wxStaticText* m_staticTextPrecision;
		wxStaticBoxSizer* bMsgSizer;
		wxTextCtrl* m_messagesBox;
		wxBoxSizer* m_buttonsSizer;
		wxButton* m_buttonReport;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;

		// Virtual event handlers, override them in your derived class
		virtual void onCloseDlg( wxCloseEvent& event ) { event.Skip(); }
		virtual void onOutputDirectoryBrowseClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFileFormatSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSelDrillUnitsSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSelZerosFmtSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGenReportFile( wxCommandEvent& event ) { event.Skip(); }


	public:

		DIALOG_GENDRILL_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Generate Drill Files"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~DIALOG_GENDRILL_BASE();

};

