#ifndef SFRAME_H
#define SFRAME_H

#include <QFrame>
#include <QMouseEvent>
#include <QApplication>


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

    QPoint dragStartCursorPosition;
    QRect bufferPosition;

};
#endif
