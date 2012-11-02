#ifndef	INTELLISENSE_H
#define INTELLISENSE_H
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "ndebug.h"
#include "ErrorLogger.h"


#include "Action.h"

using namespace std;

struct imptDate
{
    string name;
    string date;
    imptDate(string _name,string _date):name(""),date(""){name=_name;date=_date;}
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
    INVALID,
    UNDO,
    REDO,
    EDITENTER
};




class Intellisense
{
private:

    static bool instanceFlag;
    static Intellisense *intellisense;



    Intellisense(void);
    static const string months[12];

    //    added array support for commands

    const static string addCommandArray[];
    const static string deleteCommandArray[];
    const static string markCommandArray[];
    const static string displayCommandArray[];
    const static string exitCommandArray[];
    const static string sortCommandArray[];
    const static string findCommandArray[];
    const static string editCommandArray[];
    const static string undoCommandArray[];
    const static string redoCommandArray[];

    const static string EMPTYCATEGORY;
    const static string EMPTYEVENT;
    const static string EMPTYPRIORITY;
    const static int    EMPTYID;

    const static string HIGHPRIORITY;
    const static string HIGHPRIORITY_L;
    const static string WEEKLY;
    const static string MONTHLY;
    const static string FORTNIGHTLY;

    const static string ADDFEEDBACK_1;
    const static string ADDFEEDBACK_2;
    const static string EDITFEEDBACK_1;
    const static string EDITFEEDBACK_2;
    const static string DELFEEDBACK_1;
    const static string DELFEEDBACK_2;
    const static string EXITFEEDBACK_1;
    const static string DISPLAYFEEDBACK_1;
    const static string DISPLAYFEEDBACK_2;
    const static string FINDFEEDBACK_1;
    const static string FINDFEEDBACK_2;
    const static string SORTFEEDBACK_1;
    const static string SORTFEEDBACK_2;
    const static string REDOFEEDBACK_1;
    const static string UNDOFEEDBACK_1;
    const static string MARKFEEDBACK_1;
    const static string MARKFEEDBACK_2;

    const static string GREENEVENTTEXT;
    const static string GREENSTARTDATETEXT;
    const static string GREENENDDATETEXT;
    const static string GREENPRIORITYTEXT;
    const static string GREENCATEGORYTEXT;
    const static string GREENIDTEXT;

    const static string REDEVENTTEXT;
    const static string REDSTARTDATETEXT;
    const static string REDENDDATETEXT;
    const static string REDPRIORITYTEXT;
    const static string REDCATEGORYTEXT;
    const static string REDIDTEXT;
    const static char CATEGORYRECOGNISER;
        //end of added array support for commands
    bool statusFlags[MAXNOOFPARAMETERS];
    bool requirementsMet;
    string _feedback;
    string _parameter;
    int currentCommand;

public:
    static Intellisense* getInstance();


    ~Intellisense(void);
    Action check(string query);
    string getOperation(vector<string>& tokens);
    tm getDate(vector<string>& tokens);
    tm getImptDate(string _date);
    string getEventName(vector<string>& tokens);
    int getID(vector<string>& tokens);
    string getCommand(vector<string>& tokens, string _command);
    string getCategory(vector<string>& tokens);
    string getPriority(vector<string>& tokens);
    int getDateType(vector<string>& tokens);
    tm getTime(vector<string>& tokens, tm date);
    string getAddFeedBack();
    string getEditFeedBack();
    string getDeleteFeedBack();
    string getExitFeedBack();
    string getDisplayFeedBack();
    string getFindFeedBack();
    string getSortFeedBack();
    string getRedoFeedBack();
    string getUndoFeedBack();
    string getMarkFeedBack();
    string getFeedback();
    void setFeedback(string);

    string getParameter();
    void setParameter(string);


    bool getrequirementsMet();
    void setRequirementsMet(bool);



private:
    vector<string> tokenize(string command);
    ErrorLogger *logger;
    bool isAllInt(const string& s );
    operation determinOperation(vector<string>& tokens);
    string getfirst_Word(string command);
    bool checkString(const string& input, const string& command);
    bool checkCommandArray(const string& input, const string command[], int arraySize);
    int checkMonthByString(string token);
    string removeChar(string s,char chars[]);
    string& trim(string& s , const string& delimiters = " \f\r\t\v");
    string& trim_right_inplace( string& s, const string& delimiters=" \f\r\t\v");
    string& trim_left_inplace( string& s,  const string& delimiters=" \f\r\t\v");
    string toLowerString(string);
    Action addOperation(vector<string>& tokens);
    Action deleteOperation(vector<string>& tokens);
    Action exitOperation(vector<string>& tokens);
    Action displayOperation(vector<string>& tokens);
    Action markOperation(vector<string>& tokens);
    Action quickAddOperation(vector<string>& tokens);
    Action sortOperation(vector<string>& tokens);
    Action findOperation(vector<string>& tokens);
    Action editOperation(vector<string>& tokens);
    Action undoOperation(vector<string>& tokens);
    Action redoOperation(vector<string>& tokens);

    bool getStatusFlagAt(int);
    void setStatusFlagAt(int,bool);

    void setAllStatusFlag(Action task); //this is based on the task that is passed in
    void getAllStatusFlag(bool *);//change the actual flag array passed in

    //check whether parameters supplied met the minimum requirement for command to be valid
    void checkAddReq();
    void checkDelReq();
    void checkDspReq();
    void checkMarkReq();
    void checkFindReq();
    void checkEditReq();
    void checkExitReq();
    void initFlags();






    bool isValidParaForCmd(int,int);
    void smartAutoFill(Action &task);


};


#endif
