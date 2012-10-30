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
        _popUp->showMessage("10 Minutes later",message.c_str(),QSystemTrayIcon::Information);
    }
}

void Timekeeper::tenMinutesLater(int &Hour, int &Min, int _hour, int _min)
{
    Hour=_hour;
    Min=_min;
    Min+=10;
    if(Min>=60)
    {
        Hour+=1;
        Min-=60;
    }
}

void Timekeeper::run()
{
    int lastMin;
    int Hour,Min;

    while(true)
    {
        time_t t = time(0);
        struct tm * now = localtime( & t );
        if(lastMin!=now->tm_min)
        {
        if(_scheduler->instanceFlag)
        {
           tenMinutesLater(Hour,Min,now->tm_hour,now->tm_min);
           displayToTrayIcon(_scheduler->getEventBasedOnTime(Hour,Min));
        }
        }
        lastMin = now->tm_min;

        sleep(6000);
    }
}


void Timekeeper::sleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}
