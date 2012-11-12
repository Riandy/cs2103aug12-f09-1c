#include "SLineEdit.h"

//@LIU WEIYUAN: A0086030R

//Set memory position to be NON_EXISTENT since initially there
//is no command save in the memory
int SLineEdit:: _memPos = NON_EXISTENT;

//This vector is a static instance as all input bars have to reference
//to the same memory for displaying past commands
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

//Set a bool value in this overwritten inherited function
//to show that input bar has focus
void SLineEdit::focusInEvent(QFocusEvent *event)
{
    _inputBarHasFocus = true;
    QLineEdit::focusInEvent(event);
}

//Set a bool value in this overwritten inherited function
//to show that input bar has lost focus
void SLineEdit::focusOutEvent(QFocusEvent *event)
{
    _inputBarHasFocus = false;
    QLineEdit::focusOutEvent(event);
}

//Function filters the enter key, up arrow key and down arrow key
// from the user input. This is for implementing the memory of past
//commands entered into the inout bar.
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

//This function check if the user is allowed to press
//up and down to access past commands entered. User is denied
//access if no commands were entered yet.
bool SLineEdit::positionIsSet()
{
    return (_memPos != NON_EXISTENT);
}
