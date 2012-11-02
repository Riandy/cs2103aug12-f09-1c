#ifndef SLIDINGFRAME_H
#define SLIDINGFRAME_H

#include <QFrame>
#include <QTimer>
#include <cmath>

class SlidingFrame : public QFrame
{
public:
    enum DirectionType
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    SlidingFrame(QWidget *parent);

    void placeSlideParameters(int coord, DirectionType direction,  unsigned int countTime);

    bool isCurrentlySliding();

private slots:
    void periodicMovement();

private:
    void slide(int addX, int addY);

    void setUpTimer();

    void stopTimer();

    int getPosX();

    int getPosY();

private:
    QTimer _slideTimer;

    bool _currentlySliding;

    int _moveX;

    int _moveY;

    double *frameMovement;
};

#endif // SLIDINGFRAME_H
