#include <QtGui/QApplication>
#include "GuiControl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiControl view;
    view.setStandardView(false);
    view.showGui();

    return a.exec();
}
