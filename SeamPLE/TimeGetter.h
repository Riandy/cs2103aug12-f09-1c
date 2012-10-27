#ifndef TIMEGETTER_H
#define TIMEGETTER_H

#include <QObject>
#include <QDateTime>

class TimeGetter : public QObject
{
    Q_OBJECT

private:
    const static QString SET_DATE_FORMAT;
    const static QString SET_TIME_FORMAT_TICK;
    const static QString SET_TIME_FORMAT_TICKLESS;
    const static QString SET_START_NEXT_SENTENCE;
    const static QString SET_END_NEXT_SENTENCE;

private:
    QTime getTime(QDateTime currDateAndTime);

public slots:
    void getStringDateAndTime ();

signals:
    void relayStringDateAndTime (QString dateAndTime);


};

#endif // TIMEGETTER_H
