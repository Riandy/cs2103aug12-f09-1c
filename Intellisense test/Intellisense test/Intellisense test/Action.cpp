#include "Action.h"


Action::Action(void)
{
	//set default flag to true

	_task._description="";
	_task._startDate.tm_year = 0 ;
	_task._startDate.tm_mon	= 0;
	_task._startDate.tm_mday = 0;
	_task._endDate.tm_year = 0 ;
	_task._endDate.tm_mon	= 0;
	_task._endDate.tm_mday = 0;
	_task._priority = "LOW";
	this->_command = "";
	_task._catergory = "";
	_task._id=0;
}


Action::~Action(void)
{
}



string Action::getEventName()
{
	return _task._description;
}
void Action::setEventName(string name)
{
	_task._description = name;
}



tm Action::getStartDate()
{
	return _task._startDate;
}
void Action::setStartDate(tm newDate)
{
	_task._startDate = newDate;
}

string Action::getPriority()
{
	return _task._priority;
}
void Action::setPriority(string newPriority)
{
	_task._priority = newPriority;
}


string Action::getCommand()
{
	return this->_command;
}
void Action::setCommand(string newCommand)
{
	this->_command = newCommand;
}

string Action::getCategory()
{
	return _task._catergory;
}
void Action::setCategory(string newCategory)
{
	_task._catergory = newCategory;
}


