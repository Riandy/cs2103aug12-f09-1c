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

    /*
    Our Undo and redo operations rely on stacks to fulfill the functionality.
    This is based on the fact that undo and redo are first in, last out operations.
    We use two functions to operate on the stacks so that the size never becomes
    greater than 3.
    */
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


    void writeBackupFile();

    void saveToStack(stack<task>& thisStack, task thisTask);
    void saveStringToStack(stack<string>& thisStack, string thisString);
    void saveIntToStack(stack<int>& thisStack, int thisInt);

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
    vector<task> loadFile(char* fileName);
    bool fileExists(const char* fileName);

    bool archivePastEvent();


    static bool taskDateComparator(task task1,task task2);
    static bool dateComparator(tm date1,tm date2);

    vector<task> SearchPastEvent();
    string ensureUniqueName(string _name);

public:

    calender();
    ~calender();

    const static int DATENORMAL;
    const static int DATEWEEKLY;
    const static int DATEFORTNIGHTLY;
    const static int DATEMONTHLY;

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
    vector<task> displayArchiveEvent();
    vector<task> getToday();
    vector<task> SortByEvent();
    void SortByDate();
    vector<task> SortByCategory();
    string convertToDate(tm _date);
    bool updateRecurringEvents();
    int daysInAMonth(int year,int month);
    void updateDate(int num,tm &date);
    void updateMonth(int num,tm &date);
    void updateWeekly(task &event);
    void updateFortnightly(task &event);
    void updateMonthly(task &event);
};
#endif
