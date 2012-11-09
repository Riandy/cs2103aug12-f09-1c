#include "SLineEdit.h"

//Set memory position to be NON_EXISTENT since initially there
//is no command save in the memory
int SLineEdit:: _memPos = NON_EXISTENT;

QVector <QString> SLineEdit:: _commandMem;

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

void SLineEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == ENTER)
    {
        if (_commandMem.size() >= FULL)
        {
            _commandMem.pop_back();
        }
        _commandMem.push_front(text());
        _memPos = DEFAULT;
    }
    else if (positionIsSet())
    {
        bool inMemoryRange = _memPos < _commandMem.size() - 1;

        if (event->key() == UP && inMemoryRange)
        {
            _memPos++;
            setText(_commandMem[_memPos]);
            emit textEdited(text());
        }
        else if (event->key() == DOWN && _memPos > EMPTY)
        {
            _memPos--;
            setText(_commandMem[_memPos]);
            emit textEdited(text());
        }
    }

    QLineEdit::keyPressEvent(event);
}

bool SLineEdit::positionIsSet()
{
    return (_memPos != NON_EXISTENT);
}
