#ifndef CAL_H
#define CAL_H

#include "mainframe.h"

class MainFrame;

class Cal : public wxApp{
    MainFrame* main = nullptr;

    public:
    virtual bool OnInit();
};

#endif