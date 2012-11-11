#include "Sframe.h"

//@WEIYUAN A0086030R

Sframe::Sframe(QWidget *parent)
    : QFrame(parent)
{
    //Following line enables drag and drop events for application
    setAcceptDrops(true);
}

//Function is called to save the different items of the screen when
//the left mouse button is depressed while the cursor over the frame
void Sframe::mousePressEvent(QMouseEvent *event)
{
    bool leftMouseButtonClicked = ((event->buttons() & Qt::LeftButton));

    //Only triggers when left mouse is clicked
    if (leftMouseButtonClicked)
    {
        _dragStartCursorPosition = event->globalPos();
        _bufferPosition = this->geometry();
    }
    QFrame::mousePressEvent(event);
}

//Function is called to move the frame when the left button is clicked
//while the cursor is over the frame and the cursor is moved
void Sframe::mouseMoveEvent(QMouseEvent *event)
{
    bool leftMouseButtonClicked = ((event->buttons() & Qt::LeftButton));
    bool movedMinimumReqDist =
            ((event->pos() - _dragStartCursorPosition).manhattanLength()
             >= QApplication::startDragDistance());

    if (leftMouseButtonClicked && movedMinimumReqDist)
    {
        this->setGeometry(getPosX(event->globalX()),getPosY(event->globalY()),
                          this->width(),this->height());
    }
    QFrame::mouseMoveEvent(event);
}

//Get the integer x coordinate for the application given the ammount of
//distance dragged by the cursor
int Sframe::getPosX(int cursorPosX)
{
    return cursorPosX +(_bufferPosition.x()-_dragStartCursorPosition.x());
}

//Get the integer y coordinate for the application given the ammount of
//distance dragged by the cursor
int Sframe::getPosY(int cursorPosY)
{
    return cursorPosY +(_bufferPosition.y()-_dragStartCursorPosition.y());
}
