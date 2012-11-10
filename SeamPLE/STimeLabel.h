#ifndef STIMELABEL_H
#define STIMELABEL_H

#include <QLabel>
#include <QTimer>
#include "TimeGetter.h"

//@WEIYUAN A0086030R

//The following label ui component is implemented as a clock, which contains
//the time parameters required to display to the user.
//By using this overwritten class in place of a normal label, we would have
//obtain a clock that automatically updates itself every one second.

class STimeLabel : public QLabel
{
public:
    STimeLabel(QWidget *parent);

    ~STimeLabel();

private:
    void setAutoDateAndTimeDisplay();

private:
    QTimer* _interval;

    TimeGetter* _dateAndTime;


};
#endif // STIMELABEL_H
