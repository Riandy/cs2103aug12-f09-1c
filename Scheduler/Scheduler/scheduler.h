#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "calender.h"
#include <sstream>
#include "Action.h"

// Ensure that this error is synchronous with the errors sent from Intellisense.
static string ERROR_NOT_FOUND = "Error - The item does not exist.";
static string ERROR_INTELLISENSE_CHECK = "Error - The system failed to process your request. Please try again";
static string ADD_SUCCESS = "Your event was added successfully.";
static string DELETE_SUCCESS = "Your event was deleted successfully";
static string EDIT_SUCCESS = "Your event was edited successfully";
static string UNDO_SUCCESS = "Undo operation was successful";
static string UNDO_FAILURE = "Undo operation was unsuccessful";
static string REDO_SUCCESS = "Redo operation was successful";
static string REDO_FAILURE = "Redo operation was unsuccessful";


class scheduler
{
private:
	vector<string> _result;
	vector<task> taskVector;
	calender eventCalender;
	void convertToString(vector<task> taskVector);
	void generalError();
	string convertToDate(tm _date);
public:
	scheduler();
	~scheduler();
	vector<string> executeCommand(Action newaction);

	//pass in action
};


#endif