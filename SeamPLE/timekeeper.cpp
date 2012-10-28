#include "timekeeper.h"

Timekeeper::Timekeeper()
{
    _scheduler=scheduler::getInstance();

}

void Timekeeper::init(QSystemTrayIcon *_popUp)
{
      popUp=_popUp;
}

void Timekeeper::displayToTrayIcon(string message)
{
    if(message.empty())
    {return;}

    if (popUp != NULL)
    {
        popUp->showMessage("SeamPLE",message.c_str(),QSystemTrayIcon::Information, 100000);
    }
}

void Timekeeper::run()
{
    char buffer [80];

    while(true)
    {

        time_t t = time(0);
        struct tm * now = localtime( & t );
        if(_scheduler->instanceFlag)
        {
           displayToTrayIcon(_scheduler->getEventBasedOnTime(now->tm_hour,now->tm_min));

        }

        sleep(60000);

    }
}


void Timekeeper::sleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}
