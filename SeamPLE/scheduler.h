#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "calender.h"
#include <ctime>
#include <sstream>
#include "Action.h"


// Ensure that this error is synchronous with the errors sent from Intellisense.
static string ERROR_NOT_FOUND = "Error - The item does not exist.";
static string ERROR_INTELLISENSE_CHECK = "Error - The system failed to process your request. Please try again";
static string ADD_SUCCESS = "Your event was added successfully.";
static string ADD_FAILURE = "Your event was not added successfully";
static string DELETE_SUCCESS = "Your event was deleted successfully";
static string EDIT_SUCCESS = "Your event was edited successfully";
static string UNDO_SUCCESS = "Undo operation was successful";
static string UNDO_FAILURE = "There is nothing to undo";
static string REDO_SUCCESS = "Redo operation was successful";
static string REDO_FAILURE = "There is nothing to redo";



class scheduler
{
private:

    static scheduler *_scheduler;
    scheduler();
    vector<string> _result;
    vector<task> taskVector;
    calender eventCalender;
    void updateGUI(vector<task> taskVector);
    void updateResultFound(int size);
    void generalError();
    string convertToDate(tm _date);
    task processAction(Action newAction);
    void updateTask(task &_task);
    void updateWeeklyTask(tm &_date);
    void updateFornightlyTask(tm &_date);
    void updateMonthlyTask(tm &_date);
    int daysMonth(int year, int month);


public:
    static bool instanceFlag;
    static scheduler* getInstance();
    ~scheduler();
    vector<string> executeCommand(Action newaction);
    string getEventBasedOnTime(int hour, int min);

};


#endif
