#include "scheduler.h"

static string MESSAGE_ERROR_NOT_FOUND = "Error - The item does not exist.";
static string MESSAGE_ERROR_INTELLISENSE_CHECK = "Error - The system failed to process your request. Please try again";
static string MESSAGE_ADD_SUCCESS = "Your event was added successfully.";
static string MESSAGE_ADD_FAILURE = "Your event was not added successfully";
static string MESSAGE_DELETE_SUCCESS = "Your event was deleted successfully";
static string MESSAGE_EDIT_SUCCESS = "Your event was edited successfully";
static string MESSAGE_UNDO_SUCCESS = "Undo operation was successful";
static string MESSAGE_UNDO_FAILURE = "There is nothing to undo";
static string MESSAGE_REDO_SUCCESS = "Redo operation was successful";
static string MESSAGE_REDO_FAILURE = "There is nothing to redo";
static string MESSAGE_GUI_DISPLAY_TABLE = "%123TABLE_SEAMPLE_&987";
static string MESSAGE_ADD_INVALID_DATE = "You have entered an invalid date";

bool scheduler::instanceFlag=false;
scheduler* scheduler::_scheduler=NULL;

scheduler* scheduler::getInstance()
{
    if(!instanceFlag)
    {
        _scheduler=new scheduler();
        instanceFlag=true;
        return _scheduler;
    }
    else
    {
        return _scheduler;
    }
}

scheduler::scheduler()
{
    _faulty = _faulty->getInstance();
}

scheduler::~scheduler()
{
    instanceFlag = false;
    _faulty->endInstance();
}

vector<string> scheduler::executeCommand(Action newAction)
{
    //get the command type
    string command=newAction.getCommand();
    ASSERT(command!="","Command is NULL");
    /*defensive coding*/
    //convert command to upper case to ensure that it is not case sensitive
    transform(command.begin(), command.end(),command.begin(), ::toupper);

    //process and package the action into task
    task newTask=processAction(newAction);

    if(command=="ADD")
    {
        if(newTask.getCategory() == "1NVAL1D")
        {
            printMessage(MESSAGE_ADD_INVALID_DATE);

        }




// EXTRA CODE TO BE REMOVED
        else if (newTask.getEventName() == "Rick Roll")
        {
            taskVector = eventCalender.rickRoll();
            partialUpdateGUI(taskVector);
        }
// END OF EXTRA CODE TO BE REMOVED







        else
        {

       if( eventCalender.addItem(newTask))
	   {
         printMessage(MESSAGE_ADD_SUCCESS);
         updateGUI();
	   }
       else
       {
           _faulty->report("Scheduler class: Add command FAIL");
           printMessage(MESSAGE_ADD_FAILURE);
       }
       }
    }

    else if(command=="DELETE")
    {
        //delete by ID
        ASSERT((newTask.getID()!=NULL || newTask.getEventName()!="#"),"No parameter passed in to the delete function");
        if(eventCalender.checkID(newTask.getID()) || (newTask.getID() == 9999))
        {
            eventCalender.deleteItem(newTask.getID());
            printMessage(MESSAGE_DELETE_SUCCESS);
            updateGUI();
        }

        //delete by event name
        else if(newTask.getEventName()!="-" && eventCalender.deleteItem(newTask.getEventName()))
        {
            printMessage(MESSAGE_DELETE_SUCCESS);
            updateGUI();
        }

        //error handling
        else
        {
            printMessage(MESSAGE_ERROR_NOT_FOUND);
            updateGUI();
        }
    }


	else if(command=="EDIT")
    {
		// Edit Key press function to partially update GUI
        //if (newTask.getEventName()!="")
                cout<<"Edit execution with normal keypress"<<endl;
                taskVector = eventCalender.SearchByPartialTask(newTask.getEventName());
                partialUpdateGUI(taskVector);

    }
    else if(command=="EDITENTER")
    {

        // actual edit
        if (newTask.getEventName()!="")
        {
            taskVector = eventCalender.SearchByTask(newTask.getEventName());
            if (taskVector.size() == 0) //if no match found
            {
                printMessage(MESSAGE_ERROR_NOT_FOUND);
            }
            else
            {
                 if(eventCalender.editTask(newTask))
                   {
               //     taskVector = eventCalender.displayDatabase();
                    printMessage(MESSAGE_EDIT_SUCCESS);
                 //   partialUpdateGUI(taskVector);
                  }
            }
        }


        else
        {
            _faulty->report("Scheduler class: Edit command FAIL");
            printMessage(MESSAGE_ERROR_INTELLISENSE_CHECK);
        }
        updateGUI();

    }

    else if(command=="FIND")
    {
        //case 1: search by category
        if(newTask.getCategory()!="#")
        {
            taskVector = eventCalender.SearchByCat(newTask.getCategory());

            partialUpdateGUI(taskVector);
        }
        //case 2: search by task
        else if (newTask.getEventName()!="")
        {
            taskVector = eventCalender.SearchByTask(newTask.getEventName());
            partialUpdateGUI(taskVector);
        }
        else
        {
            printMessage(MESSAGE_ERROR_INTELLISENSE_CHECK);
            _faulty->report("Scheduler:: Find function fail to find the result");
        }
    }
    else if (command=="DISPLAY")
    {
        taskVector=eventCalender.displayDatabase();
        partialUpdateGUI(taskVector);
    }

    else if (command=="UNDO")
    {
        if (eventCalender.undoAction())
           printMessage(MESSAGE_UNDO_SUCCESS);
        else if (!eventCalender.undoAction())
           printMessage(MESSAGE_UNDO_FAILURE);
        updateGUI();
    }

    else if (command == "REDO")
    {
        if (eventCalender.redoAction())
            printMessage(MESSAGE_REDO_SUCCESS);
        else if (!eventCalender.redoAction())
          printMessage(MESSAGE_REDO_FAILURE);
        updateGUI();
    }

    else if (command == "TODAY") 
    {
        taskVector = eventCalender.getToday();
        partialUpdateGUI(taskVector);
    }
    else if(command=="EXIT")
    {
        exit(0);
    }
    else
    {
        _faulty->report("Scheduler class: UNKNOWN COMMAND");
        printMessage(MESSAGE_ERROR_INTELLISENSE_CHECK);
    }
    return _result;
}

int scheduler::daysMonth(int year, int month)
{
    int numberOfDays;
    if (month == 4 || month == 6 || month == 9 || month == 11)
      {numberOfDays = 30;}
    else if (month == 2)
    { bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
      if (isLeapYear)
       { numberOfDays = 29;}
      else
       { numberOfDays = 28;}
    }
    else
     { numberOfDays = 31;}

    return numberOfDays;

}

void scheduler::updateWeeklyTask(tm &_date)
{
    int numberOfDays=daysMonth(_date.tm_year,_date.tm_mon);
    _date.tm_mday+=7;
    int difference = _date.tm_mday - numberOfDays;
    if((difference)>0)
{
    _date.tm_mon+=1;
    _date.tm_mday-=numberOfDays;

}
}

void scheduler::updateFornightlyTask(tm &_date)
{
    int numberOfDays=daysMonth(_date.tm_year,_date.tm_mon);
    _date.tm_mday+=14;
    int difference = _date.tm_mday - numberOfDays;
    if((difference)>0)
{
    _date.tm_mon+=1;
    _date.tm_mday-=numberOfDays;

}
}

void scheduler::updateMonthlyTask(tm &_date)
{
    _date.tm_mon += 1;
    if(_date.tm_mon >12)
    {
        _date.tm_year += 1;
        _date.tm_mon -= 12;
    }

}

void scheduler::updateTask(task &_task)
{
    cout<<"**********start Date  before ********"<<endl;
    cout<<"year : "<<_task.getStartDate().tm_year<<endl;
    cout<<"month : "<<_task.getStartDate().tm_mon<<endl;
    cout<<"day : "<<_task.getStartDate().tm_mday<<endl;
    cout<<"hour : "<<_task.getStartDate().tm_hour<<endl;
    cout<<"min : "<<_task.getStartDate().tm_min<<endl;
    cout<<"dateType :"<<_task.getDateType()<<endl;

    Action clone;                 //wenbin: this is illegal, i will do it properly in due time
    clone.setCommand("DELETE");
    clone.setEventName(_task.getEventName());
    executeCommand(clone);
    int dateType= _task.getDateType();
    if(dateType == 0) //defensive coding/handling
    {
        return;
    }
    tm startdate=_task.getStartDate();
    switch(dateType)
    {
    case 1:
        updateWeeklyTask(startdate);
        break;
    case 2:
        updateFornightlyTask(startdate);
        break;
    case 3:
        updateMonthlyTask(startdate);
        break;
    default:break;
    }
    _task.setStartDate(startdate);
    cout<<"**********start Date  after ********"<<endl;
    cout<<"year : "<<_task.getStartDate().tm_year<<endl;
    cout<<"month : "<<_task.getStartDate().tm_mon<<endl;
    cout<<"day : "<<_task.getStartDate().tm_mday<<endl;
    cout<<"hour : "<<_task.getStartDate().tm_hour<<endl;
    cout<<"min : "<<_task.getStartDate().tm_min<<endl;
    cout<<"dateType :"<<_task.getDateType()<<endl;

    Action _clone;
    task duplicate=_task;
    _clone.setTask(duplicate);
    _clone.setCommand("ADD");
    executeCommand(_clone);

}

string scheduler::getEventBasedOnTime(int hour, int min)
{
    std::stringstream feedbackMessage;
    tm eventStart;

    vector<task> taskV=eventCalender.getToday();
    for(vector<task>::iterator it = taskV.begin(); it!= taskV.end();++it)
    {

        eventStart= it->getStartDate();
        if(hour==eventStart.tm_hour)
        {
            if(min==eventStart.tm_min)
            {
                feedbackMessage<<it->getEventName()<<"\n";
                updateTask(*it);
            }
        }

    }

    return feedbackMessage.str();
}

task scheduler::processAction(Action newAction)
{
    taskVector.clear();
    _result.clear();
    task newTask;
    newTask.setEventName(newAction.getEventName());
    newTask.setCategory(newAction.getCategory());
    newTask.setPriority(newAction.getPriority());
    newTask.setStartDate(newAction.getStartDate());
    newTask.setEndDate(newAction.getEndDate());
    newTask.setID(newAction.getID());
    return newTask;
}

string scheduler::convertToDate(tm _date)
{
    string _result;
    ostringstream convert;
    if(_date.tm_mday<10)
        convert<<"0"<<_date.tm_mday<<" / ";
    else
        convert<<_date.tm_mday<<" / ";

    if(_date.tm_mon<10)
        convert<<"0"<<_date.tm_mon<<" / ";
    else
        convert<<_date.tm_mon<<" / ";

    convert<< _date.tm_year << " - " ;

    if(_date.tm_hour<10)
        convert<<"0"<<_date.tm_hour<< " : ";
    else
        convert<<_date.tm_hour<< " : ";

    if(_date.tm_min<10)
        convert<<"0"<<_date.tm_min<< " : ";
    else
        convert<<_date.tm_min<< " : ";

    if(_date.tm_sec<10)
        convert<<"0"<<_date.tm_sec;
    else
        convert<<_date.tm_sec;

    _result=convert.str();
    return _result;
}



void scheduler::updateGUI()
{
    taskVector = eventCalender.displayDatabase();
    int vectorSize = taskVector.size();
    for (int i = 0; i < vectorSize; i++)
    {
        string _startDate,_endDate;
        if(isTimeZero(taskVector[i].getStartDate()))
            _startDate="-";
        else
            _startDate = convertToDate(taskVector[i].getStartDate());

        if(isTimeZero(taskVector[i].getEndDate()))
            _endDate="-";
        else
            _endDate = convertToDate(taskVector[i].getEndDate());

        ostringstream convert;
        //convert << taskVector.at(i).getID()+1; // commented out as it pass incorrect id to gui
        convert << i+1;//i added this as a temporary replacement for the id above,remove this when u updated ur code
        string id= convert.str();
        _result.push_back(id);
        _result.push_back(taskVector.at(i).getEventName());
        _result.push_back(_startDate);
        _result.push_back(_endDate);
        _result.push_back(taskVector.at(i).getPriority());
        _result.push_back(taskVector.at(i).getCategory());
    }

    //decision to either view in standard or simple view
    if (vectorSize>0)
     _result.push_back(MESSAGE_GUI_DISPLAY_TABLE);
}

void scheduler::partialUpdateGUI(vector<task> taskVector)
{
    updateResultFound(taskVector.size());
    int vectorSize = taskVector.size();
    for (int i = 0; i < vectorSize; i++)

    {
        string _startDate,_endDate;
        if(isTimeZero(taskVector[i].getStartDate()))
            _startDate="-";
        else
            _startDate = convertToDate(taskVector[i].getStartDate());

        if(isTimeZero(taskVector[i].getEndDate()))
            _endDate="-";
        else
            _endDate = convertToDate(taskVector[i].getEndDate());

        ostringstream convert;
        //convert << taskVector.at(i).getID()+1; // commented out as it pass incorrect id to gui
        convert << i+1;//i added this as a temporary replacement for the id above,remove this when u updated ur code
        string id= convert.str();
        _result.push_back(id);
        _result.push_back(taskVector.at(i).getEventName());
        _result.push_back(_startDate);
        _result.push_back(_endDate);
        _result.push_back(taskVector.at(i).getPriority());
        _result.push_back(taskVector.at(i).getCategory());
    }
    //decision to either view in standard or simple view
    if (vectorSize!=0)
        _result.push_back(MESSAGE_GUI_DISPLAY_TABLE);
}

void scheduler::updateResultFound(int size)
{
    ostringstream tempString;
    tempString << "You have ";
    tempString << size;
    tempString << " results found.";
    _result.push_back(tempString.str());
}

void scheduler::printMessage(string _messageType)
{
    _result.push_back(_messageType);
}

bool scheduler::isTimeZero(tm time)
{
    if(time.tm_hour==0 && time.tm_mday==0 && time.tm_min==0 && time.tm_mon==0 && time.tm_sec==0 && time.tm_year==0)
        return true;
    else
        return false;
}
