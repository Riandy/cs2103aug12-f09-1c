#ifndef GUITYPE_H
#define GUITYPE_H

#include "mainwindow.h"
#include "standardview.h"

class GuiType
{
public:
    GuiType(bool flag);

    void showGui();

    void setStandardView (bool flag);

    bool isStandardView();

private:
    bool standardViewFlag;
    MainWindow seample;
    StandardView standard;
};
#endif // GUITYPE_H
