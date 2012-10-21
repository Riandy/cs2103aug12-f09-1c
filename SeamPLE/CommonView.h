#ifndef COMMONVIEW_H
#define COMMONVIEW_H

#include <QDesktopWidget>
#include "GuiShortcuts.h"
#include "SLineEdit.h"

enum InputBarFlag{NONE, LOGICAL, UNOPERATIVE};

class CommonView
{
protected:
    const static QString STYLESHEET_INPUT_LINE_BORDER_RADIUS;
    const static QString STYLESHEET_INPUT_LINE_BORDER_STYLE;
    const static QString STYLESHEET_INPUT_LINE_BORDER_WIDTH;
    const static QString STYLESHEET_INPUT_LINE_BORDER_COLOR;
    const static QString STYLESHEET_INPUT_LINE_BACKGROUND_COLOR;

public:
    CommonView();

protected:
    GuiShortcuts _allShortcuts;

};


#endif // COMMONVIEW_H
