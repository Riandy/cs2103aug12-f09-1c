#include "timekeeper.h"
#include <QDebug>

Timekeeper::Timekeeper()
{
    _scheduler=scheduler::getInstance();
    _popUp = _popUp->getInstance();
    _oneMinute = NULL;
    setUpConfigure();
}

Timekeeper::~Timekeeper()
{
    if (_oneMinute != NULL)
    {
        delete _oneMinute;
    }

    if (_timerConfigure!=NULL)
    {
        delete _timerConfigure;
    }

    _popUp->endInstance();
}

void Timekeeper::reachOneMinute()
{
    emit oneMinuteTrigger();
}

void Timekeeper:: getEventForPopUp()
{
    time_t t = time(0);
    struct tm* now = localtime( & t );
    string result = "";
    int hour = now->tm_hour;
    int min = now->tm_min;
    int flag = -1;

    //Check if there is any events that ends or start now
    result = _scheduler->getEventNameForEnd(hour,min);
    if (isAppropriate(result))
    {
        flag = 0;
    }
    else
    {
        result = _scheduler->getEventNameForStart(hour,min);
        if (isAppropriate(result))
        {
            flag = 1;
        }

        //if unable to get any events that start and end now, get one
        //that start 10 mins later.
        else
        {
            countMinutesLater(hour, min, 10);
            result = _scheduler->getEventNameForEnd(hour,min);
            if (isAppropriate(result))
            {
                flag = 2;
            }
            else
            {
                result = _scheduler->getEventNameForStart(hour,min);
                if (isAppropriate(result))
                {
                    flag = 3;
                }


                //if unable to get any events that start and end now, get one
                //that start 30 mins later.
                else
                {
                    countMinutesLater(hour, min,30);
                    result = _scheduler->getEventNameForEnd(hour,min);
                    if (isAppropriate(result))
                    {
                        flag = 4;
                    }
                    else
                    {
                        result = _scheduler->getEventNameForStart(hour,min);
                        if (isAppropriate(result))
                        {
                            flag = 5;
                        }
                    }
                }
            }
        }
    }

    evaluateResults(result, flag);
}

void Timekeeper::configureDone()
{
    disconnect(_timerConfigure,SIGNAL(timeout()),this,SLOT(configureDone()));
    delete _timerConfigure;
    _timerConfigure = NULL;
    getEventForPopUp();
    setOneMinuteTimer();
}

void Timekeeper::countMinutesLater(int &hour, int &min, int count)
{
    min+=count;
    if(min>=60)
    {
        hour+=1;
        min-=60;
    }
}

void Timekeeper::setOneMinuteTimer()
{
    _oneMinute = new QTimer;
    _oneMinute->setSingleShot(false);
    connect(_oneMinute,SIGNAL(timeout()),this,SLOT(reachOneMinute()));
    connect (_oneMinute, SIGNAL(timeout()), this, SLOT(getEventForPopUp()));
    _oneMinute->start(60000);
}

void Timekeeper::displayToTrayIcon(string message)
{
    if (_popUp != NULL && isAppropriate(message))
    {
        _popUp->showMessage("SeamPLE",QString::fromStdString(message),QSystemTrayIcon::Information);
    }
}

bool Timekeeper::isAppropriate(string result)
{
    return (result != "");
}

void Timekeeper::evaluateResults (string result, int flag)
{
    switch (flag)
    {
        case 0:
            result = "\""+result+"\""+" has expired!";
            break;

        case 1:
            result = "\""+result+"\""+" has started!";
            break;

        case 2:
            result = "\""+result+"\""+" will expire in 10 minutes.";
            break;

        case 3:
            result = "\""+result+"\""+" will start in 10 minutes.";
            break;

        case 4:
            result = "\""+result+"\""+" will expire in 30 minutes.";
            break;

        case 5:
            result = "\""+result+"\""+" will start in 30 minutes.";
            break;

        default:
            break;
    }

    displayToTrayIcon(result);
}

void Timekeeper::setUpConfigure()
{
    _timerConfigure = new QTimer;
    _timerConfigure->setSingleShot(true);
    connect(_timerConfigure,SIGNAL(timeout()),this,SLOT(configureDone()));
    time_t t = time(0);
    struct tm* now = localtime( & t );
    _timerConfigure->start((61 - now->tm_sec)*1000);
}
