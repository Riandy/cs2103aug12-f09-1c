#include "SLineEdit.h"

//Set memory position to be -1, which will be checked as the
//inexistent position
int SLineEdit:: memPos = -1;

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

//void SLineEdit::keyPressEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_Enter)
//    {
//        if (commandMem.size() < MAX_SIZE)
//        {
//            commandMem.push_back(text());
//        }
//        memPos = 0;
//    }
//    else if (event->key() == Qt::UpArrow)
//    {
//        if (memPos < 9)
//        {
//            memPos++;
//            setText(commandMem[memPos]);
//        }
//    }
//    else if (event->key() == Qt::DownArrow)
//    {
//        if (memPos > 0)
//        {
//            memPos--;
//        }
//    }
//}
