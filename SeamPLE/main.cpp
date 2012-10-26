#include <QtGui/QApplication>
#include "GuiControl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiControl* view = view->getInstance();
    view->setStandardViewFlag(false);
    view->showGui();
    int retValue = a.exec();
    view->endInstance();

    return retValue;
}
