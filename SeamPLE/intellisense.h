#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct action
{

    string EventName;
    int Date;
    bool Priority;
    string Command;
};

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
    action check(string query);
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
    string& trim(string& s , const string& delimiters = " \f\n\r\t\v");
    string& trim_right_inplace( string& s, const string& delimiters=" \f\n\r\t\v");
    string& trim_left_inplace( string& s,  const string& delimiters=" \f\n\r\t\v");

    action addOperation(vector<string>& tokens);
    action deleteOperation(vector<string>& tokens);
    action exitOperation(vector<string>& tokens);
    action displayOperation(vector<string>& tokens);
    action markOperation(vector<string>& tokens);
    action invalidOperation(vector<string>& tokens);
    action sortOperation(vector<string>& tokens);
    action findOperation(vector<string>& tokens);
    action editOperation(vector<string>& tokens);


};
