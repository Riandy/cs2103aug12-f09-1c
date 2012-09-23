#include "stdafx.h"

#include <string>
#include <iostream>
#include "Intellisense.h"
#include "Action.h"

using namespace std;

void DisplayEvent(Action event)
{
	cout<<string("******************")<<endl;
	cout<<string("Command : ")<<event.getCommand()<<endl;
	cout<<string("Date : ")<<event.getDate()<<endl;
	cout<<string("Priority : ")<<event.getPriority()<<endl;
	cout<<string("Event Name : ")<<event.getEventName()<<endl;
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
		
	}

	


	return 0;
}

