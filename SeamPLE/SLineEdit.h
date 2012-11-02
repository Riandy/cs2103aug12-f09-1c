#ifndef SLINEEDIT_H
#define SLINEEDIT_H

#include <QLineEdit>
#include <QFocusEvent>

class SLineEdit  : public QLineEdit
{
public:
    SLineEdit(QWidget *parent);

    bool getFocusInput();

    void setFocusInput(bool focus);

protected:
    void focusInEvent(QFocusEvent *);

    void focusOutEvent(QFocusEvent *);

    bool _inputBarHasFocus;
};
#endif // SLINEEDIT_H
