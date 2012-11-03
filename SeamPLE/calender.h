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


class calender
{
public:

private:


    vector<task> _storage;
    ErrorLogger* _faulty;
    stack<string> _history;

	stack<string> _redoCommands;

    //used in add
    stack<string> _addHistory;
    stack<task> _redoHistory;
    // used in delete
     stack <task> _deleteHistory;
    //used in edit
    stack <task> _originalEdits;
    stack<task> _redoNewEdits;
    stack<task> _redoOriginalEdits;
    stack <task> _newEdits;

	bool checkNameExists(string _name);
    void saveDelete(int taskID);
	string ensureUniqueName(string _name);
    void saveHistory(string command);
	bool writeFile();
    bool loadFile();
    void undoOriginalEdits(task _oldtask);
    void undoNewEdits(task _newtask);
    void redoOriginalEdits(task _oldtask);
    void redoNewEdits(task _newtask);
    void saveAdd(string Item);


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
