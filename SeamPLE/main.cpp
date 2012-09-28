#include <QtGui/QApplication>
#include "GuiType.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiType view(true);
    view.showGui();

    return a.exec();
}
