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


static string _DELETE = "delete";
static string _ADDITION = "add";
static string _EDIT = "edit";
static int NOTFOUND = -1;

class calender
{
public:

private:


    vector<task> _storage;
    bool writeFile();
    bool loadFile();
    stack<string> _history;
    stack <task> _deleteHistory;
    stack <task> _editHistory;
    // for redo bro.
    stack<task> _redoHistory;
	stack<string> _redoCommands;

    void saveDelete(int taskID);
    void saveEdit();
    void saveHistory(string command);
public:

    calender();
    ~calender();

    bool addItem(task currentTask);
    bool deleteItem(int taskID);
    bool deleteItem(string eventName);
    bool checkID(int id);
    bool editTask(task edited);
    bool undoAction();
    bool redoAction();
    vector<task> SearchByCat(string searchItem);
    vector<task> SearchByTask(string searchItem);
    vector<task> SearchByDate(string todayDate);
    vector<task> displayDatabase();
    vector<task> getToday();
	int getTaskID(string searchItem);

    //implement the convert to date
    string convertToDate(tm _date);

};
#endif
