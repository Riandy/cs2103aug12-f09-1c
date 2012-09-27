#include "Intellisense.h"


const string Intellisense::addCommand ="add";
const string Intellisense::deleteCommand ="delete";
const string Intellisense::markCommand = "mark";
const string Intellisense::displayCommand= "display";
const string Intellisense::exitCommand = "exit";
const string Intellisense::sortCommand = "sort";
const string Intellisense::findCommand = "find";
const string Intellisense::editCommand = "edit";
const string Intellisense::months[12] = {"JANURARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};

Intellisense::Intellisense(void)
{
	for(int i=0; i<MAXNOOFPARAMETERS; i++)
	{
		statusFlags[i] = true;
	}
	requirementsMet = false;
}


Intellisense::~Intellisense(void)
{
}

Action Intellisense::check(string query)
{	
	Action task;

	trim(query);

	vector<string> buffer = tokenize(query);

	switch(determinOperation(buffer))
	{
	case ADD: 
		task=addOperation(buffer); 
		break;
	case DELETE: 
		task=deleteOperation(buffer);
		break;
	case DISPLAY: 
		task=displayOperation(buffer); 
		break;
	case MARK: 
		task=markOperation(buffer); 
		break;
	case SORT: 
		task=sortOperation(buffer); 
		break;
	case FIND: 
		task=findOperation(buffer); 
		break;
	case EDIT: 
		task=editOperation(buffer); 
		break;
	case EXIT: 
		task=exitOperation(buffer); 
		break;
	case INVALID: 
		task=invalidOperation(buffer); 
		break;
	default:
		break;
	}


	return task;
}




operation Intellisense::determinOperation(vector<string>& tokens)
{
	string commandword=tokens[0];
	if(checkString(commandword,addCommand))
	{
		return ADD;
	}else if(checkString(commandword,deleteCommand))
	{
		return DELETE;
	}else if(checkString(commandword,editCommand))
	{
		return EDIT;
	}else if(checkString(commandword,markCommand))
	{
		return MARK;
	}else if(checkString(commandword,findCommand))
	{
		return FIND;
	}else if(checkString(commandword,sortCommand))
	{
		return SORT;
	}else if(checkString(commandword,displayCommand))
	{
		return DISPLAY;
	}else if(checkString(commandword,exitCommand))
	{
		return EXIT;
	}else
	{
		return INVALID;
	}
}


bool Intellisense::checkString(const string& input, const string& command)
{
	if(input.size() != command.size())
	{
		return false;
	}

	for(string::const_iterator s1=input.begin(),s2=command.begin();s1!=input.end();++s1,++s2)    //converts both strings to lower cases for fair comparison
	{
		if(tolower(*s1) != tolower(*s2))
		{
			return false;
		}
	}
	return true;
}


string Intellisense::getfirst_Word(string command)
{
	return tokenize(command)[0];
}

string Intellisense::getCommand(vector<string>& tokens,string _command)
{
	vector<string>::iterator it=tokens.begin();
	string command = _command;
	it=tokens.erase(it);

	return command;
}


string Intellisense::getPriority(vector<string>& tokens)
{
	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		string checkString = it->c_str();
		if((checkString.compare(string("HIGH"))==0) || checkString.compare(string("high"))==0)
		{
			it=tokens.erase(it);
			return string("HIGH");
		}
	}

	return string("LOW");
}

tm Intellisense::getTime(vector<string>& tokens,tm date)
{
	string time;
	date.tm_hour=0;
	date.tm_min=0;

	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		time=it->c_str();
		if(time.size()>=5)
		{if(time.at(2) == ':' )
		{
			if(time.size()==5)
			{
				time=removeChar(time,":");
				if(isAllInt(time))
				{
					it=tokens.erase(it);
					date.tm_hour=atoi(time.substr(0,2).c_str());
					date.tm_min=atoi(time.substr(2,2).c_str());
					return date;
				}

			}
		}
		}else if(time.size()==4)
		{
			if(checkString("PM",time.substr(2,2))|| checkString("AM",time.substr(2,2)))
			{
				if(isAllInt(time.substr(0,2)))
				{
					it=tokens.erase(it);
					if(checkString("PM",time.substr(2,2)))
					{
						date.tm_hour=atoi(time.substr(0,2).c_str())+12;
						date.tm_min=atoi(time.substr(2,2).c_str());
						return date;
					}
					else
					{
						date.tm_hour=atoi(time.substr(0,2).c_str());
						date.tm_min=atoi(time.substr(2,2).c_str());
						return date;
					}

				}
			}
		}else if(time.size()==3)
		{
			if(checkString("PM",time.substr(1,2))|| checkString("AM",time.substr(1,2)))
			{
				if(isAllInt(string(1,time.at(0))))
				{
					it=tokens.erase(it);
					if(checkString("PM",time.substr(1,2)))
					{
						date.tm_hour=atoi(time.substr(0,2).c_str())+12;
						date.tm_min=atoi(time.substr(2,2).c_str());
						return date;
					}
					else
					{
						date.tm_hour=atoi(time.substr(0,2).c_str());
						date.tm_min=atoi(time.substr(2,2).c_str());
						return date;
					}

				}
			}
		}





	}
	return date;
}


string Intellisense::getCategory(vector<string>& tokens)
{
	string category = "\0";
	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		if(it->at(0) == '#' )
		{
			category = it->substr(1,it->size()-1);
			it = tokens.erase(it);
			return category;
		}
	}
	return category;


}

string Intellisense::removeChar(string s,char chars[])
{
	for (unsigned int i = 0; i < sizeof(chars); ++i)
	{
		s.erase (std::remove(s.begin(), s.end(), chars[i]), s.end());
	}
	return s;
}

string& Intellisense::trim_left_inplace( string& s,  const string& delimiters)
{
	return s.erase(  0, s.find_first_not_of( delimiters ) );
}

//removes blank spaces from back of string
string& Intellisense::trim_right_inplace( string& s, const string& delimiters)
{
	return s.erase( s.find_last_not_of( delimiters ) + 1 );
}

//removes blank spaces from front and back of string
string& Intellisense::trim(string& s ,const string& delimiters )
{
	return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
}


tm Intellisense::getDate(vector<string>& tokens)
{
	tm date;
	date.tm_hour=NULL;
	date.tm_min=NULL;
	date.tm_mday=NULL;
	date.tm_mon=NULL;
	date.tm_year=NULL;

	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		string checkString = it->c_str();
		if(checkString.size()==8)
		{
			if(isAllInt(checkString))
			{
				it=tokens.erase(it);
				date.tm_mday=atoi(checkString.substr(0,2).c_str());
				date.tm_mon=atoi(checkString.substr(2,2).c_str());
				date.tm_year=atoi(checkString.substr(4,4).c_str());
				return date=getTime(tokens,date);
			}
		} 
		if(checkString.size()==10)
		{
			if(checkString.at(2) == '\\' && checkString.at(5)=='\\'  || checkString.at(2) == '/' && checkString.at(5)=='/'  )
			{
				checkString=removeChar(checkString,"/\\");
				if(isAllInt(checkString))
				{
					it=tokens.erase(it);
					date.tm_mday=atoi(checkString.substr(0,2).c_str());
					date.tm_mon=atoi(checkString.substr(2,2).c_str());
					date.tm_year=atoi(checkString.substr(4,4).c_str());
					return date=getTime(tokens,date);
				}
			}
		}

		if(tokens.size()>=3)
		{
			int check=checkDateString(checkString);

			if(check !=-1)
			{   cout<<it->c_str()<<endl;
			it--;
			vector<string>::iterator it_day = it++;
			vector<string>::iterator it_year = ++it;


			string day =it_day->c_str();
			if(day.size()>2 || day.size()<=0 || !isAllInt(day))
			{
				return date=getTime(tokens,date);
			}
			string year = it_year->c_str();
			if(year.size()!=4 || !isAllInt(year))
			{
				return date=getTime(tokens,date);
			}
			if(atoi(day.c_str())<=0 || atoi(year.c_str())<=0)
			{

				return date=getTime(tokens,date);
			}
			int month = check;


			it_day=tokens.erase(it_day);
			it_day=tokens.erase(it_day);
			it_day=tokens.erase(it_day);

			it=it_day;

			date.tm_mday=atoi(day.c_str());
			date.tm_mon=month;
			date.tm_year=atoi(year.c_str());
			return date=getTime(tokens,date);


			}
		}




	}
	return date=getTime(tokens,date);

}


int Intellisense::checkDateString(string token)
{
	for(int i=0;i<=11;++i)
	{
		if(checkString(token,months[i]))
		{
			return i+1;
		}
	}

	return -1;
}


string Intellisense::getEventName(vector<string>& tokens)
{
	stringstream ss;
	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		ss<<it->c_str()<<string(" ");
	}

	return ss.str();
}

void Intellisense::itTest(vector<string> tokens)
{


	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		cout<<it->c_str();


	}


	cout<<endl;
}

bool Intellisense::isAllInt(const string& s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') ) return false;
	}
	return true;
}

vector<string> Intellisense::tokenize(string command)
{
	vector<string> token;
	char *cstr, *p;

	string str = command;
	cstr = new char [str.size()+1];
	strcpy(cstr, str.c_str());

	p=strtok (cstr," ");
	while (p!=NULL)
	{
		token.push_back(p);
		p=strtok(NULL," ");
	}
	delete[] cstr;


	return token;
}

Action Intellisense::addOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"ADD"));
	task.setPriority(getPriority(tokens));
	task.setStartDate(getDate(tokens));
	task.setCategory(getCategory(tokens));
	task.setEventName(getEventName(tokens));
	setAllStatusFlag(task);
	checkAddReq();
	smartAutoFill(task);//auto fill some of the fields that are unentered
	return task;
}
Action Intellisense::deleteOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"DELETE"));
	task.setEventName(getEventName(tokens));
	setAllStatusFlag(task);
	checkDelReq();

	return task;
}
Action Intellisense::exitOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"EXIT"));

	return task;

}
Action Intellisense::displayOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"DISPLAY"));
	task.setStartDate(getDate(tokens));
	setAllStatusFlag(task);
	checkDspReq();

	return task;
}
Action Intellisense::markOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"MARK"));
	task.setStartDate(getDate(tokens));
	task.setEventName(getEventName(tokens));
	setAllStatusFlag(task);
	checkMarkReq();

	return task;
}
Action Intellisense::invalidOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"INVALID"));
	setAllStatusFlag(task);

	return task;
}
Action Intellisense::sortOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"SORT"));

	return task;
}
Action Intellisense::findOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"FIND"));
	task.setPriority(getPriority(tokens));
	task.setStartDate(getDate(tokens));
	task.setEventName(getEventName(tokens));
	setAllStatusFlag(task);
	checkFindReq();

	return task;
}

Action Intellisense::editOperation(vector<string>& tokens)
{
	Action task;
	task.setCommand(getCommand(tokens,"EDIT"));
	task.setPriority(getPriority(tokens));
	task.setStartDate(getDate(tokens));
	task.setEventName(getEventName(tokens));
	setAllStatusFlag(task);//i have to set my own flag and add the two string into the action flag
	checkEditReq();

	return task;
}



void Intellisense::setAllStatusFlag(Action task)
{
	if(task.getEventName() == "" )
		setStatusFlagAt(INAME,false);
	else
		setStatusFlagAt(INAME,true);

	bool isDateNotSet;
	isDateNotSet = (task.getStartDate().tm_year == 0	&& 
		task.getStartDate().tm_mon	== 0   && 
		task.getStartDate().tm_mday == 0);
	if(isDateNotSet)
		setStatusFlagAt(IDATE,false);
	else
		setStatusFlagAt(IDATE,true);

	if(task.getPriority() == "LOW" )
		setStatusFlagAt(IPRIORITY,false);
	else
		setStatusFlagAt(IPRIORITY,true);


	if(task.getCategory() == "")
		setStatusFlagAt(ICATEGORY,false);
	else
		setStatusFlagAt(ICATEGORY,true);
}
void  Intellisense::getAllStatusFlag(bool *flags)
{
	for (int i=0;i<MAXNOOFPARAMETERS;i++)
	{
		flags[i] = statusFlags[i];;
	}
}

bool Intellisense::getStatusFlagAt(int index)
{
	return statusFlags[index];
}
void Intellisense::setStatusFlagAt(int index,bool flag)
{
	statusFlags[index] = flag;
}
bool Intellisense::getrequirementsMet()
{
	return requirementsMet;
}
void Intellisense::setRequirementsMet(bool req)
{
	requirementsMet = req;
}

void Intellisense::checkAddReq()
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
}

void Intellisense::checkDelReq()
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
}
void Intellisense::checkDspReq()
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
void Intellisense::checkMarkReq()	
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
void Intellisense::checkFindReq()	
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
void Intellisense::checkEditReq()	
{
	if (statusFlags[INAME])
	{
		requirementsMet = true;
	}
}

string Intellisense::getFeedback()
{

	return _feedback;
}
void Intellisense::setFeedback(string newFeedback)
{
	_feedback=newFeedback;
}

string Intellisense::getParameter()
{// output the string based on the flags set
	if(statusFlags[INAME])
	{
		_parameter ="<font color=green>[NAME]</font>";
	}
	else
	{
		_parameter ="<font color=red>[NAME]</font>";
	}
	if(statusFlags[IDATE])
	{
		_parameter =_parameter + "<font color=green>[IDATE]</font>";
	}
	else
	{
		_parameter =_parameter + "<font color=red>[IDATE]</font>";
	}
	if(statusFlags[IPRIORITY])
	{
		_parameter =_parameter + "<font color=green>[IPRIORITY]</font>";
	}
	else
	{
		_parameter =_parameter + "<font color=red>[IPRIORITY]</font>";
	}
	if(statusFlags[ICATEGORY])
	{
		_parameter =_parameter + "<font color=green>[ICATEGORY]</font>";
	}
	else
	{
		_parameter =_parameter + "<font color=red>[ICATEGORY]</font>";
	}


	return _parameter;
}
void Intellisense::setParameter(string newParameter)
{
	_parameter = newParameter;
}

void Intellisense::smartAutoFill(Action &task)
{
	bool isDateNotentered = (task.getStartDate().tm_year == 0 && task.getStartDate().tm_mon == 0 && task.getStartDate().tm_mday ==0);
	if (isDateNotentered)
	{//we auto fill in todays day if date is unentered
		//
		time_t timeNow;
		struct tm * timeinfo;
		time (&timeNow);
		timeinfo = localtime ( &timeNow );
		timeinfo->tm_year+=1900;//add 1900 years to fit our format
		timeinfo->tm_mon+=1; //to fit our format
		if(task.getStartDate().tm_hour==0 && task.getStartDate().tm_min==00)
		{task.setStartDate(*timeinfo);}
		else
		{
			task.setStartDateWithoutTime(*timeinfo);
		}
		
	}
}