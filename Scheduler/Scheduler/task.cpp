#include "task.h"


task::task(void)
{
    _description="";
    _startDate.tm_year = 0 ;
    _startDate.tm_mon	= 0;
    _startDate.tm_mday = 0;
    _endDate.tm_year = 0 ;
    _endDate.tm_mon	= 0;
    _endDate.tm_mday = 0;
    _priority = "LOW";
    _category = "";
    _id=0;
}


task::~task(void)
{
}


string task::getEventName()
{
    return _description;
}
void task::setEventName(string name)
{
    _description = name;
}

tm task::getStartDate()
{
    return _startDate;
}
void task::setStartDate(tm newDate)
{
    _startDate = newDate;

}

tm task::getEndDate()
{
    return _endDate;
}
void task::setEndDate(tm newDate)
{
    _endDate = newDate;

}

string task::getPriority()
{
    return _priority;
}
void task::setPriority(string newPriority)
{
    _priority = newPriority;
}

string task::getCategory()
{
    return _category;
}
void task::setCategory(string newCategory)
{
    _category = newCategory;
}

int task::getID()
{
    return _id;
}
void task::setID(int newID)
{
    _id = newID;
}
