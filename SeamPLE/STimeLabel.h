#ifndef STIMELABEL_H
#define STIMELABEL_H


#include <QLabel>
#include <QTimer>
#include "TimeGetter.h"

class STimeLabel : public QLabel
{
public:
    STimeLabel(QWidget *parent);

private:
    void setAutoDateAndTimeDisplay();

private:
    QTimer* interval;

    TimeGetter dateAndTime;


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
