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

//@CHAM WEN BIN U094659H
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
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
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
//@CHAM WEN BIN U094659H
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
//@CHAM WEN BIN U094659H
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
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseEdit()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("EDIT");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("EDIT"));
}
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseExit()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("exit");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("EXIT"));
}
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseDisplay()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("Display");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("DISPLAY"));
}
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseMark()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("MaRK");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("MARK"));
}
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseSort()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("sort");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("SORT"));

}
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseFind()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("fINd");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("FIND"));
}
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseUndo()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("uNDO");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("UNDO"));
}
//@PAN WENREN A0083711L
void UnitTest::testIntellisenseRedo()
{
    Intellisense *intellisense;
    intellisense=Intellisense::getInstance();

    Action result = intellisense->check("redo");

    string commandword = result.getCommand();
    QCOMPARE(commandword,string("REDO"));
}

#pragma endregion Intellisense UnitTesting



#pragma region Scheduler UnitTesting
//@JOHN A0069517W
void UnitTest::testSchedulerAdd()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Add");
    task* testTask = new task;
    testTask->setEventName("");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("You have not entered a valid event description."));
    delete testAction;
    delete testTask;

}
//@JOHN A0069517W
void UnitTest::testSchedulerAdd2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("ADd");
    task* testTask = new task;
    testTask->setEventName("Chicken");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was added successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W

void UnitTest::testSchedulerAdd3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("adD");
    task* testTask = new task;
    testTask->setEventName("ChickenRice");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was added successfully."));
    delete testAction;
    delete testTask;
}
    //@JOHN A0069517W
void UnitTest::testSchedulerAdd4()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("aDd");
    task* testTask = new task;
    testTask->setEventName("ILOVEUNITTESTS");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was added successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerAdd5()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("ADd");
    task* testTask = new task;
    testTask->setEventName("googlehiremenaoz");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was added successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerDelete()
{    scheduler *testScheduler;
     testScheduler = scheduler::getInstance();

     Action* testAction = new Action;
     testAction->setCommand("delete");
     task* testTask = new task;
     testTask->setID(1);
     testAction->setTask(*testTask);

     vector<string> testVector =testScheduler->executeCommand(*testAction);
     QCOMPARE(testVector[0], string("Your event was deleted successfully."));
     delete testAction;
     delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerDelete2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("delete");
    task* testTask = new task;
    testTask->setEventName("");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is too little information to choose a task to delete."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerDelete3()
{
     scheduler *testScheduler;
     testScheduler = scheduler::getInstance();

     Action* testAction = new Action;
     testAction->setCommand("delete");
     task* testTask = new task;
     testTask->setEventName("ILOVEuNITTESTS");
     testAction->setTask(*testTask);

     vector<string> testVector =testScheduler->executeCommand(*testAction);
     QCOMPARE(testVector[0], string("The item does not exist."));
     delete testAction;
     delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerDelete3_2()
{
     scheduler *testScheduler;
     testScheduler = scheduler::getInstance();

     Action* testAction = new Action;
     testAction->setCommand("deLEtE");
     task* testTask = new task;
     testTask->setEventName("ILOVEUNITTESTS");
     testAction->setTask(*testTask);

     vector<string> testVector =testScheduler->executeCommand(*testAction);
     QCOMPARE(testVector[0], string("Your event was deleted successfully."));
     delete testAction;
     delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerDelete4()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("delete");
    task* testTask = new task;
    testTask->setEventName("FusRODAH");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("The item does not exist."));
    delete testAction;
    delete testTask;
}

//@JOHN A0069517W
void UnitTest::testSchedulerUnknownCommand()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("IAMATELETUBBY");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Error - The system failed to process your request. Please try again."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerUnknownCommand2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("NEVERGONNAGIVEYOUUP");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Error - The system failed to process your request. Please try again."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerUnknownCommand3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("DELETZ");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Error - The system failed to process your request. Please try again."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testSchedulerUnknownCommand4()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("OPPAGANNAMSTYLEZ");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Error - The system failed to process your request. Please try again."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo4() //@JOHN
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is nothing to undo."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo4()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is nothing to redo."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo5()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo5()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testEdit()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("editenter");
    task* testTask = new task;
    testTask->setEventName("");
    testAction->setTask(*testTask);
    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Error - The system failed to process your request. Please try again."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testEdit2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("editenter");
    task* testTask = new task;
    testTask->setEventName("ChickenRice");
    testTask->setPriority("HIGH");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was edited successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testEdit3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("editenter");
    task* testTask = new task;
    testTask->setEventName("ChickenRice");
    testTask->setPriority("LOW");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was edited successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testEdit4()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("editenter");
    task* testTask = new task;
    testTask->setEventName("ChickenRice");
    testTask->setPriority("HIGH");
    testTask->setCategory("#nice");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was edited successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testEdit5()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("editenter");
    task* testTask = new task;
    testTask->setEventName("ChickenRice");

    testTask->setCategory("#notnice");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was edited successfully."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo9()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is nothing to undo."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo8()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo7()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo6()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}

//@JOHN A0069517W
void UnitTest::testRedo7()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo8()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo6()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo9()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is nothing to redo."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo10()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo10()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo11()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo12()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo13()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo14()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is nothing to undo."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo11()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo12()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo13()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testRedo14()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There is nothing to redo."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testUndo15()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("Undo");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Undo operation was successful."));
    delete testAction;
    delete testTask;
}

//@JOHN A0069517W
void UnitTest::testRedo15()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("redO");
    task* testTask = new task;
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Redo operation was successful."));
    delete testAction;
    delete testTask;
}

//@JOHN A0069517W
void UnitTest::testMark()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("MARK");
    task* testTask = new task;
    testTask->setEventName("ChickenRice");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was marked as completed."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testMark2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("MARK");
    task* testTask = new task;
    testTask->setEventName("googlehiremenaoz");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("Your event was marked as completed."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testMark3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("MARK");
    task* testTask = new task;
    testTask->setEventName("googlehiremenaoz");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There was an error marking your event."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testMark4()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("MARK");
    task* testTask = new task;
    testTask->setEventName("");
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There was an error marking your event."));
    delete testAction;
    delete testTask;
}
//@JOHN A0069517W
void UnitTest::testMark5()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    Action* testAction = new Action;
    testAction->setCommand("MARK");
    task* testTask = new task;
    testTask->setID(3);
    testAction->setTask(*testTask);

    vector<string> testVector =testScheduler->executeCommand(*testAction);
    QCOMPARE(testVector[0], string("There was an error marking your event."));
    delete testAction;
    delete testTask;
}

//@LIU WEIYUAN A0086030R
//Test size of vector returned when no events for today
void UnitTest::testTodayEventNoEvent()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    vector<string> testVector = testScheduler->getTodayEvents();
    int size = testVector.size();
    QCOMPARE(size,2);

    delete testScheduler;
}

//@LIU WEIYUAN A0086030R
//Test for number of outstanding events returned when no events for today
void UnitTest::testTodayEventNoEvent2()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    vector<string> testVector = testScheduler->getTodayEvents();
    string result = testVector[0];
    QCOMPARE(result,string("0"));

    delete testScheduler;
}

//@LIU WEIYUAN A0086030R
//Test for number of priority events returned when no events for today
void UnitTest::testTodayEventNoEvent3()
{
    scheduler *testScheduler;
    testScheduler = scheduler::getInstance();

    vector<string> testVector = testScheduler->getTodayEvents();
    string result = testVector[1];
    QCOMPARE(result,string("0"));

    delete testScheduler;
}

#pragma endregion Scheduler UnitTesting

#pragma region Calender Unit Testing

//@Riandy A0088392R
//testing to add an event
void UnitTest::testAddItem()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("Going for meeting");
    testTask.setPriority("HIGH");
    QCOMPARE(testCalender.addItem(testTask),true);
}

//@Riandy A0088392R
//testing to delete item ID that exist
void UnitTest::testDeleteItemByID()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("This is to test Delete by ID");
    tm startDate;
    startDate.tm_mday=12;
    startDate.tm_hour=10;
    startDate.tm_min=55;
    startDate.tm_mon=4;
    startDate.tm_sec=1;
    startDate.tm_year=2012;
    testTask.setStartDate(startDate);
    //can only be tested if the addItem is correct.
    testCalender.addItem(testTask);
    QCOMPARE(testCalender.deleteItem(1),true);
}

//@Riandy A0088392R
//test for the event name that does not exist
void UnitTest::testDeleteItemByEventName()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("This is to test Delete by EventName");
    tm startDate;
    startDate.tm_mday=12;
    startDate.tm_hour=10;
    startDate.tm_min=55;
    startDate.tm_mon=4;
    startDate.tm_sec=1;
    startDate.tm_year=2012;
    testTask.setStartDate(startDate);
    //can only be tested if the addItem is correct.
    testCalender.addItem(testTask);
    QCOMPARE(testCalender.deleteItem("Hello"),false);
}

//@Riandy A0088392R
//test for the event name that exist
void UnitTest::testDeleteItemByEventName2()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("This is to test Delete by EventName");
    tm startDate;
    startDate.tm_mday=2;
    startDate.tm_hour=10;
    startDate.tm_min=5;
    startDate.tm_mon=4;
    startDate.tm_sec=11;
    startDate.tm_year=2013;
    testTask.setStartDate(startDate);
    //can only be tested if the addItem is correct.
    testCalender.addItem(testTask);
    QCOMPARE(testCalender.deleteItem("This is to test Delete by EventName"),true);
}

//@Riandy A0088392R
//check for non existence ID
void UnitTest::testcheckID()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("Checking the existence of ID");
    tm startDate;
    startDate.tm_mday=2;
    startDate.tm_hour=10;
    startDate.tm_min=5;
    startDate.tm_mon=4;
    startDate.tm_sec=11;
    startDate.tm_year=2013;
    testTask.setStartDate(startDate);
    task testTask2;
    testTask.setEventName("Checking ID 2");
    tm startDate2;
    startDate2.tm_mday=2;
    startDate2.tm_hour=10;
    startDate2.tm_min=5;
    startDate2.tm_mon=4;
    startDate2.tm_sec=11;
    startDate2.tm_year=2013;
    testTask2.setStartDate(startDate2);
    //can only be tested if the addItem is correct.
    testCalender.addItem(testTask2);
    QCOMPARE(testCalender.checkID(11),false);
}

//@Riandy A0088392R
//check for existence ID
void UnitTest::testcheckID2()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("Checking the existence of ID");
    tm startDate;
    startDate.tm_mday=12;
    startDate.tm_hour=10;
    startDate.tm_min=15;
    startDate.tm_mon=9;
    startDate.tm_sec=11;
    startDate.tm_year=2013;
    testTask.setStartDate(startDate);
    task testTask2;
    testTask.setEventName("Checking ID 2");
    tm startDate2;
    startDate2.tm_mday=2;
    startDate2.tm_hour=10;
    startDate2.tm_min=5;
    startDate2.tm_mon=4;
    startDate2.tm_sec=11;
    startDate2.tm_year=2013;
    testTask2.setStartDate(startDate2);
    //can only be tested if the addItem is correct.
    testCalender.addItem(testTask);
    testCalender.addItem(testTask2);
    QCOMPARE(testCalender.checkID(1),true);
}

//@Riandy A0088392R
//this unit test try to delete all the database
void UnitTest::testdeleteAll()
{
    calender testCalender;
    task testTask;
    int size=testCalender.displayDatabase().size();
    testTask.setEventName("Adding task 1 to test delete");
    testTask.setCategory("Testing only");
    testTask.setID(100);
    testTask.setDateType(4);
    task testTask2;
    testTask.setEventName("Checking ID 2");
    tm startDate2;
    startDate2.tm_mday=2;
    startDate2.tm_hour=10;
    startDate2.tm_min=5;
    startDate2.tm_mon=4;
    startDate2.tm_sec=11;
    startDate2.tm_year=2013;
    testTask2.setStartDate(startDate2);
    testCalender.addItem(testTask);
    testCalender.addItem(testTask2);
    QCOMPARE(testCalender.displayDatabase().size()==size+2,true);
    QCOMPARE(testCalender.deleteAll(),true);
    QCOMPARE(testCalender.displayDatabase().size()==0,true);
}

//@Riandy A0088392R
void UnitTest::testsearchByCat()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("Adding task 1 to test delete");
    testTask.setCategory("Testing only");
    testTask.setID(100);
    testTask.setDateType(4);
    testCalender.addItem(testTask);
    QCOMPARE(testCalender.SearchByCat("MEME").size()==0,true);
}

//@Riandy A0088392R
void UnitTest::testsearchByCat2()
{
    calender testCalender;
    task testTask;
    testTask.setEventName("How if item not exist??");
    testTask.setCategory("Testing only");
    testTask.setID(34);
    testTask.setPriority("LOW");
    testTask.setDateType(1);
    testTask.setCategory("meeting");
    testCalender.addItem(testTask);
    QCOMPARE(testCalender.SearchByCat("meeting").size()==1,true);
}

//@Riandy A0088392R
void UnitTest::testsearchByTask()
{
    calender taskCalender;
    task testTask;
    //adding 5 tasks to test the searching
    testTask.setEventName("test1");
    taskCalender.addItem(testTask);
    testTask.setEventName("test2");
    taskCalender.addItem(testTask);
    testTask.setEventName("test");
    taskCalender.addItem(testTask);
    taskCalender.addItem(testTask);
    taskCalender.addItem(testTask);
    QCOMPARE(taskCalender.SearchByTask("test").size()==0,false);
}

//@Riandy A0088392R
void UnitTest::testsearchByTask2()
{
    calender taskCalender;
    task testTask;
    int resultBefore= taskCalender.SearchByTask("test").size();
    //adding 5 tasks to test the searching
    testTask.setEventName("test1");
    taskCalender.addItem(testTask);
    testTask.setEventName("test2");
    taskCalender.addItem(testTask);
    testTask.setEventName("test");
    taskCalender.addItem(testTask);
    taskCalender.addItem(testTask);
    taskCalender.addItem(testTask);
    QCOMPARE(taskCalender.SearchByTask("test").size()==resultBefore+5,true);
}

//@Riandy A0088392R
void UnitTest::testsearchByDate()
{
    calender taskCalender;
    task testTask;
    tm date;
    date.tm_hour=20;
    date.tm_mday=12;
    date.tm_min=10;
    date.tm_mon=1;
    date.tm_sec=0;
    date.tm_year=2012;
    testTask.setStartDate(date);
    taskCalender.addItem(testTask);
    date.tm_year=2011;
    testTask.setStartDate(date);
    taskCalender.addItem(testTask);
    date.tm_hour=20;
    date.tm_mday=12;
    date.tm_min=10;
    date.tm_mon=11;
    date.tm_sec=0;
    date.tm_year=2014;
    testTask.setStartDate(date);
    taskCalender.addItem(testTask);
    QCOMPARE(taskCalender.SearchByDate("12 / 1 / 2012").size()==1,true);
}

//@Riandy A0088392R
void UnitTest::testconvertToDate()
{
    calender taskCalender;
    tm date;
    date.tm_hour=20;
    date.tm_mday=11;
    date.tm_min=10;
    date.tm_mon=11;
    date.tm_sec=0;
    date.tm_year=2012;
    QCOMPARE(taskCalender.convertToDate(date).compare("11 / 11 / 2012 - 20 : 10 : 0")==0,true);
}

//@Riandy A0088392R
void UnitTest::testconvertToDateWithoutTime()
{
    calender taskCalender;
    tm date;
    date.tm_mday=11;
    date.tm_mon=11;
    date.tm_year=2012;
    QCOMPARE(taskCalender.convertToDateNoTime(date).compare("11 / 11 / 2012")==0,true);
}

//@JOHN A0069517W
void UnitTest::testDeleteAll2()
{
    calender testCalender;
    bool test = testCalender.deleteAll();
    QCOMPARE(test, true);
}

//@JOHN A0069517W
void UnitTest::testDeleteAll3()
{
    calender testCalender;
    bool test = testCalender.deleteAll();
    QCOMPARE(test, false);
}





#pragma endregion Calender Unit Testing
