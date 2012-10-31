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
 {
     Intellisense *intellisense;
     intellisense=Intellisense::getInstance();

     Action result = intellisense->check("add line");

     string commandword = result.getCommand();
     string eventName = result.getEventName();

     QCOMPARE(QString( commandword.c_str()),QString("ADD"));
     QCOMPARE(QString( eventName.c_str()), QString("line"));

 }
 /*void UnitTest::testIntellisense2()
  {
      Intellisense *intellisense;
      intellisense=Intellisense::getInstance();

      Action result = intellisense->check("add Happy Aniversary Jenny 23112012 #family");

      string commandword = result.getCommand();
      string eventName = result.getEventName();
      string category = result.getCategory();
      int dateType = result.getDateType();


      QCOMPARE(QString( commandword.c_str()),QString("ADD"));
      QCOMPARE(QString( eventName.c_str()), QString("Happy Aniversary Jenny"));
      QCOMPARE(QString( category.c_str()), QString("family"));
      //QCOMPARE(QString( dateType, (task::DATENORMAL)) );
 }
*/
