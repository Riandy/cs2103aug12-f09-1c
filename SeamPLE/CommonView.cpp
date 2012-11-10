#include "CommonView.h"

//@WEIYUAN A0086030R
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

const QString CommonView:: COMMAND_UNDO = "undo";
const QString CommonView:: COMMAND_REDO = "redo";
const QString CommonView:: COMMAND_ADD = "add ";
const QString CommonView:: COMMAND_FIND = "find ";
const QString CommonView:: COMMAND_DISPLAY = "display";
const QString CommonView:: COMMAND_DELETE = "delete ";
const QString CommonView:: COMMAND_EDIT = "edit ";
const QString CommonView:: COMMAND_MARK = "mark ";
const QString CommonView:: COMMAND_TODAY = "today";
const QString CommonView:: COMMAND_FIND_FLOAT = "find #F10AT";

const string CommonView:: MESSAGE_ERROR_INVALID_COLOUR =
        "INVALID INPUT BAR COLOUR RETURNED";
const string CommonView:: MESSAGE_ERROR_INCOMPLETE_RESULTS =
        "INCOMPLETE SCHEDULER RESULTS RETURNED";

//CommonView::CommonView()
//{
//}

bool CommonView::interfaceCurrentlyChanging()
{
    return _currentlyChanging;
}

bool CommonView::screenCurrentlySliding()
{
    return _currentlySliding;
}
