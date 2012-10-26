#include "SLineEdit.h"

SLineEdit::SLineEdit(QWidget *parent): QLineEdit(parent)
{
    _inputBarHasFocus = false;
}

bool SLineEdit::getFocusInput()
{
    return _inputBarHasFocus;
}

void SLineEdit::setFocusInput(bool focus)
{
    _inputBarHasFocus = focus;

    if (_inputBarHasFocus)
    {
        this->setFocus(Qt::OtherFocusReason);
    }
    else
    {
        this->clearFocus();
    }
}

void SLineEdit::focusInEvent(QFocusEvent *event)
{
    _inputBarHasFocus = true;
    QLineEdit::focusInEvent(event);
}

void SLineEdit::focusOutEvent(QFocusEvent *event)
{
    _inputBarHasFocus = false;
    QLineEdit::focusOutEvent(event);
}
