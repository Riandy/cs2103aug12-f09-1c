#include "TimeGetter.h"

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

QTime TimeGetter:: getTime(QDateTime currDateAndTime)
{
    return currDateAndTime.time();
}

void TimeGetter::getStringDateAndTime()
{
    QDateTime currDateAndTime = QDateTime::currentDateTime();
    QString dateAndTime = currDateAndTime.toString("dddd dd-MM-yy");

    bool currSecondIsEvenNumber = getTime(currDateAndTime).second() % 2 == 0;
    dateAndTime += SET_START_NEXT_SENTENCE;

    if (currSecondIsEvenNumber)
    {
        dateAndTime += currDateAndTime.toString(SET_TIME_FORMAT_TICK);
    }
    else
    {
        dateAndTime += currDateAndTime.toString(SET_TIME_FORMAT_TICKLESS);
    }

    dateAndTime += SET_END_NEXT_SENTENCE;

    emit relayStringDateAndTime(dateAndTime);
}


