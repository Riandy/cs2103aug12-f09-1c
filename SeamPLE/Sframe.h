#ifndef SFRAME_H
#define SFRAME_H

#include <QFrame>
#include <QMouseEvent>
#include <QApplication>

//@LIU WEIYUAN A0086030R

//This class is for the customization of a frame element to allow
//the frame to be controlled and be moved around by the user. It is
//an overwritten class of QFrame
class Sframe : public QFrame
{
public:
    Sframe(QWidget *parent);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int getPosX(int cursorPosX);
    int getPosY(int cursorPosY);

    QPoint _dragStartCursorPosition;
    QRect _bufferPosition;

};
#endif
