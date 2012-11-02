#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "calender.h"
#include <ctime>
#include <sstream>
#include <algorithm>
#include "ndebug.h"
#include "Action.h"
#include "ErrorLogger.h"



class scheduler
{
private:
    ErrorLogger* _faulty;
    static scheduler *_scheduler;
    scheduler();
    vector<string> _result;
    vector<task> taskVector;
    calender eventCalender;
    void updateGUI();
    void updateResultFound(int size);
    string convertToDate(tm _date);
    task processAction(Action newAction);
    void updateTask(task &_task);
    void updateWeeklyTask(tm &_date);
    void updateFornightlyTask(tm &_date);
    void updateMonthlyTask(tm &_date);
    int daysMonth(int year, int month);
    void printMessage(string _messageType);
    void partialUpdateGUI(vector<task> taskVector);


public:
    static bool instanceFlag;
    static scheduler* getInstance();
    ~scheduler();
    vector<string> executeCommand(Action newaction);
    string getEventBasedOnTime(int hour, int min);

};


#endif
