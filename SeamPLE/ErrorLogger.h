#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include <ctime>
#include <string>
#include <fstream>

//@WEIYUAN A0086030R
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
