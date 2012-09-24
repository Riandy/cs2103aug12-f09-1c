#include "Action.h"


Action::Action(void)
{
	//set default flag to true
	for(int i=0; i<MAXNOOFPARAMETERS; i++)
	{
		statusFlags[i] = true;
	}
	eventDetails.EventName="";
	eventDetails.Date = 0;
	eventDetails.Priority = false;
	eventDetails.command = "";
	eventDetails.category = "";
	requirementsMet = false;
}


Action::~Action(void)
{
}

void Action::setAllStatusFlag()
{
	if(getEventName() == "" )
		setStatusFlagAt(INAME,false);
	else
		setStatusFlagAt(INAME,true);

	
	if(getDate() == 0)
		setStatusFlagAt(IDATE,false);
	else
		setStatusFlagAt(IDATE,true);

	if(getPriority() == false )
		setStatusFlagAt(IPRIORITY,false);
	else
		setStatusFlagAt(IPRIORITY,true);

	
	if(getCategory() == "")
		setStatusFlagAt(ICATEGORY,false);
	else
		setStatusFlagAt(ICATEGORY,true);
}
void  Action::getAllStatusFlag(bool *flags)
{
	for (int i=0;i<MAXNOOFPARAMETERS;i++)
	{
		flags[i] = statusFlags[i];;
	}
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

string Action::getCategory()
{
	return eventDetails.category;
}
void Action::setCategory(string newCategory)
{
	eventDetails.category = newCategory;
}
bool Action::getStatusFlagAt(int index)
{
	return statusFlags[index];
}
void Action::setStatusFlagAt(int index,bool flag)
{
	statusFlags[index] =flag;
}
bool Action::getrequirementsMet()
{
	return requirementsMet;
}
void Action::setRequirementsMet(bool req)
{
	requirementsMet = req;
}

void Action::checkAddReq()
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
}

void Action::checkDelReq()
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
}
void Action::checkDspReq()
{
	if (statusFlags[ICATEGORY] )
	{
		requirementsMet = true;
	}
	if (statusFlags[IDATE] )
	{
		requirementsMet = true;
	}

}
void Action::checkMarkReq()	
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
	if (statusFlags[IDATE] )
	{
		requirementsMet = true;
	}
}
void Action::checkFindReq()	
{
	if (statusFlags[IDATE] )
	{
		requirementsMet = true;
	}
	if (statusFlags[ICATEGORY] )
	{
		requirementsMet = true;
	}
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
}
void Action::checkEditReq()	
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
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
