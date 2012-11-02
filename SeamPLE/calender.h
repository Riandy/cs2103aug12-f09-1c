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
#include "ndebug.h"
#include "ErrorLogger.h"
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
    ErrorLogger* _faulty;
    stack<string> _history;
    stack <task> _deleteHistory;
    stack <task> _originalEdits;
	stack <task> _newEdits;
    stack<task> _redoHistory;
	stack<string> _redoCommands;
	bool checkNameExists(string _name);
    void saveDelete(int taskID);
	string ensureUniqueName(string _name);
    void saveHistory(string command);
	bool writeFile();
    bool loadFile();
	void saveOriginalEdits(task _oldtask);
	void saveNewEdits(task _newtask);
	int findVectorPosition(task _thisTask);
	void swapTops(task bufferTask);
public:

    calender();
    ~calender();

    bool addItem(task currentTask);
    bool deleteItem(int taskID);
    bool deleteItem(string eventName);
    bool checkID(int id);
    bool editTask(task _edited);
    bool undoAction();
    bool redoAction();
    vector<task> SearchByCat(string searchItem);
    vector<task> SearchByTask(string searchItem);
    vector<task> SearchByPartialTask(string searchItem);
    task* pointerSearchByTask(string searchItem);
    vector<task> SearchByDate(string todayDate);
    vector<task> displayDatabase();
    vector<task> getToday();
	int getTaskID(string searchItem);
    vector<task> SortByEvent();
    vector<task> SortByDeadline();
    vector<task> SortByCategory();

    //implement the convert to date
    string convertToDate(tm _date);

};
#endif
