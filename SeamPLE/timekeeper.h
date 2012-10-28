#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <QThread>
#include <QDebug>
#include <QWaitCondition>
#include <QSystemTrayIcon>
#include <QMutex>
#include <iostream>
#include <QDateTime>
#include <ctime>
#include "scheduler.h"




using namespace std;
class Timekeeper:public QThread
{
    Q_OBJECT



public:
    Timekeeper( );
    void init(QSystemTrayIcon* _popUp);
    static void sleep(unsigned long msecs);
    void displayToTrayIcon(string message);

protected:

    void run();
    void showtime(string input);

private:
    scheduler *_scheduler;
    QSystemTrayIcon* popUp;



};

#endif // TIMEKEEPER_H
