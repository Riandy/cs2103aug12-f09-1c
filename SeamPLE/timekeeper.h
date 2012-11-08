#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <QThread>
#include <QTimer>
#include <ctime>
#include "scheduler.h"
#include "NotifyView.h"

using namespace std;

class Timekeeper: public QObject
{
    Q_OBJECT

private:
    const static string MESSAGE_TITLE;
    const static string MESSAGE_CORNER_BRACE;
    const static string MESSAGE_EXPIRED;
    const static string MESSAGE_STARTED;
    const static string MESSAGE_END_TEN_MINS;
    const static string MESSAGE_END_THIRTY_MINS;
    const static string MESSAGE_START_TEN_MINS;
    const static string MESSAGE_START_THIRTY_MINS;


public:
    Timekeeper();
    ~Timekeeper();

private slots:
    void reachOneMinute();
    void getEventForPopUp();
    void configureDone();

signals:
    void oneMinuteTrigger();

private:
    void countMinutesLater(int &hour, int &min, int count);
    void setOneMinuteTimer();
    void setPopUpTimer();
    void displayToTrayIcon(string message);
    bool isAppropriate (string result);
    void evaluateResults (string result, int flag);
    void setUpConfigure();

    scheduler * _scheduler;
    NotifyView* _popUp;
    QTimer* _oneMinute;
    QTimer* _timerConfigure;

};

#endif // TIMEKEEPER_H
