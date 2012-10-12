#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "calender.h"
#include <sstream>
#include "Action.h"


// Ensure that this error is synchronous with the errors sent from Intellisense.
static string ERROR_NOT_FOUND = "Error - The item does not exist.";
static string ERROR_INTELLISENSE_CHECK = "Error - The system failed to process your request. Please try again";

class Seample;


class scheduler
{
private:

    Seample *app;

    vector<string> _result;
    vector<task> taskVector;
    calender eventCalender;
    void convertToString(vector<task> taskVector);
    void generalError();
    string convertToDate(tm _date);
public:
    scheduler();
    ~scheduler();
    void init(Seample *_app);
    vector<string> executeCommand(Action newaction);

    //pass in action
};


#endif
