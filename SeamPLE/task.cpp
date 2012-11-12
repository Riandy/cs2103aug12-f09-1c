#include "task.h"


const int  task::DATENORMAL         = 0;
const int  task::DATEWEEKLY         = 1;
const int  task::DATEFORTNIGHTLY     = 2;
const int  task::DATEMONTHLY         = 3;

//@PAN WENREN A0083711L
task::task(void)
{//whenever this part is changed the get requirements have to change and minimum requirements have to be checked
    //the get category and get functions have to change since they default indicator is set by all the getter functions
    _description            = "";
    _startDate.tm_year      = 0 ;
    _startDate.tm_mon       = 0;
    _startDate.tm_mday      = 0;
    _startDate.tm_min       = 0;
    _startDate.tm_hour      = 0;
    _startDate.tm_sec       = 0;
    _endDate.tm_year        = 0 ;
    _endDate.tm_mon         = 0;
    _endDate.tm_mday        = 0;
    _endDate.tm_hour        = 0;
    _endDate.tm_min         = 0;
    _endDate.tm_sec         = 0;
    _priority               = "LOW";
    _category               = "#";
    _description            = "-";
    _id                     = -1;
    dateType                = DATENORMAL;//normal mode
}
task::~task(void)
{

}
//@PAN WENREN A0083711L
string task::getEventName()
{
    return _description;
}
//@PAN WENREN A0083711L
void task::setEventName(string name)
{
    _description = name;
}
//@PAN WENREN A0083711L
tm task::getStartDate()
{
    return _startDate;
}
//@PAN WENREN A0083711L
void task::setStartDate(tm newDate)
{
    _startDate = newDate;
}

//@PAN WENREN A0083711L
tm task::getEndDate()
{
    return _endDate;
}
//@PAN WENREN A0083711L
void task::setEndDate(tm newDate)
{
    _endDate = newDate;
}
//@PAN WENREN A0083711L
string task::getPriority()
{
    return _priority;
}
//@PAN WENREN A0083711L
void task::setPriority(string newPriority)
{
    _priority = newPriority;
}
//@PAN WENREN A0083711L
string task::getCategory()
{
    return _category;
}
//@PAN WENREN A0083711L
void task::setCategory(string newCategory)
{
    _category = newCategory;
}
//@PAN WENREN A0083711L
int task::getID()
{
    return _id;
}
//@PAN WENREN A0083711L
void task::setID(int newID)
{
    _id = newID;
}
//@PAN WENREN A0083711L
int task::getDateType()
{
    return dateType;
}
//@PAN WENREN A0083711L
void task::setDateType(int newType)
{
    dateType= newType;
}
//@CHAM WEN BIN U094659H
string task::convertToDate(tm _date)
{
    string _result;
    ostringstream convert;
    convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year << " - " ;
    convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
    _result=convert.str();
    return _result;
}
//@CHAM WEN BIN U094659H
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
    result.push_back("Date_Type : "+ convertInt(dateType));
    result.push_back("Priority : "+getPriority());
    result.push_back("Category : "+getCategory());
    return result;
}
//@CHAM WEN BIN U094659H
//returns from int to string
string task:: convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
//@CHAM WEN BIN U094659H
tm  task::getEmptyDateTm()
{

    struct tm emptyTime;
    emptyTime.tm_year = 0 ;
    emptyTime.tm_mon  = 0;
    emptyTime.tm_mday = 0;
    emptyTime.tm_min  = 0;
    emptyTime.tm_hour = 0;
    emptyTime.tm_sec  = 0;

    return emptyTime;
}
