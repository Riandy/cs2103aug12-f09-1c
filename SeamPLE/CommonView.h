#ifndef COMMONVIEW_H
#define COMMONVIEW_H

#include <QDesktopWidget>
#include <QPropertyAnimation>
#include "ErrorLogger.h"
#include "GuiShortcuts.h"
#include "SLineEdit.h"

//@WEIYUAN A0086030R
enum InputBarFlag
{
    NONE,
    LOGICAL,
    UNOPERATIVE
};

class CommonView
{
protected:
    //Following will contain strings containing properties of the stylesheets for the
    //input line of the GUI
    const static QString STYLESHEET_INPUT_LINE_BORDER_RADIUS;
    const static QString STYLESHEET_INPUT_LINE_BORDER_STYLE;
    const static QString STYLESHEET_INPUT_LINE_BORDER_WIDTH;
    const static QString STYLESHEET_INPUT_LINE_BORDER_COLOR;
    const static QString STYLESHEET_INPUT_LINE_BACKGROUND_COLOR;

    //Following will contain strings that will be used by StandardView and SeampleView
    //in triggering of the shortcuts
    const static QString COMMAND_UNDO;
    const static QString COMMAND_REDO;
    const static QString COMMAND_ADD;
    const static QString COMMAND_FIND;
    const static QString COMMAND_DISPLAY;
    const static QString COMMAND_DELETE;
    const static QString COMMAND_EDIT;
    const static QString COMMAND_FIND_FLOAT;
    const static QString COMMAND_MARK;
    const static QString COMMAND_TODAY;

    //Following will contain strings corresponding to error reports of both user interfaces
    const static string MESSAGE_ERROR_INVALID_COLOUR;
    const static string MESSAGE_ERROR_INCOMPLETE_RESULTS;

public:
    bool interfaceCurrentlyChanging();
    bool screenCurrentlySliding();

protected:
    GuiShortcuts _allShortcuts;
    QPropertyAnimation *_animation;
    bool _currentlyChanging;
    bool _currentlySliding;
};


#endif // COMMONVIEW_H
