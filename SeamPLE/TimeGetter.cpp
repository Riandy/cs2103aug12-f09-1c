#include "TimeGetter.h"

//@LIU WEIYUAN A0086030R

TimeGetter* TimeGetter:: _timeGetter = NULL;

//Following strings contain the format for items that will be displayed
//to the users. For example, SET_TIME_FORMAT_TICK and TICKLESS are to
//show the ticking motion of a digital clock
const QString TimeGetter:: SET_DATE_FORMAT =
        "dddd dd-MM-yy";
const QString TimeGetter:: SET_TIME_FORMAT_TICK =
        "h mm ap";
const QString TimeGetter:: SET_TIME_FORMAT_TICKLESS =
        "h:mm ap";
const QString TimeGetter:: SET_START_NEXT_SENTENCE =
        "<br>";
const QString TimeGetter:: SET_END_NEXT_SENTENCE =
        "</br>";

const QString TimeGetter:: SET_DATE_FONT_FORMAT_AND_TAG =
        "<font size=2 face=\"Arial\" color = #FCF40D>";
const QString TimeGetter:: SET_END_FONT_TAG =
        "</font>";
const QString TimeGetter:: SET_TIME_FONT_FORMAT_AND_TAG =
        "<font size=3 face=\"Cambria\" color = #FCF40D>";

QTime TimeGetter:: getTime(QDateTime currDateAndTime)
{
    return currDateAndTime.time();
}

//Function returns a boolean value on whether the singleton for this
//class exists or not.
bool TimeGetter::singleInstanceExist()
{
    bool result;

    if (_timeGetter == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

//This function returns the address of the singleton existence of this class
TimeGetter* TimeGetter::getInstance()
{
    if (!singleInstanceExist())
    {
        _timeGetter = new TimeGetter();
    }

    return _timeGetter;
}

//This function deletes the singleton existence of this class
void TimeGetter:: endInstance()
{
    if (singleInstanceExist())
    {
        delete _timeGetter;
        _timeGetter = NULL;
    }
}

//Function emits a signal of the string date and time every second
//to the slot functions connected to it
void TimeGetter::getStringDateAndTime()
{
    QDateTime currDateAndTime = QDateTime::currentDateTime();
    QString date = currDateAndTime.toString(SET_DATE_FORMAT);
    date = SET_DATE_FONT_FORMAT_AND_TAG + date + SET_END_FONT_TAG;

    bool currSecondIsEvenNumber = getTime(currDateAndTime).second() % 2 == 0;

    QString time;

    //Following if-else conditions are to show the ticking motion of a clock
    if (currSecondIsEvenNumber)
    {
        time = currDateAndTime.toString(SET_TIME_FORMAT_TICK);
    }
    else
    {
        time = currDateAndTime.toString(SET_TIME_FORMAT_TICKLESS);
    }

    time = SET_TIME_FONT_FORMAT_AND_TAG + time + SET_END_FONT_TAG;

    emit relayStringDateAndTime(date+SET_START_NEXT_SENTENCE+time+SET_END_NEXT_SENTENCE);
}

