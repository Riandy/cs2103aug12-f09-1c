#include "timekeeper.h"

const string Timekeeper:: MESSAGE_TITLE =
        "SeamPLE";
const string Timekeeper:: MESSAGE_CORNER_BRACE =
        "\"";
const string Timekeeper:: MESSAGE_EXPIRED =
        " has expired!";
const string Timekeeper:: MESSAGE_STARTED =
        " has started!";
const string Timekeeper:: MESSAGE_END_TEN_MINS =
        " will expire in 10 minutes.";
const string Timekeeper:: MESSAGE_END_THIRTY_MINS =
        " will expire in 30 minutes.";
const string Timekeeper:: MESSAGE_START_TEN_MINS =
        " will start in 10 minutes.";
const string Timekeeper:: MESSAGE_START_THIRTY_MINS =
        " will start in 30 minutes.";

//@author: u094659h
//singleton pattern constructor
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

//@author: u094659h
//retrieve task upon reaching the star time
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
                    countMinutesLater(hour, min, 20);
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

//Following function configure one minute timer to start at one minut mark
void Timekeeper::configureDone()
{
    disconnect(_timerConfigure,SIGNAL(timeout()),this,SLOT(configureDone()));
    delete _timerConfigure;
    _timerConfigure = NULL;
    getEventForPopUp();
    setOneMinuteTimer();
}

//This function does the adding of minutes and hour
void Timekeeper::countMinutesLater(int &hour, int &min, int count)
{
    min+=count;
    if(min>=60)
    {
        hour+=1;
        min-=60;
    }
}

//Setting the one minute timer configuration to be triggered once a minute
void Timekeeper::setOneMinuteTimer()
{
    _oneMinute = new QTimer;
    _oneMinute->setSingleShot(false);
    connect(_oneMinute,SIGNAL(timeout()),this,SLOT(reachOneMinute()));
    connect (_oneMinute, SIGNAL(timeout()), this, SLOT(getEventForPopUp()));
    _oneMinute->start(60000);
}

//Function to display a message to user via the notification balloon
void Timekeeper::displayToTrayIcon(string message)
{
    if (_popUp != NULL && isAppropriate(message))
    {
        _popUp->showMessage(QString::fromStdString(MESSAGE_TITLE),
                            QString::fromStdString(message),
                            QSystemTrayIcon::Information);
    }
}

//Check if a string sent in is empty or not
bool Timekeeper::isAppropriate(string result)
{
    return (result != "");
}

//Function evaluates the result of based on a flag sent in to show
//the timing towards where an event is expiring or starting
void Timekeeper::evaluateResults (string result, int flag)
{
    switch (flag)
    {
        case 0:
            result = MESSAGE_CORNER_BRACE+result+MESSAGE_CORNER_BRACE+
                    MESSAGE_EXPIRED;
            break;

        case 1:
            result = MESSAGE_CORNER_BRACE+result+MESSAGE_CORNER_BRACE+
                    MESSAGE_STARTED;
            break;

        case 2:
            result = MESSAGE_CORNER_BRACE+result+MESSAGE_CORNER_BRACE+
                    MESSAGE_END_TEN_MINS;
            break;

        case 3:
            result = MESSAGE_CORNER_BRACE+result+MESSAGE_CORNER_BRACE+
                    MESSAGE_START_TEN_MINS;
            break;

        case 4:
            result = MESSAGE_CORNER_BRACE+result+MESSAGE_CORNER_BRACE+
                    MESSAGE_END_THIRTY_MINS;
            break;

        case 5:
            result = MESSAGE_CORNER_BRACE+result+MESSAGE_CORNER_BRACE+
                    MESSAGE_START_THIRTY_MINS;
            break;

        default:
            break;
    }

    displayToTrayIcon(result);
}

//Function is to configure the configurating timer at the start of the program
void Timekeeper::setUpConfigure()
{
    _timerConfigure = new QTimer;
    _timerConfigure->setSingleShot(true);
    connect(_timerConfigure,SIGNAL(timeout()),this,SLOT(configureDone()));
    time_t t = time(0);
    struct tm* now = localtime( & t );
    _timerConfigure->start((61 - now->tm_sec)*1000);
}
