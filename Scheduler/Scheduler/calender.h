#ifndef CALENDER_H
#define CALENDER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;



class calender
{
public:
	struct task
	{
		string _description;
		int _startDate;
		int _endDate;
		string _priority; //HIGH OR LOW
		int _id;      
		string _category;
	
	};

private:
	



	int _numberTasks;
	vector<task> _storage;
	//ifstream infile;
	//ofstream outfile;



	bool writeFile();
	bool loadFile();


	
public:
	
calender();
~calender();

bool addItem(task currentTask); //done
bool deleteItem(int taskID); //done
bool searchID(int id); //done
bool editTask(task edited); //do later
vector<task> SearchByCat(string searchItem); //done
vector<task> SearchByTask(string searchItem); //done

vector<task> displayDatabase(); //done




//using a void here, because bool won't cut it, and I think we might need to think this 
//through.

void execute(string command, task currentTask);



};
#endif