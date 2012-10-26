#include "UnitTest.h"

void UnitTest::dummyTest() {
    // Always succeeds
    QVERIFY(true);
}


void UnitTest::dummyTest1() {
    // Always succeeds
    QVERIFY(true);
}


 void UnitTest::testIntellisense()
 {   Intellisense *intellisense;
     intellisense=Intellisense::getInstance();

     Action result = intellisense->check("add lin1");

     string commandword = result.getCommand();
     string eventName = result.getEventName();

     QCOMPARE(QString( commandword.c_str()),QString("ADD"));
     QCOMPARE(QString( eventName.c_str()), QString("line"));

 }
