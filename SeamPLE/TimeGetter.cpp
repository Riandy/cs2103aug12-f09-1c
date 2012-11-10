#include "TimeGetter.h"

//@WEIYUAN A0086030R

TimeGetter* TimeGetter:: _timeGetter = NULL;

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

TimeGetter* TimeGetter::getInstance()
{
    if (!singleInstanceExist())
    {
        _timeGetter = new TimeGetter();
    }

    return _timeGetter;
}

void TimeGetter:: endInstance()
{
    if (singleInstanceExist())
    {
        delete _timeGetter;
        _timeGetter = NULL;
    }
}

void TimeGetter::getStringDateAndTime()
{
    QDateTime currDateAndTime = QDateTime::currentDateTime();
    QString date = currDateAndTime.toString(SET_DATE_FORMAT);
    date = SET_DATE_FONT_FORMAT_AND_TAG + date + SET_END_FONT_TAG;

    bool currSecondIsEvenNumber = getTime(currDateAndTime).second() % 2 == 0;

    QString time;
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

