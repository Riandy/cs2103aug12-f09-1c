#ifndef SLINEEDIT_H
#define SLINEEDIT_H

#include <QLineEdit>
#include <QFocusEvent>

enum LineEdit_Code
{
    EMPTY = 0,
    FULL = 10,
    ENTER = 16777220,
    UP = 16777236,
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

    //void keyPressEvent(QKeyEvent *);

    bool positionIsSet();

protected:
    bool _inputBarHasFocus;

    static QVector <QString> _commandMem;

    static int _memPos;
};
#endif // SLINEEDIT_H
