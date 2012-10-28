#ifndef TIMEGETTER_H
#define TIMEGETTER_H

#include <QObject>
#include <QDateTime>

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
    TimeGetter();

    ~TimeGetter();

    QTime getTime(QDateTime currDateAndTime);

    bool singleInstanceExist();

public:
    TimeGetter* getInstance();

    void endInstance();

public slots:
    void getStringDateAndTime ();

signals:
    void relayStringDateAndTime (QString dateAndTime);


};

#endif // TIMEGETTER_H
