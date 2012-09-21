#include "Intellisense.h"
#include <vector>
//to be done  date processing 
//priority processing
Intellisense::Intellisense(void)
{
}


Intellisense::~Intellisense(void)
{
}

//bool isLastCharNewLine(istringstream &buffer);//move this to header file later
bool isLastCharNewLine(string buffer);//move this to header file later
char toLower(char in);
int checkDate(string date);
char checkPriority(string priority);
action Intellisense::check(string query)
{//convert to lower case for command words
	string command;
	string task;
	string date;
	string priority;

	action raction;
	raction.date = 0;
	raction.name = "";
	raction.priority  = '\0';//default is null
	raction.status = 0;// status code

	bool lastCharNewLine;
	lastCharNewLine = isLastCharNewLine(query);
	if(lastCharNewLine)
	{//discard the newline at the end of command if any
		//cout<<"query before Erase: "<<query<<endl;
		string::iterator it;
		it = query.end()-1;
		//cout<<"LAST CHAR is newline"<<endl;
		query.erase(it); //extract and discard the newline
		//cout<<"query after Erase: "<<query<<endl;
	}

	istringstream buffer(query);//using of stringstream to extract till tab or newline is found signalling command sending
								//how bout we return error code as well as the string to display to user?
	cout <<"testing query:"<<buffer.str()<<endl;
	

	//buffer.clear();//reset
	//buffer.str("");//reset
	//Extraction of Command
	//working splitting
	/*vector<string> tokens;
	char split_char = '\t';
	for (string each; getline(buffer, each, split_char); tokens.push_back(each));

	for(int i =0;i<tokens.size();i++)
	{
		cout<<tokens[i]<<endl;
	}*/
	//end of working splitting

	getline(buffer,command,'\t');
	cout<<"extracted command:"<<command<<endl;
	//Process Command words
	transform (command.begin(), command.end(), command.begin(),toLower);// change the command to all lower case
	if(command == "-a" || command =="add")//only 2 format right now
	{
		//by right we can extract all the optional fields here even if it is unentered
		getline(buffer,task,'\t');
		cout<<"extracted task:"<<task<<endl;
		getline(buffer,date,'\t');
		cout<<"extracted date:"<<date<<endl;
		getline(buffer,priority,'\t');
		cout<<"extracted priority:"<<priority<<endl;
		//end of extraction of all fields

		int processedDate = checkDate(date);

		if( processedDate == FORMATINVALIDDATE )
		{
			raction.status = ERR_ADD_D;
		}
		else
		{
			raction.date = processedDate;//set the valid date in
			raction.status = VALIDADD;// can add in already even without priority
			if(priority != "")//if got priority entered
			{
				//check priority here
				cout<<"got priority:"<<priority<<endl;
				//then do priority check
				char pcheck = checkPriority(priority);
				if ( pcheck == '\0')
				{//invalid priority
					raction.status = ERR_ADD_P;
					cout<<"INVALID PRIORITY"<<endl;
				}
				else
				{
					raction.priority = pcheck;
				}

			}
			else
			{
				cout<<"No priority entered"<<endl;
			}
		}

	}
	else if(command == "-e" || command =="edit")
	{
	
	}
	else if(command == "-d" || command =="del")
	{
	
	}
	else if(command == "-f" || command =="find")
	{
	
	}
	else if(command == "dsp" )
	{
	
	}
	else if(command == "mark" )
	{
	
	}
	else
	{//invalid command or unrecognise command
		raction.status = INVALIDCOMAND;
	}
	//if invalid command words straight away return

	//end of Process of command words



	//End of Extraction of command

	return raction;

}
/*bool isLastCharNewLine(istringstream &buffer)
{
	bool lastCharNewLine = false;
	int length;
	char lastChar;
	buffer.seekg(0,ios::end);
	length = buffer.tellg();
	buffer.seekg(length-1,ios::beg);
	lastChar = buffer.peek();//get the last character
	buffer.seekg(0,ios::beg);//move the pointer to the front
	if(lastChar == '\n')
		lastCharNewLine = true;
	else
		lastCharNewLine = false;

	cout<<
			//"LAST CHARACTER IS : "<<lastChar<<
			"lastchar newline flag: "<<lastCharNewLine<<endl;
	return lastCharNewLine;
}
*/
bool isLastCharNewLine(string buffer)
{
	if(buffer.back() =='\n')
		return true;
	else
		return false;
}
char toLower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
} 
int checkDate(string date)
{
	int processedDate;//in the format we discussed ddmmyyyy
	//this check is only done for version o.o.o.o.o.0.0.00.0.0.000.
	cout<<"date length: "<<date.length()<<endl;
	if(date.length() != 8)//need to upgrade this to capture 7 digit date and so on
	{
		processedDate = FORMATINVALIDDATE ;// we use 99999999 to represent  invalid date format
	}
	else
	{
		processedDate = 12122001;//processing to be done here
	}
	//hahaha check for the ddmmyyyy
	return processedDate;
}
char checkPriority(string priority)
{
	char flag;
	if (priority == "H" || priority == "h" )
		flag = 'H';
	else if (priority == "L" || priority == "l" ) 
		flag = 'L';
	else
		flag = '\0';//return null to indicate invalid
	cout<<"priority check results is:"<<flag<<endl;
	return flag;
}