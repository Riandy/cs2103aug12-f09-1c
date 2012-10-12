#include "scheduler.h"

scheduler::scheduler()
{
}

scheduler::~scheduler()
{
}

vector<string> scheduler::executeCommand(Action newAction)
{
    //get the command type
    string command=newAction.getCommand();

   // this->taskVector.clear();
    //this->_result.clear();

    //process the given information to task
    task newTask;
    newTask.setEventName(newAction.getEventName());
    newTask.setCategory(newAction.getCategory());
    newTask.setPriority(newAction.getPriority());
    newTask.setStartDate(newAction.getStartDate());
    newTask.setEndDate(newAction.getEndDate());
    newTask.setID(newAction.getID());

    if(command=="ADD")
    {
        // We want to add, then show the new database to the user
        eventCalender.addItem(newTask);
        taskVector = eventCalender.displayDatabase();
        convertToString(taskVector);
    }
    else if(command=="DELETE")
    {
        if(eventCalender.checkID(newTask.getID()))
        {
            // We want to delete, then show the new database to the user
            eventCalender.deleteItem(newTask.getID());
            //taskVector = eventCalender.displayDatabase();
            //convertToString(taskVector);
        }
        else
        {
            _result.push_back(ERROR_NOT_FOUND);

        }
    }
    else if(command=="EDIT")
    {
        //not yet implemented
    }
    else if(command=="FIND")
    {
        //can find by category or task
        //case 1: if category is not empty (are we using "" or 0 flag?)
        if(newTask.getCategory()!="")
        {
            taskVector = eventCalender.SearchByCat(newTask.getCategory());
            convertToString(taskVector);

        }
        //case 2: search by task
        else if (newTask.getEventName()!="")
        {
            taskVector = eventCalender.SearchByTask(newTask.getEventName());
            convertToString(taskVector);

        }
        else
            generalError();
    }
    else if (command=="DISPLAY")
    {
        taskVector = eventCalender.displayDatabase();
        convertToString(taskVector);
    }
    else
         generalError();


    return _result;
}

void scheduler::init(Seample *_app)
{
    this->app=_app;
}



void scheduler::convertToString(vector<task> taskVector)
{

    int vectorSize = taskVector.size();
    for (int i = 0; i < vectorSize; i++)

    {
        string _startDate = convertToDate(taskVector[i].getStartDate());
        string _endDate = convertToDate(taskVector[i].getEndDate());

        //use ostringstream to convert id to string
        ostringstream convert;
        convert << taskVector.at(i).getID();
        string id= convert.str();

        _result.push_back(id);
        _result.push_back(taskVector.at(i).getEventName());
        _result.push_back(_startDate);
        _result.push_back(_endDate);
        _result.push_back(taskVector.at(i).getPriority());
        _result.push_back(taskVector.at(i).getCategory());

    }

}

//@Riandy : changed the format abit (TESTED)
string scheduler::convertToDate(tm _date)
{
    string _result;
    ostringstream convert;
    convert<< _date.tm_yday << " / " << _date.tm_mon << " / " << _date.tm_year << " - " ;
    convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
    _result=convert.str();
    return _result;
}

void scheduler::generalError()
{
    _result.push_back(ERROR_INTELLISENSE_CHECK);
}
