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
    //command="delete";
    taskVector.clear();
    _result.clear();

    //process the given information to task
    task newTask;
    newTask.setEventName(newAction.getEventName());
    newTask.setCategory(newAction.getCategory());
    newTask.setPriority(newAction.getPriority());
    newTask.setStartDate(newAction.getStartDate());
    newTask.setEndDate(newAction.getEndDate());
    newTask.setID(newAction.getID());

    //newTask.setEventName("eat");

    if(command=="ADD")
    {
        eventCalender.addItem(newTask);
        _result.push_back(ADD_SUCCESS);
        taskVector = eventCalender.displayDatabase();
        updateGUI(taskVector);
    }
    else if(command=="DELETE")
    {
        //delete by ID
        if(newTask.getID()>0)
        {
            if(eventCalender.checkID(newTask.getID()))
            {
                eventCalender.deleteItem(newTask.getID());
                _result.push_back(DELETE_SUCCESS);
                taskVector = eventCalender.displayDatabase();
                updateGUI(taskVector);
            }
        }
        //delete by event name
        else if(newTask.getEventName()!="-")
        {
             if(eventCalender.deleteItem(newTask.getEventName()))
             {
                 _result.push_back(DELETE_SUCCESS);
                taskVector = eventCalender.displayDatabase();
                updateGUI(taskVector);
             }
			 // below else statement should be caught by the one further below.
         /*    else
                 _result.push_back(ERROR_NOT_FOUND);
				 */
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
        //case 1: search by category
        if(newTask.getCategory()!="#")
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

    else if (command == "TODAY") // CHECK THE COMMAND NAME SENT FROM ACTION
    {
        taskVector = eventCalender.getToday();
        convertToString(taskVector);
    }
    else
        generalError();


    return _result;
}

void scheduler::convertToString(vector<task> taskVector)
{

    int vectorSize = taskVector.size();
    string firstPosition;
    ostringstream tempString;
    tempString << "You have ";
    tempString << taskVector.size();
    tempString << " results found.";
    firstPosition = tempString.str();
    _result.push_back(firstPosition);
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


void scheduler::updateGUI(vector<task> taskVector)
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


