#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include "../../Quadcal/headers/QuadCal.h"

class QuadCal;

class MainFrame : public wxFrame{
    public:
    MainFrame();

    private:
    wxStaticText* a_lbl = nullptr;
    wxStaticText* b_lbl = nullptr;
    wxStaticText* c_lbl = nullptr;
    wxTextCtrl* a_in = nullptr;
    wxTextCtrl* b_in = nullptr;
    wxTextCtrl* c_in = nullptr;
    wxButton* submit = nullptr;
    wxStaticText* out = nullptr;
    QuadCal* cal = nullptr;
    wxString intro = "\n\n\n\nPlease complete the equation with integers or decimal values\nand click \'Examine\'";
    int col1 = 50;
    void run(wxCommandEvent &evt);
//    std::wstring convert(const std::string &as);

    wxDECLARE_EVENT_TABLE();
};

#endif