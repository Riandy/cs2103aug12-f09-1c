#ifndef  ACTION_H
#define ACTION_H
#include <string>
#include <ctime>
#include "task.h"

using namespace std;

//if we want to extend to more fields we have to add in here
#define MAXNOOFPARAMETERS 5 // NAME,DATE,PRIORITY,CATEGORY,
#define INAME 0	//INDEX OF NAME IN THE FLAG ARRAY
#define IDATE 1
#define IPRIORITY 2
#define ICATEGORY 3
#define IDATEEND 4


class Action
{
private :
	task _task;
	string _command;

public:
	Action(void);
	~Action(void);

	string getCommand();
	void setCommand(string);

	string getEventName();
	void setEventName(string);


	tm getStartDate();
	void setStartDate( tm);
	void setStartDateWithoutTime(tm);

	tm getEndDate();
	void setEndDate( tm);

	string getPriority();
	void setPriority(string);

	string getCategory();
	void setCategory(string);

	int getID();
	void setID(int);

	void determineDate(tm date1,tm date2);


};
#endif;