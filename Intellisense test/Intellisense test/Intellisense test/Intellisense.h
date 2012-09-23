#ifndef	INTELLISENSE_H
#define INTELLISENSE_H
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

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



public:
	Intellisense(void);
	~Intellisense(void);
	Action check(string query);
	vector<string> tokenize(string command);
	string getOperation(vector<string>& tokens);
	int getDate(vector<string>& tokens);
	string getEventName(vector<string>& tokens);
	string getCommand(vector<string>& tokens, string _command);
	bool getPriority(vector<string>& tokens);
	bool isDate(const string& s );
	void itTest(vector<string> tokens);
	operation determinOperation(vector<string>& tokens);
	string getfirst_Word(string command);
	bool checkString(const string& input, const string& command);
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


};

#endif;