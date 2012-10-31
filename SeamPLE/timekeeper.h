#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <QThread>
#include <ctime>
#include "scheduler.h"
#include "NotifyView.h"

using namespace std;

class Timekeeper:public QThread
{
    Q_OBJECT

public:
    Timekeeper();
    ~Timekeeper();
    //void init(QSystemTrayIcon* _popUp);
    static void sleep(unsigned long msecs);
    void displayToTrayIcon(string message);

protected:
    void run();
    void showtime(string input);

private:
    scheduler * _scheduler;
    NotifyView* _popUp;



};

#endif // TIMEKEEPER_H
