#ifndef COMMONVIEW_H
#define COMMONVIEW_H

#include <QDesktopWidget>
#include <QPropertyAnimation>
#include "ErrorLogger.h"
#include "GuiShortcuts.h"
#include "SLineEdit.h"

//@author: A0086030R

//This class contains the shared GUI items between SeampleView and
//StandardView. Items seen here are meant to be used by both user interfaces
//stated above

enum InputBarFlag
{
    NONE,
    LOGICAL,
    UNOPERATIVE
};

class CommonView
{
protected:
    const static QString STYLESHEET_INPUT_LINE_BORDER_RADIUS;
    const static QString STYLESHEET_INPUT_LINE_BORDER_STYLE;
    const static QString STYLESHEET_INPUT_LINE_BORDER_WIDTH;
    const static QString STYLESHEET_INPUT_LINE_BORDER_COLOR;
    const static QString STYLESHEET_INPUT_LINE_BACKGRD_COLOR;
    const static QString STYLESHEET_INPUT_LINE_LOGICAL_COLOR;
    const static QString STYLESHEET_INPUT_LINE_UNOPERATIVE_COLOR;
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
    const static QString MESSAGE_NIL;
    const static string ANIMATION_ATTRIBUTE;
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
