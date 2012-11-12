#ifndef TIMEGETTER_H
#define TIMEGETTER_H

#include <QObject>
#include <QDateTime>

//@LIU WEIYUAN: A0086030R

//This class is for getting the time and date to be implemented
//in objects that is displayed in the UI as a clock. A ui object
//can contain an instance of this class and call its functions
//to get the time
class TimeGetter : public QObject
{
    Q_OBJECT

private:
    static TimeGetter* _timeGetter;

    const static QString SET_DATE_FORMAT;
    const static QString SET_TIME_FORMAT_TICK;
    const static QString SET_TIME_FORMAT_TICKLESS;
    const static QString SET_START_NEXT_SENTENCE;
    const static QString SET_END_NEXT_SENTENCE;
    const static QString SET_DATE_FONT_FORMAT_AND_TAG;
    const static QString SET_END_FONT_TAG;
    const static QString SET_TIME_FONT_FORMAT_AND_TAG;

private:
    QTime getTime(QDateTime currDateAndTime);
    bool singleInstanceExist();
    QString setTickingMotionFrom(QDateTime currDateAndTime);

public:
    TimeGetter* getInstance();
    void endInstance();

public slots:
    void getStringDateAndTime ();

signals:
    void relayStringDateAndTime (QString dateAndTime);


};

#endif // TIMEGETTER_H
