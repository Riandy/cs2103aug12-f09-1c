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
        _dragStartCursorPosition = event->globalPos();
        _bufferPosition = this->geometry();
    }
    QFrame::mousePressEvent(event);
}

void Sframe::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }

    if ((event->pos() - _dragStartCursorPosition).manhattanLength()
            >= QApplication::startDragDistance())
    {
        this->setGeometry(getPosX(event->globalX()),getPosY(event->globalY()),
                          this->width(),this->height());
    }
    QFrame::mouseMoveEvent(event);
}

int Sframe::getPosX(int cursorPosX)
{
    return cursorPosX +(_bufferPosition.x()-_dragStartCursorPosition.x());
}

int Sframe::getPosY(int cursorPosY)
{
    return cursorPosY +(_bufferPosition.y()-_dragStartCursorPosition.y());
}
