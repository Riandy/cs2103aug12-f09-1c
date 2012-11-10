#include <QtGui/QApplication>
#include "GuiControl.h"
#include "UnitTest.h"

#include "timekeeper.h"

int main(int argc, char *argv[])
{
//    if(0)     // change to true to enable unit testing, false otherwise
//    {
//        QApplication app1(argc, argv);
//        int retval(0);

//        retval += QTest::qExec(&UnitTest(), argc, argv);
//        // Add more test like above here

//        return (retval ? 1 : 0);
//    }
//    else
//    {
        QApplication a(argc, argv);
        GuiControl* view = view->getInstance();
        view->setStandardViewFlag(false);
        view->showGui();
        int retValue = a.exec();
        view->endInstance();

        return retValue;
   // }


}


