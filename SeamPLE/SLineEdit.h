#ifndef SLINEEDIT_H
#define SLINEEDIT_H

#include <QLineEdit>
#include <QFocusEvent>

//@WEIYUAN A0086030R

//This class is an overwritten class for the line edit component of the
//GUI class. It has additional functions to assist the focus setting
//and getting of the input bar. It also has additional functions to imitate
//the CLI with the access of past commands by pressing up or down
enum LineEdit_Code
{
    NON_EXISTENT = -2,
    DEFAULT = -1,
    EMPTY = 0,
    FULL = 10,
    ENTER = 16777220,
    UP = 16777235,
    DOWN = 16777237
};

class SLineEdit  : public QLineEdit
{
public:
    SLineEdit(QWidget *parent);

    bool getFocusInput();

    void setFocusInput(bool focus);

protected:
    void focusInEvent(QFocusEvent *);

    void focusOutEvent(QFocusEvent *);

    void keyPressEvent(QKeyEvent *);

    bool positionIsSet();

protected:
    bool _inputBarHasFocus;

    static QVector <QString> _commandMem;

    static int _memPos;
};
#endif // SLINEEDIT_H
