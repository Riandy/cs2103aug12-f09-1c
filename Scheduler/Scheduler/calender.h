#ifndef CALENDER_H
#define CALENDER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include "task.h"
#include <stack>

using namespace std;

class calender
{
public:

private:

	int _numberTasks;
	vector<task> _storage;
	bool writeFile();
	bool loadFile();
	stack<task> _history;
	task _lastUndo[1];
	
public:
	
calender();
~calender();

bool addItem(task currentTask); 
bool deleteItem(int taskID); 
bool checkID(int id); 
bool editTask(task edited); 
bool undoAction();
bool redoAction();
vector<task> SearchByCat(string searchItem); 
vector<task> SearchByTask(string searchItem); 
vector<task> displayDatabase(); 
vector<task> getToday();

//implement the convert to date
string convertToDate(tm _date);

};
#endif