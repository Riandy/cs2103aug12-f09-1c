#ifndef UNITTEST_H
#define UNITTEST_H

#include <QTtest/QTtest>
#include "intellisense.h"

class UnitTest: public QObject
{ Q_OBJECT

private slots:
    void dummyTest();
    void dummyTest1();
    void testIntellisense();


};

#endif // UNITTEST_H
