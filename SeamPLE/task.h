#ifndef TASK_H
#define TASK_H
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


class task
{
private:
    string _description;
    tm _startDate;
    tm _endDate;
    string _priority;
    string _category;
    int _id;


public:
    task();
    ~task();

    string getEventName();
    void setEventName(string);


    tm getStartDate();
    void setStartDate( tm);
    void setStartDateWithoutTime(tm);

    tm getEndDate();
    void setEndDate( tm);

    string getPriority();
    void setPriority(string);

    string getCategory();
    void setCategory(string);

    int getID();
    void setID(int);

    string convertToDate(tm);

    vector<string> toString();

};
#endif
