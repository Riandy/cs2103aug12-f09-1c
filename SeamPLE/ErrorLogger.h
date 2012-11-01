#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include <ctime>
#include <string>
#include <fstream>

using namespace std;

class ErrorLogger
{
private:
    static ErrorLogger* _logger;

private:
    ErrorLogger();

    ~ErrorLogger();

    bool singleInstanceExists();

    string getDateTime();

public:
    ErrorLogger* getInstance();

    void endInstance();

    void report(string error);

    void resetErrorLog();

};

#endif // ERRORLOGGER_H
