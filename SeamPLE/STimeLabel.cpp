#include "STimeLabel.h"

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

void STimeLabel::setAutoDateAndTimeDisplay()
{
    _dateAndTime = _dateAndTime->getInstance();
    _interval = new QTimer(this);
    connect(_interval, SIGNAL(timeout()), _dateAndTime, SLOT(getStringDateAndTime()));
    connect(_dateAndTime, SIGNAL(relayStringDateAndTime(QString)), this, SLOT(setText(QString)));
    _interval->setSingleShot(false);
    _interval->start(1000);
}
