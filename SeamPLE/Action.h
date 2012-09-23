#ifndef  ACTION_H
#define ACTION_H
#include <string>
using namespace std;


struct Event
{
	string EventName;
	int Date;
	bool Priority;	
	string command;// this is based on the intellisenseTest file. How bout we change this to base on your operation enum
	//do you want the command to be in the event struct?  
};
class Action
{
private :
	Event eventDetails;
	int statusCode;
	//not sure what other details you need for version 0.0 prototype
	//if theres any other fields that you wish to include, do tell me so i can add them in

public:
	Action(void);
	~Action(void);

	string getCommand();
	void setCommand(string);

	string getEventName();
	void setEventName(string);

	int getDate();
	void setDate(int );

	bool getPriority();
	void setPriority(bool);

	int getStatusCode();
	void setStatusCode(int); 
};



// STATUS CODE
#define INVALIDCOMAND	0
#define VALIDADD		1
#define	VALIDDEL		2
#define VALIDEDIT		3
#define VALIDFIND		4
#define	VALIDDISPLAY	5
#define	VALIDMARK		6

//ALL ADD ERROR CODE BEGIN WITH 1X EG 11,12,13
#define	ERR_ADD_D	11	//INVALID DATE OR NO DATE
#define ERR_ADD_P	12	//INVALID PRIORITY ASSUMING DATE IS K

//ALL DEL ERROR CODE BEGIN WITH 2X, EG 21,22,23...
#define ERR_DEL_T 21	//INVALID TASK NAME OR NOT FOUND

//ALL EDIT ERROR CODE BEGIN WITH 3X
#define ERR_EDIT_NT 30 // NO FIELDS ENTERED TO EDIT
#define ERR_EDIT_T 31 // TASK DOES NOT EXIST
#define ERR_EDIT_D 32 //DATE FORMAT WRONG
#define ERR_EDIT_P 33 //INVALID PRIORITY

//ALL FIND ERROR CODE BEGIN WITH 4X
#define ERR_FIND_D 41 //DATE FORMAT INCORRECT
#define ERR_FIND_P 42//PRIORITY IS INVALID

//ALL DISPLAY ERROR CODE BEGIN WITH 5X
#define ERR_DSP_D 51 //DATE FORMAT IS INVALID

//ALL MARK ERROR CODE BEGIN WITH 6X
#define ERR_MARK_T 61 //TASK NOT FOUND
#define ERR_MARK_D 62 // DATE FORMAT IS INVALID

// the one below is for magic number that we used in our intellisense
#define FORMATINVALIDDATE 99999999

//for error code
string feedbackMsg(int errorcode)
{ //i think this part has no need to be extracted to static const string since the purpose of the function 
	//is to solely convert errorcode to error messages. What do you think wenbin?
	string messageOut;
	switch (errorcode)
	{
	case INVALIDCOMAND:
		messageOut = "Invalid Operation. Eg.add, del, edit, find ,dsp, mark  ";	
		break;
	case VALIDADD :
		messageOut = "Event successfully added.";
		break;
	case VALIDDEL :
		messageOut = "Event successfully deleted.";
		break;
	case VALIDEDIT :
		messageOut = "Event Edited. ";
		break;
	case VALIDFIND :
		messageOut = "Displaying Search resutlts...";
		break;
	case VALIDDISPLAY :
		messageOut = "Displaying Search resutlts.";
		break;
	case VALIDMARK:
		messageOut = "Event has been marked.";
		break;
	case ERR_ADD_D:
		messageOut = "Invalid Date format.Eg add meeting 24082012 ";
		break;
	case ERR_ADD_P:
		messageOut = "Invalid priority. Priority please enter H or L ";
		break;
	case ERR_DEL_T:
		messageOut = "Invalid Task name , Event not found";
		break;
	case ERR_EDIT_NT:
		messageOut = "No fields entered For editing.";
		break;
	case ERR_EDIT_T:
		messageOut = "Invalid Task name , Event not found";
		break;
	case ERR_EDIT_D:
		messageOut = "Invalid Date format , please follow ddmmyyyy or ...more to be decided";
		break;
	case ERR_EDIT_P:
		messageOut = "Invalid Priority. Priority please enter H or L ";
		break;
	case ERR_FIND_D:
		messageOut = "Invalid Date format , please follow ddmmyyyy";
		break;
	case ERR_FIND_P:
		messageOut = "Invalid Priority. Priority please enter H or L";
		break;
	case ERR_DSP_D:
		messageOut = "Invalid Date format , please follow ddmmyyyy";
		break;
	case ERR_MARK_T:
		messageOut = "Invalid Task name , Task not found";
		break;
	case ERR_MARK_D:
		messageOut = "Invalid Date format , please follow ddmmyyyy";
		break;

		
	}
	return messageOut;
}

#endif;