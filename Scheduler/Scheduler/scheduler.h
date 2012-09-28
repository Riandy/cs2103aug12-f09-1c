#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "calender.h"

class scheduler
{
private:
	
	calender eventCalender;

public:
	scheduler();
	~scheduler();
	bool executeCommand(string command,calender::task newTask);
	//pass in action
};
#endif