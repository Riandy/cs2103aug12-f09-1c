#ifndef STIMELABEL_H
#define STIMELABEL_H


#include <QLabel>
#include <QTimer>
#include "TimeGetter.h"

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



//#include <QLabel>
//#include <QDateTime>
//#include <QTimer>
//#include <QObject>

//class STimeLabel : public QLabel
//{
//    Q_OBJECT

//public:
//    STimeLabel(QWidget *parent = 0);

//private slots:
//    //void showTime();

//private:
//    QTimer* interval;
//};


#endif // STIMELABEL_H
