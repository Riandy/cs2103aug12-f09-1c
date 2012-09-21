#include <iostream>
#include <string>

#include "Intellisense.h"
using namespace std;

int main()
{
    //Funny comment
	action response;//response from intellisense
	Intellisense intellisense;
	string userInput;
	//userInput = "add\tlala\t12122012\tH";
	userInput = "aDD\tBirthday Celebration\t01231990\tk\n";
	response = intellisense.check(userInput);
	cout <<"Status code: " << response.status << endl;
	cout <<"Event name: "<< response.name << endl;
	cout <<"Date: "<< response.date << endl;
	cout <<"priority: "<< response.priority << endl;
	//for now assumption is user have to follow a seqence to input
	//this will simulate the gui display to the user
	system("pause");
	return 0;
}
