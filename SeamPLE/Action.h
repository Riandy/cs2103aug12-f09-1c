#ifndef  ACTION_H
#define ACTION_H
#include <string>
#include <ctime>
#include "task.h"

using namespace std;

//if we want to extend to more fields we have to add in here
#define MAXNOOFPARAMETERS 6 // NAME,DATE,PRIORITY,CATEGORY,
#define INAME       0	//INDEX OF NAME IN THE FLAG ARRAY
#define IDATE       1
#define IPRIORITY   2
#define ICATEGORY   3
#define IDATEEND    4
#define IID         5


class Action
{
private :
    task _task;
    string _command;

public:
    const static string EMPTYCOMMAND;
    Action(void);
    ~Action(void);

    task getTask();
    void setTask(task);

    string getCommand();
    void setCommand(string);

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
    void setDateType(int datetype);

    void determineDate(tm date1,tm date2);
    bool checkDateEmpty(tm date);


};
#endif
