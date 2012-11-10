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
    bool isTimeZero(tm time);

    void Add(task thisTask);
    void Delete(task thisTask);
    void Edit(task thisTask);
    void EditEnter(task thisTask);
    void Find(task thisTask);
    void Display();
    void Undo();
    void Redo();
    void Today();
    void Mark(task thisTask);
    void Todo();
    void Exit();

public:
    static bool instanceFlag;
    static scheduler* getInstance();
    ~scheduler();
    vector<string> executeCommand(Action newaction);
    string getEventBasedOnTime(int hour, int min);
    string getEventNameForEnd(int hour, int min);
    string getEventNameForStart(int hour, int min);


//--TodayEvents generating functions-------------
public:
    vector<string> getTodayEvents();

private:
    void getAllRequiredParameters(vector<task>& firstPriority, bool& firstPriorityFound,
                                  int& highPriorityTasks, int& size,
                                  int& threeCountFlag, vector<task>& threeTasks);
    vector<string> makeTodayStringResults(vector<task> firstPriority, bool firstPriorityFound,
                                          int highPriorityTasks, int size,
                                          int threeCountFlag, vector<task> threeTasks);
    vector<string> combineStringVectors(
            vector<string> first, vector<string> second);
    string getStringFromInt(int subject);
//------------------------------------------------

};


#endif
