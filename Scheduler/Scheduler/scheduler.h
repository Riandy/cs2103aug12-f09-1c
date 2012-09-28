#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "calender.h"
#include "Action.h"

class scheduler
{
private:
	vector<string> result;
	calender eventCalender;

public:
	scheduler();
	~scheduler();
	vector<string> executeCommand(Action newaction);
	//pass in action
};
#endif