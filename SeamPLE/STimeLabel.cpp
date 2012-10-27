#include "STimeLabel.h"

STimeLabel::STimeLabel(QWidget *parent):
    QLabel(parent)
{
    setAutoDateAndTimeDisplay();
}

void STimeLabel::setAutoDateAndTimeDisplay()
{
    interval = new QTimer(this);
    connect(interval, SIGNAL(timeout()), &dateAndTime, SLOT(getStringDateAndTime()));
    connect(&dateAndTime, SIGNAL(relayStringDateAndTime(QString)), this, SLOT(setText(QString)));
    interval->start(1000);
}
