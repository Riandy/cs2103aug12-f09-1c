#include "ErrorLogger.h"

//Static pointer containing address of the single instance
ErrorLogger* ErrorLogger::_logger = NULL;

//Check if Singleton of ErrorLogger has been created yet
bool ErrorLogger::singleInstanceExists()
{
    bool result;

    if (_logger == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

//Getting string conversion of current date and time
string ErrorLogger:: getDateTime()
{
    time_t currTime;
    time(&currTime);

    return ctime(&currTime);
}


//Returns address of the Singleton ErrorLogger to the calling pointer
ErrorLogger* ErrorLogger::getInstance()
{
    if (!singleInstanceExists())
    {
        _logger = new ErrorLogger();
    }

    return _logger;
}

//Delete the single instance of the class
void ErrorLogger::endInstance()
{
    if (singleInstanceExists())
    {
        delete _logger;
        _logger = NULL;
    }
}

void ErrorLogger:: report(string error)
{
    ofstream write ("ErrorLog.txt", fstream::app);

    write << getDateTime();
    write << "| " << error << " |" << endl << endl;

    write.close();
}

void ErrorLogger:: resetErrorLog()
{
    ofstream writeLog ("ErrorLog.txt");

    writeLog << "Error Log Resetted on : " << getDateTime();
    writeLog << endl << endl;

    writeLog.close();
}
