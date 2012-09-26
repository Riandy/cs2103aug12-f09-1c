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
