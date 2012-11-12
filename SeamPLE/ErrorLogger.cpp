#include "ErrorLogger.h"

//@author: A0086030R
//Static pointer containing address of the single instance
ErrorLogger* ErrorLogger::_logger = NULL;

//The following string holds the name of the text file for writing the error
//log to. Change the string to redirect the logging to another file
const string ErrorLogger::ERROR_TEXT_FILE = "ErrorLog.txt";

//The following strings holds portions of messages that are logged into the
//error text file
const string ErrorLogger::ERROR_LOG_PRE_MESSAGE = "Error Log Resetted on : ";
const string ErrorLogger::ERROR_TEXT_BARRIERS = " | ";

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

//Delete the single instance of this class
void ErrorLogger::endInstance()
{
    if (singleInstanceExists())
    {
        delete _logger;
        _logger = NULL;
    }
}

//Log the error in a text file. Error string is appended to current
//contents of the file
void ErrorLogger:: report(string error)
{
    ofstream errorLog (ERROR_TEXT_FILE.c_str(), fstream::app);
    errorLog << getDateTime();
    errorLog << ERROR_TEXT_BARRIERS << error << ERROR_TEXT_BARRIERS;
    errorLog << endl << endl;
    errorLog.close();
}

//Reset the entire error log. A date will be indicated at the start
//of the file to show when the log was resetted
void ErrorLogger:: resetErrorLog()
{
    ofstream errorLog (ERROR_TEXT_FILE.c_str());
    errorLog << ERROR_LOG_PRE_MESSAGE << getDateTime();
    errorLog << endl << endl;
    errorLog.close();
}

