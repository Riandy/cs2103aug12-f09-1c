//#include "STimeLabel.h"

//STimeLabel::STimeLabel(QWidget *parent)
//    : QLabel(parent)
//{
//    interval = new QTimer(this);
//    connect(interval, SIGNAL(timeout()), this, SLOT(showTime()));
//    interval->start(1000);

//    showTime();
//}

//void STimeLabel::showTime()
//{
//    QTime time = QTime::currentTime();
//    QString text = time.toString("hh:mm");
//    if ((time.second() % 2) == 0)
//        text[2] = ' ';
//    display(text);
//}
