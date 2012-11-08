#include "SLineEdit.h"

#include <QDebug>

//Set memory position to be -1, which will be checked as the
//inexistent position
int SLineEdit:: _memPos = -1;

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

//void SLineEdit::keyPressEvent(QKeyEvent *event)
//{
//    if (event->key() == ENTER)
//    {
//        if (_commandMem.size() >= FULL)
//        {
//            _commandMem.pop_front();
//        }
//        _commandMem.push_back(text());
//        _memPos = 0;
//    }

//    if (positionIsSet())
//    {
//        if (event->key() == UP)
//        {
//            if (_memPos < FULL - 1)
//            {
//                _memPos++;
//            }
//            setText(_commandMem[_memPos]);
//        }
//        else if (event->key() == DOWN)
//        {
//            qDebug() << "I AM HERE";
//            if (_memPos > EMPTY)
//            {
//                _memPos--;
//            }
//            setText(_commandMem[_memPos]);
//        }
//    }

//    QLineEdit::keyPressEvent(event);
//}

bool SLineEdit::positionIsSet()
{
    return (_memPos != -1);
}
