#include "../headers/cal.h"

wxIMPLEMENT_APP(Cal);

bool Cal::OnInit(){
    main = new MainFrame();
    main->Show();

    /*
    #ifdef _WIN32
    const wxIconLocation* loc = new wxIconLocation("E:\\projects\\C++\\QuadraticCalculator\\resources\\fx.ico");
    if (loc->IsOk()){
        main->SetIcon(wxIcon(*loc));
    }
    else {
        std::cout << "Setting Icon Failed" << std::endl;
    }
    #endif // _WIN32
    */

    return true;
}
