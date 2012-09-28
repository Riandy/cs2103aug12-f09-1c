#ifndef CALENDER_H
#define CALENDER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;


class calender
{

private:
	struct task
	{
		string _description;
		int _startDate;
		int _endDate;
		int _priority;
		int _id;                      // Can you guys include this in the event? 
	};



	int _numberTasks;
	vector<task*> _storage;
	//ifstream infile;
	//ofstream outfile;


	bool addItem(task* currentTask);
	bool deleteItem(int taskID);

	bool writeFile();
	bool loadFile();


	
public:

calender();
~calender();

//using a void here, because bool won't cut it, and I think we might need to think this 
//through.

void execute(string command, task currentTask);



};
#endif