#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include <ctime>
#include <string>
#include <fstream>

//@LIU WEIYUAN A0086030R

//This class is to be used for logging of errors. As this class is a
//singleton, a pointer is needed to be created for this class. Call
//getInstance to get address of the instance and endInstance to remove
//the instance.
//Important function for reporting error is the report function, where
//the error is returned as a string for writing into the log.

using namespace std;

class ErrorLogger
{
private:
    static ErrorLogger* _logger;

    const static string ERROR_TEXT_FILE;
    const static string ERROR_LOG_PRE_MESSAGE;
    const static string ERROR_TEXT_BARRIERS;


private:
    bool singleInstanceExists();
    string getDateTime();

public:
    ErrorLogger* getInstance();
    void endInstance();
    void report(string error);
    void resetErrorLog();

};

#endif // ERRORLOGGER_H
