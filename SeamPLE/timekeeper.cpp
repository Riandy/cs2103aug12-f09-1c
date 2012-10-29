#include "timekeeper.h"

Timekeeper::Timekeeper()
{
    _scheduler=scheduler::getInstance();
    _popUp = _popUp->getInstance();

}

Timekeeper::~Timekeeper()
{
    _popUp->endInstance();
}

void Timekeeper::displayToTrayIcon(string message)
{
    bool hasMessage = !(message.empty());

    if (_popUp != NULL && hasMessage)
    {
        _popUp->showMessage("SeamPLE",message.c_str(),QSystemTrayIcon::Information);
    }
}

void Timekeeper::run()
{
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
