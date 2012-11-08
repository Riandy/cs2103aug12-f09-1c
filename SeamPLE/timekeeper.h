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
