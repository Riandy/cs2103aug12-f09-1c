#ifndef CALENDER_H
#define CALENDER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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

    stack<string> _commandHistory;
    stack<string> _undoHistory;

    //used in add
    stack<string> _addHistory;
    stack<task> _undoneAddTasks;
    // used in delete
    stack <task> _deletedTasks;
    stack<string> _deleteHistory;
    //used in edit
    stack <task> _undoOriginalEdits;
    stack<task> _redoNewEdits;
    stack<task> _redoOriginalEdits;
    stack <task> _undoNewEdits;
    bool lastCommandUndo;


    void saveDeletedTask(int taskID);
    void saveHistory(string command);
    void undoOriginalEdits(task _oldtask);
    void undoNewEdits(task _newtask);
    void redoOriginalEdits(task _oldtask);
    void redoNewEdits(task _newtask);
    void saveAdd(string Item);
    void saveUndoneDelete(string Item);
    void writeBackupFile();

    void undoAdd();
    void undoDelete();
    bool undoEdit();
    void undoDeleteAll();

    void redoAdd();
    void redoDelete();
    bool redoEdit();
    void redoDeleteAll();
    bool archiveEvent(task markedTask);

    bool writeFile();
    bool loadFile(char* fileName);
    bool fileExists(const char* fileName);

    bool archivePastEvent();


    static bool taskDateComparator(task task1,task task2);
    static bool dateComparator(tm date1,tm date2);

    vector<task> SearchPastEvent();
    string ensureUniqueName(string _name);

public:

    calender();
    ~calender();
    bool checkNameExists(string _name);
    int getTaskID(string searchItem);
    bool addItem(task currentTask);
    bool deleteItem(int taskID);
    bool deleteItem(string eventName);
    bool checkID(int id);
    bool editTask(task _edited);
    bool undoAction();
    bool redoAction();
    bool markTask(task markedTask);
    bool deleteAll();
    string convertToDateNoTime(tm _date);
    vector<task> SearchByCat(string searchItem);
    vector<task> SearchByTask(string searchItem);
    vector<task> SearchByPartialTask(string searchItem);
    vector<task> getFloatingEvents();

    task* pointerSearchByTask(string searchItem);
    vector<task> SearchByDate(string searchDate);

    vector<task> displayDatabase();
    vector<task> getToday();
    vector<task> SortByEvent();
    void SortByDate();
    vector<task> SortByCategory();
    string convertToDate(tm _date);
};
#endif
