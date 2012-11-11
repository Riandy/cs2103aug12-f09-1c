#include "CommonView.h"

//@LIU WEIYUAN A0086030R
//Following will contain strings containing properties of the stylesheets for
//the input line of the GUI
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_RADIUS =
        "border-radius: 10px;";
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_STYLE =
        "border-style: ridge;";
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_WIDTH =
        "border-width: 4px;";
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_COLOR =
        "border-color: rgb(84, 84, 84);";
const QString CommonView::STYLESHEET_INPUT_LINE_BACKGRD_COLOR =
        "background-color: rgb(170, 85, 0);";
const QString CommonView::STYLESHEET_INPUT_LINE_LOGICAL_COLOR =
        "background-color: rgb(50,205,50);";
const QString CommonView::STYLESHEET_INPUT_LINE_UNOPERATIVE_COLOR =
        "background-color: rgb(255,99,71);";

//Following will contain strings that will be used by StandardView and
//SeampleView in triggering of the shortcuts
const QString CommonView:: COMMAND_UNDO = "undo";
const QString CommonView:: COMMAND_REDO = "redo";
const QString CommonView:: COMMAND_ADD = "add ";
const QString CommonView:: COMMAND_FIND = "find ";
const QString CommonView:: COMMAND_DISPLAY = "display";
const QString CommonView:: COMMAND_DELETE = "delete ";
const QString CommonView:: COMMAND_EDIT = "edit ";
const QString CommonView:: COMMAND_FIND_FLOAT = "todo";
const QString CommonView:: COMMAND_MARK = "mark ";
const QString CommonView:: COMMAND_TODAY = "today";

//Following will contain strings corresponding to error reports of both user
//interfaces. Note that the data type is string and not QString as the
//errorlogger class utilise strings to write into the error text file
const string CommonView:: MESSAGE_ERROR_INVALID_COLOUR =
        "INVALID INPUT BAR COLOUR RETURNED";
const string CommonView:: MESSAGE_ERROR_INCOMPLETE_RESULTS =
        "INCOMPLETE SCHEDULER RESULTS RETURNED";


bool CommonView::interfaceCurrentlyChanging()
{
    return _currentlyChanging;
}

bool CommonView::screenCurrentlySliding()
{
    return _currentlySliding;
}
