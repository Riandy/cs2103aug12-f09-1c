#include "task.h"


task::task(void)
{
    _description="";
    _startDate.tm_year = 0 ;
    _startDate.tm_mon	= 0;
    _startDate.tm_mday = 0;
    _startDate.tm_min =0;
    _startDate.tm_hour=0;
    _endDate.tm_year = 0 ;
    _endDate.tm_mon	= 0;
    _endDate.tm_mday = 0;
    _endDate.tm_hour=0;
    _endDate.tm_min=0;
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

string task::convertToDate(tm _date)
{
    string _result;
    ostringstream convert;
    convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year << " - " ;
    convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
    _result=convert.str();
    //cout<<"YAY"<<_result<<endl;
    return _result;
}

vector<string> task::toString()
{
    vector<string> result;
    string _startDate = convertToDate(getStartDate());
    string _endDate = convertToDate(getEndDate());

    //use ostringstream to convert id to string
    ostringstream convert;
    convert << getID();
    string id= convert.str();

    result.push_back(id);
    result.push_back("Description : "+getEventName());
    result.push_back("Start_Date : "+_startDate);
    result.push_back("End_Date : "+_endDate);
    result.push_back("Priority : "+getPriority());
    result.push_back("Category : "+getCategory());
    return result;
}
