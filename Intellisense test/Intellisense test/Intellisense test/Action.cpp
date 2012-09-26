#include "Action.h"


Action::Action(void)
{
	//set default flag to true

	eventDetails.EventName="";
	eventDetails.StartDate ;
	eventDetails.Priority = false;
	eventDetails.command = "";
	eventDetails.category = "";

}


Action::~Action(void)
{
}



string Action::getEventName()
{
	return eventDetails.EventName;
}
void Action::setEventName(string name)
{
	eventDetails.EventName = name;
}



tm Action::getStartDate()
{
	return eventDetails.StartDate;
}
void Action::setStartDate(tm newDate)
{
	eventDetails.StartDate = newDate;
}

bool Action::getPriority()
{
	return eventDetails.Priority;
}
void Action::setPriority(bool newPriority)
{
	eventDetails.Priority = newPriority;
}

int Action::getStatusCode()
{
	return statusCode;
}
void Action::setStatusCode(int newCode)
{
	statusCode = newCode;
}

string Action::getCommand()
{
	return eventDetails.command;
}
void Action::setCommand(string newCommand)
{
	eventDetails.command = newCommand;
}

string Action::getCategory()
{
	return eventDetails.category;
}
void Action::setCategory(string newCategory)
{
	eventDetails.category = newCategory;
}


