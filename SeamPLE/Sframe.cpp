#include "Sframe.h"

Sframe::Sframe(QWidget *parent)
    : QFrame(parent)
{
    setAcceptDrops(true);
}

void Sframe::mousePressEvent(QMouseEvent *event)
{
    //Only triggers when left mouse is clicked
    if (event->button() == Qt::LeftButton)
    {
        dragStartCursorPosition = event->globalPos();
        bufferPosition = this->geometry();
    }
}

void Sframe::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }

    if ((event->pos() - dragStartCursorPosition).manhattanLength()
         >= QApplication::startDragDistance())
    {
        this->setGeometry(getPosX(event->globalX()),getPosY(event->globalY()),
                          this->width(),this->height());
    }
}

int Sframe::getPosX(int cursorPosX)
{
    return cursorPosX +(bufferPosition.x()-dragStartCursorPosition.x());
}

int Sframe::getPosY(int cursorPosY)
{
    return cursorPosY +(bufferPosition.y()-dragStartCursorPosition.y());
}
