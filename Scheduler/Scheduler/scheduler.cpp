#include "scheduler.h"

scheduler::scheduler()
{
}

scheduler::~scheduler()
{
}

bool scheduler::executeCommand(string command,calender::task newTask)
{
	//return type of the execute command?
	if(command=="ADD")
	{
		eventCalender.addItem(newTask);
	}
	else if(command=="DELETE")
	{

	}
	else if(command=="EDIT")
	{

	}
	else if(command=="FIND")
	{

	}

	return true;
}