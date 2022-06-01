#include "../headers/mainframe.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(5, MainFrame::run)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Quadratic Calculator", wxDefaultPosition, wxSize(650, 500)) {
    #ifdef _WIN32
    this->SetBackgroundColour(*wxWHITE);
    #endif // _WIN32
    a_in = new wxTextCtrl(this, 1, "", wxPoint(50, col1), wxSize(100, 25));
    a_in->SetFocus();
    a_lbl = new wxStaticText(this, wxID_ANY, L"x\u00b2", wxPoint(175, col1), wxSize(25, 25));
    b_in = new wxTextCtrl(this, 2, "", wxPoint(225, col1), wxSize(100, 25));
    b_lbl = new wxStaticText(this, wxID_ANY, "x", wxPoint(350, col1), wxSize(25, 25));
    c_in = new wxTextCtrl(this, 3, "", wxPoint(400, col1), wxSize(100, 25));
    c_lbl = new wxStaticText(this, wxID_ANY, "(constant)", wxPoint(525, col1), wxSize(100, 25));

    submit = new wxButton(this, 5, "Examine", wxPoint(275, 125), wxSize(100, 50));
    submit->SetBackgroundColour(wxColor("#BFFF00"));
    submit->SetForegroundColour(*wxBLACK);

    out = new wxStaticText(this, 10, intro, wxPoint(150, 225), wxSize(350, 200));
}

void MainFrame::run(wxCommandEvent &evt) {
    double a, b, c;
    if (!(a_in->GetValue()).ToDouble(&a) || !(b_in->GetValue()).ToDouble(&b) || !(c_in->GetValue().ToDouble(&c)) || a_in->IsEmpty() || b_in->IsEmpty() || c_in->IsEmpty()) {
        out->SetLabel("\nPlease try again" + intro);
    }
    else {
        cal = new QuadCal(a, b, c);
        out->SetLabel(cal->getEquation(0) + L"\n" + cal->Run(0));
        delete(cal);
        cal = nullptr;
    }
}

/*
std::wstring convert( const std::string& as ){
    wchar_t* buf = new wchar_t[as.size() * 2 + 2];
    swprintf( buf, L"%S", as.c_str() );
    std::wstring rval = buf;
    delete[] buf;
    return rval;
}
*/
