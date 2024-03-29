#ifndef	INTELLISENSE_H
#define INTELLISENSE_H
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

#include "Action.h"
using namespace std;

enum operation{
	ADD,
	DELETE,
	MARK,
	DISPLAY,
	EXIT,
	SORT,
	FIND,
	EDIT,
	INVALID
};


class Intellisense
{
private:

	static const string addCommand;
	static const string deleteCommand;
	static const string markCommand;
	static const string displayCommand;
	static const string exitCommand;
	static const string sortCommand;
	static const string findCommand;
	static const string editCommand;
	static const string months[12];
	bool statusFlags[MAXNOOFPARAMETERS];
	bool requirementsMet;
	string _feedback;
	string _parameter;

public:
	Intellisense(void);
	~Intellisense(void);
	Action check(string query);
	vector<string> tokenize(string command);
	string getOperation(vector<string>& tokens);
	tm getDate(vector<string>& tokens);
	string getEventName(vector<string>& tokens);
	string getCommand(vector<string>& tokens, string _command);
	string getCategory(vector<string>& tokens);
	string getPriority(vector<string>& tokens);
	tm getTime(vector<string>& tokens, tm date);
	bool isAllInt(const string& s );
	void itTest(vector<string> tokens);
	operation determinOperation(vector<string>& tokens);
	string getfirst_Word(string command);
	bool checkString(const string& input, const string& command);
	int checkDateString(string token);
	string removeChar(string s,char chars[]);
	string& trim(string& s , const string& delimiters = " \f\r\t\v");
	string& trim_right_inplace( string& s, const string& delimiters=" \f\r\t\v");
	string& trim_left_inplace( string& s,  const string& delimiters=" \f\r\t\v");


	Action addOperation(vector<string>& tokens);
	Action deleteOperation(vector<string>& tokens);
	Action exitOperation(vector<string>& tokens);
	Action displayOperation(vector<string>& tokens);
	Action markOperation(vector<string>& tokens);
	Action invalidOperation(vector<string>& tokens);
	Action sortOperation(vector<string>& tokens);
	Action findOperation(vector<string>& tokens);
	Action editOperation(vector<string>& tokens);

	bool getStatusFlagAt(int);
	void setStatusFlagAt(int,bool);

	void setAllStatusFlag(Action task); //this is based on the task that is passed in
	void getAllStatusFlag(bool *);//change the actual flag array passed in

	bool getrequirementsMet();
	void setRequirementsMet(bool);

	//These functions below governs the validity  of whether the command can be processed by the main
	void checkAddReq();//check whether parameters supplied met the minimum requirement for command to be valid
	void checkDelReq();
	void checkDspReq();
	void checkMarkReq();
	void checkFindReq();
	void checkEditReq();

	void smartAutoFill(Action &task);
	string getFeedback();
	void setFeedback(string);

	string getParameter();
	void setParameter(string);

};

#endif;