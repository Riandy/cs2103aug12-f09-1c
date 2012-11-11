#ifndef TASK_H
#define TASK_H
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include "ndebug.h"
using namespace std;

//@CHAM WEN BIN U094659H
class task
{
private:
    string _description;
    tm _startDate;
    tm _endDate;
    string _priority;
    string _category;
    int dateType;
    int _id;
    string convertInt(int number);


public:

    const static int DATENORMAL;
    const static int DATEWEEKLY;
    const static int DATEFORTNIGHTLY;
    const static int DATEMONTHLY;
    const static string DEFAULTPRIORITY;
    const static string DEFAULTCATEGORY;
    const static string DEFAULTEVENT;
    const static int DEFAULTID;
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

    int getDateType();
    void setDateType(int );

    string convertToDate(tm);

    vector<string> toString();
    static tm getEmptyDateTm();
};
#endif
