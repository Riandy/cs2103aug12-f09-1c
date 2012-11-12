#include "scheduler.h"

static string MESSAGE_ERROR_NOT_FOUND = "The item does not exist.";
static string MESSAGE_ERROR_INTELLISENSE_CHECK = "Error - The system failed to process your request. Please try again.";
static string MESSAGE_ADD_SUCCESS = "Your event was added successfully.";
static string MESSAGE_DELETE_ALL_SUCCESS = "All events deleted successfully.";
static string MESSAGE_ADD_FAILURE = "Your event was not added successfully.";
static string MESSAGE_DELETE_SUCCESS = "Your event was deleted successfully.";
static string MESSAGE_EDIT_SUCCESS = "Your event was edited successfully.";
static string MESSAGE_UNDO_SUCCESS = "Undo operation was successful.";
static string MESSAGE_UNDO_FAILURE = "There is nothing to undo.";
static string MESSAGE_REDO_SUCCESS = "Redo operation was successful.";
static string MESSAGE_REDO_FAILURE = "There is nothing to redo.";
static string MESSAGE_GUI_DISPLAY_TABLE = "%123TABLE_SEAMPLE_&987";
static string MESSAGE_GUI_DISPLAY_TABLE_2 = "%987TABLE_SEAMPLE_&123";
static string MESSAGE_ADD_INVALID_DATE = "You have entered an invalid date.";
static string MESSAGE_ADD_NO_NAME = "You have not entered a valid event description.";
static string MESSAGE_DELETE_WARNING = "Your input was both an event name as well as a serial number. An entry was deleted by its serial number.";
static string MESSAGE_MARK_SUCCESS = "Your event was marked as completed.";
static string MESSAGE_MARK_FAILURE = "There was an error marking your event.";
static string MESSAGE_DELETE_NOT_ENOUGH_INPUT = "There is too little information to choose a task to delete.";
static string MESSAGE_INVALID = "INVALID DATE, please enter a valid date";
static string MESSAGE_DELETE_ALL_FAIL = "There was nothing to delete.";
static string EMPTY_DATE = "0 / 0 / 0 - 0 : 0 : 0";
bool scheduler::instanceFlag=false;
static int NOTFOUND = -1;
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

//@Riandy A0088392R
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
        this->Add(newTask);
    }
    else if(command=="DELETE")
    {
        this->Delete(newTask);
    }
	else if(command=="EDIT")
    {
       this->Edit(newTask);
    }
    else if(command=="EDITENTER")
    {
      this->EditEnter(newTask);
    }
    else if(command=="FIND")
    {
      this->Find(newTask);
    }
    else if (command=="DISPLAY")
    {
      this->Display();
    }
    else if (command=="UNDO")
    {
       this->Undo();
    }
    else if (command == "REDO")
    {
       this->Redo();
    }
    else if (command == "TODAY") 
    {
       this->Today();
    }
    else if (command == "MARK")
    {
       this->Mark(newTask);
    }
    else if (command == "TODO")
    {
       this->Todo();
    }
    else if (command == "DISPLAYARCHIVE")
    {
        this->DisplayArchive();
    }
    else if(command=="EXIT")
    {
       this->Exit();
    }
    else
    {
        _faulty->report("Scheduler class: UNKNOWN COMMAND");
        printMessage(MESSAGE_ERROR_INTELLISENSE_CHECK);

    }
    return _result;
}

//@author: U094659H
//returns the number of days in the month
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

//@author: U094659H
//updates the date to a week later
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

//@author: U094659H
//updates the date to 2 week later
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

//@author: U094659H
//updates the date to a month later
void scheduler::updateMonthlyTask(tm &_date)
{
    _date.tm_mon += 1;
    if(_date.tm_mon >12)
    {
        _date.tm_year += 1;
        _date.tm_mon -= 12;
    }

}

//@author: U094659H
//updates a task based on dateType, namely: weekly,monthly,fortnightly
void scheduler::updateTask(task &_task)
{

    Action clone;
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

    Action _clone;
    task duplicate=_task;
    _clone.setTask(duplicate);
    _clone.setCommand("ADD");
    executeCommand(_clone);

}

//@author: U094659H
//transvers throught the array to retrieve events that are going to occur
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

//@Riandy A0088392R
//Get Event name for any event today ending with the hour and minute
string scheduler::getEventNameForEnd(int hour, int min)
{
    std::stringstream feedbackMessage;
    tm eventDate;
    vector<task> taskV=eventCalender.getToday();

    int size = taskV.size();
    for(int i = 0 ; i < size ; i++)
    {
        task currTask = taskV[i];
        eventDate = currTask.getEndDate();
        if(hour==eventDate.tm_hour &&min==eventDate.tm_min)
        {
            feedbackMessage<< currTask.getEventName();
            break;
        }
    }
    return feedbackMessage.str();
}
//@Riandy A0088392R
//Get Event name for any event today starting with the hour and minute
string scheduler::getEventNameForStart(int hour, int min)
{
    std::stringstream feedbackMessage;
    tm eventDate;
    vector<task> taskV=eventCalender.getToday();

    int size = taskV.size();
    for(int i = 0 ; i < size ; i++)
    {
        task currTask = taskV[i];
        eventDate = currTask.getStartDate();
        if(hour==eventDate.tm_hour &&min==eventDate.tm_min)
        {
            feedbackMessage<< currTask.getEventName();
            break;
        }
    }
    return feedbackMessage.str();
}

//@Riandy A0088392R
//This function take the action object and extract the required information,
//package it and store it as a task.
//Note : If any field need to be added in the future, this part is to be added.
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
    newTask.setDateType(newAction.getDateType());
    newTask.setID(newAction.getID());
    return newTask;
}

//@Riandy A0088392R
//This function takes in the tm date object and convert it to the appropriate format
//using stringstream to be displayed in the GUI. Done extra checking if the date field is 0 or 1 digit,
//will append extra 0 into it. so format will always be XX / XX / XXXX
string scheduler::convertToDate(tm _date)
{
    string _dateString;
    ostringstream convert;
    if(_date.tm_mday<TWODIGIT)
        convert<<"0"<<_date.tm_mday<<" / ";
    else
        convert<<_date.tm_mday<<" / ";

    if(_date.tm_mon<TWODIGIT)
        convert<<"0"<<_date.tm_mon<<" / ";
    else
        convert<<_date.tm_mon<<" / ";

    convert<< _date.tm_year << " - " ;

   if(_date.tm_hour<TWODIGIT)
        convert<<"0"<<_date.tm_hour<< " : ";
    else
        convert<<_date.tm_hour<< " : ";

    if(_date.tm_min<TWODIGIT)
        convert<<"0"<<_date.tm_min<< " : ";
    else
        convert<<_date.tm_min<< " : ";

    if(_date.tm_sec<TWODIGIT)
        convert<<"0"<<_date.tm_sec;
    else
        convert<<_date.tm_sec;

   _dateString =convert.str();
    return _dateString;
}


//@Riandy A0088392R
//This function is used to update the result to the GUI
//it will convert the task vector into vector of string which will be used by
//the GUI to display the result
void scheduler::updateGUI(string command)
{
    taskVector = eventCalender.displayDatabase();

    int vectorSize = taskVector.size();
    for (int i = 0; i < vectorSize; i++)
    {
        string _startDate,_endDate;
        //check whether the startDate or endDate is zero.
        //if yes, change it to "-"
        if(isTimeZero(taskVector[i].getStartDate()))
            _startDate="-";
        else
            _startDate = convertToDate(taskVector[i].getStartDate());

        if(isTimeZero(taskVector[i].getEndDate()))
            _endDate="-";
        else
            _endDate = convertToDate(taskVector[i].getEndDate());

        ostringstream convert;

        convert << i+1;
        string id= convert.str();
        _result.push_back(id);
        _result.push_back(taskVector.at(i).getEventName());
        _result.push_back(_startDate);
        _result.push_back(_endDate);
        _result.push_back(taskVector.at(i).getPriority());
        _result.push_back(taskVector.at(i).getCategory());
    }

    //decision to either view in standard or simple view in the GUI
    if (vectorSize>0)
    {
        if(command=="ADD" || command=="DELETE")
            _result.push_back(MESSAGE_GUI_DISPLAY_TABLE_2);
         else
            _result.push_back(MESSAGE_GUI_DISPLAY_TABLE);

    }
}

//@Riandy A0088392R
//This function is used to update the number of results found to the _result vector
//which will be used by the GUI to display
void scheduler::updateResultFound(int size)
{
    ostringstream tempString;
    tempString << "You have ";
    tempString << size;
    tempString << " results found.";
    _result.push_back(tempString.str());
}

//@Riandy A0088392R
//This function check whether the field in the given tm struct
//is all zero. if yes, return true, otherwise return false.
bool scheduler::isTimeZero(tm time)
{
    if(time.tm_hour==0 && time.tm_mday==0 && time.tm_min==0 && time.tm_mon==0 && time.tm_sec==0 && time.tm_year==0)
        return true;
    else
        return false;
}

 //@author: A0069517W
void scheduler::partialUpdateGUI(vector<task> taskVector,string command)
{
    if(command!="ADD")
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
    if (vectorSize>0){
        if(command=="ADD" || command=="DELETE")
        {
            _result.push_back(MESSAGE_GUI_DISPLAY_TABLE_2);
           }
        else{
            _result.push_back(MESSAGE_GUI_DISPLAY_TABLE);
        }
    }
}


 //@author: A0069517W
void scheduler::printMessage(string _messageType)
{
    _result.push_back(_messageType);
}


 //@author: A0069517W
void scheduler::Add(task thisTask)
{
    if(thisTask.getCategory() == "1NVAL1D")
    {
       printMessage(MESSAGE_INVALID);
       return;
    }

    if (thisTask.getEventName() =="")
    {
        printMessage(MESSAGE_ADD_NO_NAME);

    }
    else
    {

        if( eventCalender.addItem(thisTask))
         {
          printMessage(MESSAGE_ADD_SUCCESS);
          vector<task> temp;
          temp.push_back(thisTask);
          partialUpdateGUI(temp,"ADD");
            }
        else
          {
           _faulty->report("Scheduler class: Add command FAIL");
           printMessage(MESSAGE_ADD_FAILURE);
          }
   }
}

 //@author: A0069517W
void scheduler::Delete(task thisTask)
{
    if ((thisTask.getID() == -1) && (thisTask.getEventName() == ""))
            {
                printMessage(MESSAGE_DELETE_NOT_ENOUGH_INPUT);
            }
            else
            {
                ostringstream convert;
                convert<<thisTask.getID();
                string _eventName = convert.str();
            if (thisTask.getEventName() == "all")
            {
                  if (eventCalender.deleteAll())
                printMessage(MESSAGE_DELETE_ALL_SUCCESS);
                  else
                      printMessage(MESSAGE_DELETE_ALL_FAIL);
            }


           else if (eventCalender.checkNameExists(_eventName) && eventCalender.checkID(thisTask.getID())) //@JOHN
            {
                // case whereby user's input is both an event name and valid id.
                eventCalender.deleteItem(thisTask.getID());
                printMessage(MESSAGE_DELETE_WARNING);

            }
            else if(eventCalender.checkID(thisTask.getID()))
            {
                eventCalender.deleteItem(thisTask.getID());
                printMessage(MESSAGE_DELETE_SUCCESS);
            }

            //delete by event name
            else if(thisTask.getEventName()!="-" && eventCalender.deleteItem(thisTask.getEventName())) //@RIANDY
            {
                printMessage(MESSAGE_DELETE_SUCCESS);
            }

           else if(thisTask.getID()!= NOTFOUND)
            {
                // check if user wanted to delete by name, but the name is an integer and was
                // parsed by intellisense to be an integer.

                if (eventCalender.deleteItem(_eventName))
                    printMessage(MESSAGE_DELETE_SUCCESS);
               else
                    printMessage(MESSAGE_ERROR_NOT_FOUND);

            }

            //error handling
            else
            {
                printMessage(MESSAGE_ERROR_NOT_FOUND);
            }
            }
    updateGUI("DELETE");
}


//@PAN WENREN A0083711L
void scheduler::Edit(task thisTask) //@WENREN
{
    taskVector = eventCalender.SearchByPartialTask(thisTask.getEventName());
    partialUpdateGUI(taskVector,"EDIT");
}

//@PAN WENREN A0083711L
void scheduler::EditEnter(task thisTask)
{
    if (thisTask.getEventName()!="")
           {
               taskVector = eventCalender.SearchByTask(thisTask.getEventName());
               if (taskVector.size() == 0)
               {
                   printMessage(MESSAGE_ERROR_NOT_FOUND);
               }
               else
               {
                    if(eventCalender.editTask(thisTask))
                         printMessage(MESSAGE_EDIT_SUCCESS);
               }

           }

           else
        // No event description in task packet, unable to edit anything.
           {
               _faulty->report("Scheduler class: Edit command FAIL");
               printMessage(MESSAGE_ERROR_INTELLISENSE_CHECK);
           }
    updateGUI("EDIT");
}
 //@author: A0069517W
void scheduler::Display()
{
    taskVector=eventCalender.displayDatabase();
    partialUpdateGUI(taskVector,"DISPLAY");
}
 //@author: A0069517W
void scheduler::Undo()
{
    if (eventCalender.undoAction())
           printMessage(MESSAGE_UNDO_SUCCESS);
        else if (!eventCalender.undoAction())
           printMessage(MESSAGE_UNDO_FAILURE);
    updateGUI("UNDO");
}
 //@author: A0069517W
void scheduler::Redo()
{
    if (eventCalender.redoAction())
        printMessage(MESSAGE_REDO_SUCCESS);
    else if (!eventCalender.redoAction())
      printMessage(MESSAGE_REDO_FAILURE);
    updateGUI("REDO");
}

//@Riandy A0088392R
//This function is to find the today's event and
//update the result to _result through partialUpdateGui function
void scheduler::Today()
{
    taskVector = eventCalender.getToday();
    partialUpdateGUI(taskVector,"TODAY");
}

//@Riandy A0088392R
//This function is used to find a specific task in the database.
//User can either find by category,eventName,date.
//either than that 3 type, error message will be generated.
void scheduler::Find(task thisTask)
{
    string _dateString = eventCalender.convertToDateNoTime(thisTask.getStartDate());

    //case 1: search by category
    if(thisTask.getCategory()!="#"){
        taskVector = eventCalender.SearchByCat(thisTask.getCategory());
        partialUpdateGUI(taskVector,"FIND");
    }
    //case 2: search by task
    else if (thisTask.getEventName()!=""){
        taskVector = eventCalender.SearchByTask(thisTask.getEventName());
        partialUpdateGUI(taskVector,"FIND");
    }
    else if (_dateString != EMPTY_DATE){
        taskVector = eventCalender.SearchByDate(_dateString);
        partialUpdateGUI(taskVector,"FIND");
    }
    else{
        //display error message and log the error in a txt file
        printMessage(MESSAGE_ERROR_INTELLISENSE_CHECK);
        //error logging
        _faulty->report("Scheduler:: Find function fail to find the result");
    }
}
 //@author: A0069517W
void scheduler::Exit()
{
    exit(0);
}

//@author: A0069517W
void scheduler::Mark(task thisTask)
{
    if (  eventCalender.markTask(thisTask) )
        printMessage(MESSAGE_MARK_SUCCESS);
    else
        printMessage(MESSAGE_MARK_FAILURE);
    updateGUI("MARK");
}

//@author: A0069517W
void scheduler::Todo()
{
    taskVector = eventCalender.getFloatingEvents();
    partialUpdateGUI(taskVector,"TODO");
}


//@WEIYUAN A0086030R
//Get a list of today's events for StandardView
vector<string> scheduler:: getTodayEvents()
{
    int size;
    vector<task> firstPriority;
    bool firstPriorityFound = false;
    int threeCountFlag = 0;
    vector<task> threeTasks;
    int highPriorityTasks = 0;

    getAllRequiredParameters(firstPriority, firstPriorityFound,
                             highPriorityTasks,size,
                             threeCountFlag, threeTasks);

    return makeTodayStringResults(firstPriority, firstPriorityFound,
                                  highPriorityTasks,size,
                                  threeCountFlag, threeTasks);
}
//@WEIYUAN A0086030R
//Called by getTodayEvents to retrieve the required parameters for making the returning
//vector of strings
void scheduler::getAllRequiredParameters(vector<task>& firstPriority, bool& firstPriorityFound,
                                         int&  highPriorityTasks, int& size,
                                         int& threeCountFlag, vector<task>& threeTasks)
{
    _result.clear();
    vector<task> taskList = eventCalender.getToday();
    size = taskList.size();

    for (int i = 0; i < size ; i++)
    {
        if (taskList[i].getPriority() == "HIGH")
        {
            highPriorityTasks++;
        }

        if (!firstPriorityFound && taskList[i].getPriority() == "HIGH")
        {
            firstPriorityFound = true;
            firstPriority.push_back(taskList[i]);
        }
        else if (threeCountFlag < 3)
        {
            threeCountFlag++;
            threeTasks.push_back(taskList[i]);
        }
    }
}
//@WEIYUAN A0086030R
//Function creates a vector of strings according to parameters sent in for today's events
vector<string> scheduler::makeTodayStringResults(vector<task> firstPriority, bool firstPriorityFound,
                                                 int highPriorityTasks, int size,
                                                 int threeCountFlag, vector<task> threeTasks)
{
    vector<string> eventsOverview;
    eventsOverview.push_back(getStringFromInt(size));
    eventsOverview.push_back(getStringFromInt(highPriorityTasks));
    if (firstPriorityFound)
    {
        partialUpdateGUI(firstPriority,"MARKTODAY");
        _result.erase(_result.begin());
        _result.erase(_result.begin()+(_result.size()-1));
        eventsOverview = combineStringVectors(eventsOverview,_result);
    }
    if (threeCountFlag != 0)
    {
        _result.clear();
        partialUpdateGUI(threeTasks,"MARKTODAY");
        _result.erase(_result.begin());
        _result.erase(_result.begin()+(_result.size()-1));
        eventsOverview = combineStringVectors(eventsOverview,_result);
    }
    return eventsOverview;
}
//@WEIYUAN A0086030R
//Take the content of both vectors and return as a single
//vector of strings
vector<string> scheduler:: combineStringVectors(
        vector<string> first, vector<string> second)
{
    vector<string> combined = first;

    int size = second.size();
    for (int i = 0; i < size ;i++)
    {
        combined.push_back(second[i]);
    }

    return combined;
}
//@WEIYUAN A0086030R
//Get a string conversion from the integer that is sent in as the parameter
string scheduler:: getStringFromInt(int subject)
{
    stringstream buffer;
    buffer << subject;
    return buffer.str();
}

//@Riandy A0088392R
//display the archive file to the GUI
void scheduler::DisplayArchive()
{
    taskVector=eventCalender.displayArchiveEvent();
    partialUpdateGUI(taskVector,"DISPLAYARCHIVE");
}
