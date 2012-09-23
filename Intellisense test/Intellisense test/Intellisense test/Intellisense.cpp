#include "Intellisense.h"


const string Intellisense::addCommand ="add";
const string Intellisense::deleteCommand ="delete";
const string Intellisense::markCommand = "mark";
const string Intellisense::displayCommand= "display";
const string Intellisense::exitCommand = "exit";
const string Intellisense::sortCommand = "sort";
const string Intellisense::findCommand = "find";
const string Intellisense::editCommand = "edit";



Intellisense::Intellisense(void)
{
}


Intellisense::~Intellisense(void)
{
}

Action Intellisense::check(string query)
{
	Action event;
	
	trim(query);

	vector<string> buffer = tokenize(query);

	switch(determinOperation(buffer))
	{
	case ADD: 
		event=addOperation(buffer); 
		break;
	case DELETE: 
		event=deleteOperation(buffer);
		break;
	case DISPLAY: 
		event=displayOperation(buffer); 
		break;
	case MARK: 
		event=markOperation(buffer); 
		break;
	case SORT: 
		event=sortOperation(buffer); 
		break;
	case FIND: 
		event=findOperation(buffer); 
		break;
	case EDIT: 
		event=editOperation(buffer); 
		break;
	case EXIT: 
		event=exitOperation(buffer); 
		break;
	case INVALID: 
		event=invalidOperation(buffer); 
		break;
	default:
		break;
	}

	
	return event;
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


bool Intellisense::getPriority(vector<string>& tokens)
{
	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		string checkString = it->c_str();
		if((checkString.compare(string("HIGH"))==0) || checkString.compare(string("high"))==0)
		{
			it=tokens.erase(it);
			return true;
		}
	}

	return false;
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


int Intellisense::getDate(vector<string>& tokens)
{
	for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
	{
		string checkString = it->c_str();
		if(checkString.size()==8)
		{
			if(isDate(checkString))
			{
				
				it=tokens.erase(it);
				return atoi(checkString.c_str());
			}
		}
	}

	return 0;
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

bool Intellisense::isDate(const string& s)
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
	Action event;
	event.setCommand(getCommand(tokens,"ADD"));
	event.setPriority(getPriority(tokens));
	event.setDate(getDate(tokens));
	event.setEventName(getEventName(tokens));
	event.setCategory(getCategory(tokens));
	return event;
}
Action Intellisense::deleteOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"DELETE"));
	event.setEventName(getEventName(tokens));

	return event;
}
Action Intellisense::exitOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"EXIT"));

	return event;

}
Action Intellisense::displayOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"DISPLAY"));
	event.setDate(getDate(tokens));

	return event;
}
Action Intellisense::markOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"MARK"));
	event.setDate(getDate(tokens));
	event.setEventName(getEventName(tokens));

	return event;
}
Action Intellisense::invalidOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"INVALID"));

	return event;
}
Action Intellisense::sortOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"SORT"));

	return event;
}
Action Intellisense::findOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"FIND"));
	event.setPriority(getPriority(tokens));
	event.setDate(getDate(tokens));
	event.setEventName(getEventName(tokens));

	return event;
}

Action Intellisense::editOperation(vector<string>& tokens)
{
	Action event;
	event.setCommand(getCommand(tokens,"EDIT"));
	event.setPriority(getPriority(tokens));
	event.setDate(getDate(tokens));
	event.setEventName(getEventName(tokens));

	return event;
}