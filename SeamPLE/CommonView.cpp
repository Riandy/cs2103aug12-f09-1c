#include "CommonView.h"

//@WEIYUAN A0086030R
//Following will contain strings containing properties of the stylesheets for the
//input line of the GUI
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_RADIUS =
        "border-radius: 10px;";
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_STYLE =
        "border-style: ridge;";
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_WIDTH =
        "border-width: 4px;";
const QString CommonView::STYLESHEET_INPUT_LINE_BORDER_COLOR =
        "border-color: rgb(84, 84, 84);";
const QString CommonView::STYLESHEET_INPUT_LINE_BACKGROUND_COLOR =
        "background-color: rgb(170, 85, 0);";

//Following will contain strings that will be used by StandardView and SeampleView
//in triggering of the shortcuts
const QString CommonView:: COMMAND_UNDO = "undo";
const QString CommonView:: COMMAND_REDO = "redo";
const QString CommonView:: COMMAND_ADD = "add ";
const QString CommonView:: COMMAND_FIND = "find ";
const QString CommonView:: COMMAND_DISPLAY = "display";
const QString CommonView:: COMMAND_DELETE = "delete ";
const QString CommonView:: COMMAND_EDIT = "edit ";
const QString CommonView:: COMMAND_FIND_FLOAT = "find #F10AT";
const QString CommonView:: COMMAND_MARK = "mark ";
const QString CommonView:: COMMAND_TODAY = "today";

//Following will contain strings corresponding to error reports of both user interfaces
const string CommonView:: MESSAGE_ERROR_INVALID_COLOUR =
        "INVALID INPUT BAR COLOUR RETURNED";
const string CommonView:: MESSAGE_ERROR_INCOMPLETE_RESULTS =
        "INCOMPLETE SCHEDULER RESULTS RETURNED";

//Returns a boolean value on whether the Gui interfaces are in the
//midst of changing
bool CommonView::interfaceCurrentlyChanging()
{
    return _currentlyChanging;
}

//Returns a boolean value on whether the intefaces in StandardView
//are in the midst of a transistion
bool CommonView::screenCurrentlySliding()
{
    return _currentlySliding;
}
