#ifndef  ACTION_H
#define ACTION_H
#include <string>
#include <ctime>

using namespace std;

//if we want to extend to more fields we have to add in here
#define MAXNOOFPARAMETERS 4 // NAME,DATE,PRIORITY,CATEGORY,
#define INAME 0	//INDEX OF NAME IN THE FLAG ARRAY
#define IDATE 1
#define IPRIORITY 2
#define ICATEGORY 3

struct Event
{
	string EventName;
	tm StartDate;
	bool Priority;	
	string command;
	string category;
};
class Action
{
private :
	Event eventDetails;
	int statusCode; //removed for current implementation

	//not sure what other details you need for version 0.0 prototype
	//if theres any other fields that you wish to include, do tell me so i can add them in

public:
	Action(void);
	~Action(void);

	string getCommand();
	void setCommand(string);

	string getEventName();
	void setEventName(string);


	tm getStartDate();
	void setStartDate( tm);

	bool getPriority();
	void setPriority(bool);

	string getCategory();
	void setCategory(string);

	int getStatusCode();
	void setStatusCode(int); 


};






#endif;