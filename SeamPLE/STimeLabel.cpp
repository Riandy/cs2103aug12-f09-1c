#include "STimeLabel.h"

//@author: A0086030R

STimeLabel::STimeLabel(QWidget *parent):
    QLabel(parent)
{
    setAutoDateAndTimeDisplay();
    this->setAlignment(Qt::AlignCenter);
}

STimeLabel::~STimeLabel()
{
    delete _interval;
    _dateAndTime->endInstance();
}

//This function sets the timer and values which is set to trigger every one
//second, resulting in the update in time every single second.
void STimeLabel::setAutoDateAndTimeDisplay()
{
    _dateAndTime = _dateAndTime->getInstance();
    _interval = new QTimer(this);
    connect(_interval, SIGNAL(timeout()),
            _dateAndTime, SLOT(getStringDateAndTime()));
    connect(_dateAndTime, SIGNAL(relayStringDateAndTime(QString)),
            this, SLOT(setText(QString)));
    _interval->setSingleShot(false);
    _interval->start(1000);
}
