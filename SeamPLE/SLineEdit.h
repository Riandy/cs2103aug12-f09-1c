#ifndef SLINEEDIT_H
#define SLINEEDIT_H

#include <QLineEdit>
#include <QFocusEvent>

#define MAX_SIZE 10

class SLineEdit  : public QLineEdit
{
public:
    SLineEdit(QWidget *parent);

    bool getFocusInput();

    void setFocusInput(bool focus);

protected:
    void focusInEvent(QFocusEvent *);

    void focusOutEvent(QFocusEvent *);

protected:
    bool _inputBarHasFocus;

    static QVector <QString> commandMem;

    static int memPos;
};
#endif // SLINEEDIT_H
