#include "Action.h"


Action::Action(void)
{
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

int Action::getDate()
{
	return eventDetails.Date;
}
void Action::setDate(int newDate)
{
	eventDetails.Date = newDate;
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