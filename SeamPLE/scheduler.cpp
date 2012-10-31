#include "scheduler.h"

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
}

scheduler::~scheduler()
{
    instanceFlag = false;
}

vector<string> scheduler::executeCommand(Action newAction)
{
    //get the command type
    string command=newAction.getCommand();
    command="add";
    ASSERT(command!="","Command is NULL");
    /*defensive coding*/
    //convert everything to upper case
    transform(command.begin(), command.end(),command.begin(), ::toupper);

    //process and package the action into task
    task newTask=processAction(newAction);

    if(command=="ADD")
    {
       if( eventCalender.addItem(newTask))
	   {
			_result.push_back(ADD_SUCCESS);
			taskVector = eventCalender.displayDatabase();
			updateGUI(taskVector);
	   }
	   else
			_result.push_back(ADD_FAILURE);
	}

    else if(command=="DELETE")
    {
        //delete by ID
        if(eventCalender.checkID(newTask.getID()))
        {
            eventCalender.deleteItem(newTask.getID());
            _result.push_back(DELETE_SUCCESS);
            taskVector = eventCalender.displayDatabase();
            updateGUI(taskVector);
        }
        //delete by event name
        else if(newTask.getEventName()!="-" && eventCalender.deleteItem(newTask.getEventName()))
        {
            _result.push_back(DELETE_SUCCESS);
            taskVector = eventCalender.displayDatabase();
            updateGUI(taskVector);
        }
        //error handling
        else
        {
            _result.push_back(ERROR_NOT_FOUND);
            taskVector = eventCalender.displayDatabase();
            updateGUI(taskVector);
        }
    }


	else if(command=="EDIT")
    {
		// Edit Key press function to partially update GUI
        if (newTask.getEventName()!="")
        {
                cout<<"Edit execution with normal keypress"<<endl;
                taskVector = eventCalender.SearchByPartialTask(newTask.getEventName());
                updateResultFound(taskVector.size());
                updateGUI(taskVector);
        }
        else
            generalError();
	    }
    else if(command=="EDITENTER")
    {
		// actual edit
        if (newTask.getEventName()!="")
        {
            taskVector = eventCalender.SearchByTask(newTask.getEventName());
            if (taskVector.size() == 0) //if no match found
			{
               _result.push_back(ERROR_NOT_FOUND);
			}
			else
            {
                 if(eventCalender.editTask(newTask))
                   {
                    taskVector = eventCalender.displayDatabase();
                   _result.push_back(EDIT_SUCCESS);
                    updateGUI(taskVector);
                  }



            }
        }
        else
            generalError();

    }

    else if(command=="FIND")
    {
        //case 1: search by category
        if(newTask.getCategory()!="#")
        {
            taskVector = eventCalender.SearchByCat(newTask.getCategory());
            updateResultFound(taskVector.size());
            updateGUI(taskVector);
        }
        //case 2: search by task
        else if (newTask.getEventName()!="")
        {
            taskVector = eventCalender.SearchByTask(newTask.getEventName());
            updateResultFound(taskVector.size());
            updateGUI(taskVector);
        }
        else
            generalError();

    }
    else if (command=="DISPLAY")
    {

        taskVector = eventCalender.displayDatabase();
        updateResultFound(taskVector.size());
        updateGUI(taskVector);
    }

    else if (command=="UNDO")
    {
        if (eventCalender.undoAction())
	   {
		  _result.push_back(UNDO_SUCCESS);
		   taskVector = eventCalender.displayDatabase();
			   updateGUI(taskVector);
		}
        else if (!eventCalender.undoAction())
            _result.push_back(UNDO_FAILURE);
    }

    else if (command == "REDO")
    {
        if (eventCalender.redoAction())
         {
			_result.push_back(REDO_SUCCESS);
			taskVector = eventCalender.displayDatabase();
		    updateGUI(taskVector);
		}
        else if (!eventCalender.redoAction())
            _result.push_back(REDO_FAILURE);
    }

    else if (command == "TODAY") 
    {
        taskVector = eventCalender.getToday();
        updateGUI(taskVector);
    }
    else
        generalError();


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
    convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year << " - " ;
    convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
    _result=convert.str();
    return _result;
}

void scheduler::generalError()
{
    _result.push_back(ERROR_INTELLISENSE_CHECK);
}


void scheduler::updateGUI(vector<task> taskVector)
{
    int vectorSize = taskVector.size();

    for (int i = 0; i < vectorSize; i++)

    {
        //testing
        string _startDate = convertToDate(taskVector[i].getStartDate());
        string _endDate = convertToDate(taskVector[i].getEndDate());

        ostringstream convert;
       // convert << taskVector.at(i).getID(); // commented out as it pass incorrect id to gui
        convert << i;//i added this as a temporary replacement for the id above,remove this when u updated ur code
        string id= convert.str();
        _result.push_back(id);
        _result.push_back(taskVector.at(i).getEventName());
        _result.push_back(_startDate);
        _result.push_back(_endDate);
        _result.push_back(taskVector.at(i).getPriority());
        _result.push_back(taskVector.at(i).getCategory());

    }
}

void scheduler::updateResultFound(int size)
{
    ostringstream tempString;
    tempString << "You have ";
    tempString << size;
    tempString << " results found.";
    _result.push_back(tempString.str());
}
