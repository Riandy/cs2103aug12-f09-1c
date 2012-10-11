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
	taskVector.clear();
	_result.clear();
	//process the given information to task
	task newTask;
	newTask._category=newAction.getCategory();
	newTask._description=newAction.getEventName();
	newTask._endDate=newAction.getEndDate();
	newTask._priority=newAction.getPriority();
	newTask._startDate=newAction.getStartDate();
	newTask._id=newAction.getID();

	if(command=="ADD")
	{
		// We want to add, then show the new database to the user
		eventCalender.addItem(newTask);
		taskVector = eventCalender.displayDatabase();
		convertToString(taskVector);
	}
	else if(command=="DELETE")
	{
		if(eventCalender.checkID(newTask._id))
		{
			// We want to delete, then show the new database to the user
			eventCalender.deleteItem(newTask._id);
			taskVector = eventCalender.displayDatabase();
			convertToString(taskVector);
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
		if(newTask._category!="")
		{		
			taskVector = eventCalender.SearchByCat(newTask._category);
			convertToString(taskVector);

		}
		//case 2: search by task
		else if (newTask._description!="")
		{
			taskVector = eventCalender.SearchByTask(newTask._description);
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

void scheduler::convertToString(vector<task> taskVector)
{
	
	int vectorSize = taskVector.size();
	for (int i = 0; i < vectorSize; i++)
		
	{
		string _startDate = convertToDate(taskVector[i]._startDate);
		string _endDate = convertToDate(taskVector[i]._endDate);

		stringstream strStream;
		strStream<<taskVector[i]._description;
		strStream<<_startDate;
		strStream<<_endDate;
		strStream<<taskVector[i]._priority;
		strStream<<taskVector[i]._category;
		strStream<<taskVector[i]._id;
		string taskString = strStream.str();
		_result.push_back(taskString);
	}

}


string scheduler::convertToDate(tm _date)
{
	string _result;
	_result = _date.tm_min;
	_result += _date.tm_hour;
	_result += _date.tm_mday;
	_result += _date.tm_mon;
	_result += _date.tm_year;
	return _result;


}

void scheduler::generalError()
{
	_result.push_back(ERROR_INTELLISENSE_CHECK);
}