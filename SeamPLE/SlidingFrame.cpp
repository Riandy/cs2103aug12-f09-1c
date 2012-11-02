#include "SlidingFrame.h"


SlidingFrame::SlidingFrame(QWidget *parent)
    : QFrame(parent)
{
    _currentlySliding = false;
    _moveX = 0;
    _moveY = 0;
}


//void Sframe::mousePressEvent(QMouseEvent *event)
//{
//    //Only triggers when left mouse is clicked
//    if (event->button() == Qt::LeftButton)
//    {
//        _dragStartCursorPosition = event->globalPos();
//        _bufferPosition = this->geometry();
//    }
//    QFrame::mousePressEvent(event);
//}

//void Sframe::mouseMoveEvent(QMouseEvent *event)
//{
//    if (!(event->buttons() & Qt::LeftButton))
//    {
//        return;
//    }

//    if ((event->pos() - _dragStartCursorPosition).manhattanLength()
//            >= QApplication::startDragDistance())
//    {
//        this->setGeometry(getPosX(event->globalX()),getPosY(event->globalY()),
//                          this->width(),this->height());
//    }
//    QFrame::mouseMoveEvent(event);
//}

void SlidingFrame::placeSlideParameters(int coord, DirectionType direction, unsigned int countTime)
{
//    switch(direction)
//    {
//    case UP:
//        break;
//    case DOWN:
//        break;
//    }

    setUpTimer();

    for (int i = 0; i < countTime; i++)
    {

    }
}

bool SlidingFrame::isCurrentlySliding()
{
    return _currentlySliding;
}

void periodicMovement()
{

}

void SlidingFrame::slide(int addX, int addY)
{
    this->setGeometry(getPosX()+addX,getPosY()+addY,
                      this->width(),this->height());
}

void SlidingFrame::setUpTimer()
{
    connect(&_slideTimer,SIGNAL(timeout()), this, SLOT(periodicMovement()));
    _slideTimer.start(1);
}

void SlidingFrame::stopTimer()
{
    disconnect(&_slideTimer,SIGNAL(timeout()), this, SLOT(periodicMovement()));
}

int SlidingFrame::getPosX()
{
    return this->geometry().x();
}

int SlidingFrame::getPosY()
{
    return this->geometry().y();
}
