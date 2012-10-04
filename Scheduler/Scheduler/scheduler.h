#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "calender.h"
#include "Action.h"
#include <sstream>

class scheduler
{
private:
	vector<string> result;
	vector<task> taskVector;
	calender eventCalender;
	string convertToString(vector calender::task);

public:
	scheduler();
	~scheduler();
	vector<string> executeCommand(Action newaction);
	//pass in action
};
#endif