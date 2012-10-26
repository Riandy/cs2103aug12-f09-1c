#ifndef UNITTEST_H
#define UNITTEST_H

#include <QTtest/QTtest>

class UnitTest: public QObject
{ Q_OBJECT

private slots:
    void dummyTest();
    void dummyTest1();
};

#endif // UNITTEST_H
