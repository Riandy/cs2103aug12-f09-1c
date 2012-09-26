#include "stdafx.h"

#include <string>
#include <iostream>
#include "Intellisense.h"
#include "Action.h"

using namespace std;

void DisplayDate(tm date)
{   
	cout<<string("Date : ")<<date.tm_mday;
	cout<<string("/")<<date.tm_mon;
	cout<<string("/")<<date.tm_year;
	cout<<string(" , ");
	cout<<date.tm_hour<<string(":")<<date.tm_min<<endl;
}


void DisplayEvent(Action task)
{
	cout<<string("******************")<<endl;
    cout<<string("Command : ")<<task.getCommand()<<endl;
	DisplayDate(task.getStartDate());
	cout<<string("Priority : ")<<task.getPriority()<<endl;
	cout<<string("Event Name : ")<<task.getEventName()<<endl;
	cout<<string("Category : ")<<task.getCategory()<<endl;
	//cout<<string("Req Met : ")<<task.getrequirementsMet()<<endl;
	cout<<string("******************")<<endl;
}





int main()
{   Action response;
	Intellisense intellisense;
	string userInput;

	while(true)
	{
		cout<<"command: ";
		getline(cin,userInput);
		response=intellisense.check(userInput);
		DisplayEvent(response);
		cout<<string("Req Met : ")<<intellisense.getrequirementsMet()<<endl;
		cout<<string(" ")<<intellisense.getParameter()<<endl;
	}

	


	return 0;
}

