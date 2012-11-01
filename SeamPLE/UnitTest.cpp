#include "UnitTest.h"

void UnitTest::dummyTest() {
    // Always succeeds
    QVERIFY(true);
}


void UnitTest::dummyTest1() {
    // Always succeeds
    QVERIFY(true);
}



#pragma region Intellisense UnitTesting

void UnitTest::testIntellisenseAdd()
{//basic add
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("add birthday");
    string commandword = result.getCommand();
    string eventName = result.getEventName();
    QCOMPARE(commandword ,string("ADD"));
    QCOMPARE(eventName, string("birthday"));
}
void UnitTest::testIntellisenseAdd2()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("add soccer match HIGH");
    string commandword = result.getCommand();
    string eventName = result.getEventName();
    string priority = result.getPriority();

    QCOMPARE(commandword ,string("ADD"));
    QCOMPARE(eventName, string("soccer match"));
    QCOMPARE(priority, string("HIGH"));
}
void UnitTest::testIntellisenseAdd3()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("add soccer match #SPORTS");
    string commandword = result.getCommand();
    string eventName = result.getEventName();
    string category = result.getCategory();

    QCOMPARE(commandword ,string("ADD"));
    QCOMPARE(eventName, string("soccer match"));
    QCOMPARE(category, string("SPORTS"));
}
void UnitTest::testIntellisenseAdd4()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();
    Action result = intellisense->check("add record 9 news 09102012 9am");

    string eventName = result.getEventName();
    tm date = result.getStartDate();

    QCOMPARE( eventName, string ("record 9 news"));
    QCOMPARE( date.tm_year, int(2012));
    QCOMPARE( date.tm_mday, int(9));
    QCOMPARE( date.tm_mon,  int(10));
    QCOMPARE( date.tm_min,  int(0));
    QCOMPARE( date.tm_hour, int(9));
}

void UnitTest::testIntellisenseAdd5()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();
    Action result = intellisense->check("add record 9 news 09/10/2012 9pm");

    string eventName = result.getEventName();
    tm date = result.getStartDate();

    QCOMPARE( eventName, string ("record 9 news"));
    QCOMPARE( date.tm_year, int(2012));
    QCOMPARE( date.tm_mday, int(9));
    QCOMPARE( date.tm_mon,  int(10));
    QCOMPARE( date.tm_min,  int(0));
    QCOMPARE( date.tm_hour, int(21));
}




void UnitTest::testIntellisenseDel()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("del birthday");

    string commandword = result.getCommand();
    string eventName = result.getEventName();
    string category = result.getCategory();
    int dateType = result.getDateType();

    QCOMPARE(commandword ,string("DELETE"));
    QCOMPARE(eventName, string("birthday"));//got space at the end

}

void UnitTest::testIntellisenseDel2()
{//test delete by id
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("del 2");

    string commandword = result.getCommand();
    int id = result.getID();

    QCOMPARE(commandword ,string("DELETE"));
    QCOMPARE(id, 2);

}

void UnitTest::testIntellisenseDEL3()
 {
      Intellisense *intellisense;
      intellisense=Intellisense::getInstance();

      Action result = intellisense->check("del #asd");

      string commandword = result.getCommand();
      string eventName = result.getEventName();
      string category  = result.getCategory();
      int id = result.getID();

      QCOMPARE(commandword ,string("DELETE"));
      QCOMPARE(id, -1);
      QCOMPARE(eventName, string("#asd"));
      QCOMPARE( category , string("#"));

}

void UnitTest::testIntellisenseEdit()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("EDIT");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("EDIT"));
}
void UnitTest::testIntellisenseEdit2()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("EDIT birthday #celebration");
    string eventName = result.getEventName();
    string commandword = result.getCommand();
    string category = result.getCategory();
    QCOMPARE(commandword,string("EDIT"));
    QCOMPARE(eventName,string("birthday"));
    QCOMPARE(category,string("celebration"));
}

void UnitTest::testIntellisenseExit()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("exit");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("EXIT"));
}

void UnitTest::testIntellisenseDisplay()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("Display");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("DISPLAY"));
}
void UnitTest::testIntellisenseMark()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("MaRK");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("MARK"));
}
void UnitTest::testIntellisenseQuickAdd()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("Happy Aniversary Jenny 23112012 #family");

    string commandword = result.getCommand();
    string eventName = result.getEventName();
    string category = result.getCategory();
    int dateType = result.getDateType();


    QCOMPARE(commandword,string("ADD"));
    QCOMPARE(eventName, string("Happy Aniversary Jenny"));
    QCOMPARE(category, string("family"));
    QCOMPARE( dateType, task::DATENORMAL );
}

void UnitTest::testIntellisenseQuickAdd2()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("yoga lesson 29/02/2013 8am weekly");

    string commandword = result.getCommand();
    int dateType = result.getDateType();
    tm datecheck = result.getStartDate();
    string eventName = result.getEventName();

    QCOMPARE(commandword, string("ADD"));
    QCOMPARE(eventName , string("yoga lesson"));
    QCOMPARE(dateType, task::DATEWEEKLY);
    QCOMPARE(datecheck.tm_hour , int(8));
    QCOMPARE(datecheck.tm_min , int(0));
    QCOMPARE(datecheck.tm_mon, int (2));


}

void UnitTest::testIntellisenseSort()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("sort");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("SORT"));

}

void UnitTest::testIntellisenseFind()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("fINd");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("FIND"));
}
void UnitTest::testIntellisenseUndo()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("uNDO");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("UNDO"));
}

void UnitTest::testIntellisenseRedo()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("redo");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("REDO"));
}

#pragma endregion Intellisense UnitTesting


