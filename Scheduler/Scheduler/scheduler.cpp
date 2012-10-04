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
		eventCalender.addItem(newTask);
	}
	else if(command=="DELETE")
	{
		if(eventCalender.searchID(newTask._id))
		{
			//if id found in the database
			//then perform deletion
			eventCalender.deleteItem(newTask._id);
		}
		else
		{
			//return to user that deletion fails because id doesn't exist

		}
	}
	else if(command=="EDIT")
	{
		//not yet implemented
	}
	else if(command=="FIND")
	{
		//can find by category or task
		//case 1: if category is not empty
		if(newTask._category!="")
		{
			//remember to store the result in a vector later
			taskvector = eventCalender.SearchByCat(newTask._category);
			convertToString(taskvector);

		}
		//case 2: search by task
		else
		{
			//remember to store it in the vector later
			
			taskVector = eventCalender.SearchByTask(newTask._description);
			convertToString(taskVector);

		}
	}

	return result;
}
/*	

WE NEED TO IMPLEMENT A DISPLAY FUNCTION

*/

string sheduler::convertToString(vector<task> taskVector)
{
	
	int vectorSize = taskVector.size();
	for (int i = 0; i < vectorSize; i++)
		
	{
		sstream str;
		str<<taskVector[i]._description;
	//	str<<taskVector[i].asctime(_startdate);
		str<<taskVector[i]._priority;
		str<<taskVector[i]._category;
		str<<taskVector[i]._id;
		result.push(str);

	}

}