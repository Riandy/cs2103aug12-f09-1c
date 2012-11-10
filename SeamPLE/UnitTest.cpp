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



#pragma region Scheduler UnitTesting

void UnitTest::testSchedulerAdd() //@JOHN
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
void UnitTest::testSchedulerAdd2() //@JOHN
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
void UnitTest::testSchedulerAdd3() //@JOHN
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
void UnitTest::testSchedulerAdd4() //@JOHN
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

void UnitTest::testSchedulerAdd5() //@JOHN
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
void UnitTest::testSchedulerDelete() //@JOHN
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
void UnitTest::testSchedulerDelete2() //@JOHN
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
void UnitTest::testSchedulerDelete3() //@JOHN
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
void UnitTest::testSchedulerDelete3_2() //@JOHN
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
void UnitTest::testSchedulerDelete4() //@JOHN
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

void UnitTest::testSchedulerUnknownCommand() //@JOHN
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
void UnitTest::testSchedulerUnknownCommand2() //@JOHN
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
void UnitTest::testSchedulerUnknownCommand3() //@JOHN
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
void UnitTest::testSchedulerUnknownCommand4() //@JOHN
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

void UnitTest::testUndo() //@JOHN
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

void UnitTest::testUndo2() //@JOHN
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
void UnitTest::testUndo3() //@JOHN
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

void UnitTest::testRedo() //@JOHN
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
void UnitTest::testRedo2() //@JOHN
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
void UnitTest::testRedo3() //@JOHN
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
void UnitTest::testRedo4() //@JOHN
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
void UnitTest::testUndo5() //@JOHN
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

void UnitTest::testRedo5() //@JOHN
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
void UnitTest::testEdit() //@JOHN
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

void UnitTest::testEdit2() //@JOHN
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
void UnitTest::testEdit3() //@JOHN
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
void UnitTest::testEdit4() //@JOHN
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
void UnitTest::testEdit5() //@JOHN
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
void UnitTest::testUndo9() //@JOHN
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

void UnitTest::testUndo8() //@JOHN
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
void UnitTest::testUndo7() //@JOHN
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
void UnitTest::testUndo6() //@JOHN
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

void UnitTest::testRedo7() //@JOHN
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
void UnitTest::testRedo8() //@JOHN
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
void UnitTest::testRedo6() //@JOHN
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
void UnitTest::testRedo9() //@JOHN
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
void UnitTest::testUndo10() //@JOHN
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

void UnitTest::testRedo10() //@JOHN
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
void UnitTest::testUndo11() //@JOHN
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

void UnitTest::testUndo12() //@JOHN
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
void UnitTest::testUndo13() //@JOHN
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
void UnitTest::testUndo14() //@JOHN
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

void UnitTest::testRedo11() //@JOHN
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
void UnitTest::testRedo12() //@JOHN
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
void UnitTest::testRedo13() //@JOHN
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
void UnitTest::testRedo14() //@JOHN
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
void UnitTest::testUndo15() //@JOHN
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

void UnitTest::testRedo15() //@JOHN
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

void UnitTest::testMark() //@JOHN
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
void UnitTest::testMark2() //@JOHN
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
void UnitTest::testMark3() //@JOHN
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
void UnitTest::testMark4() //@JOHN
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
void UnitTest::testMark5() //@JOHN
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

#pragma endregion Scheduler UnitTesting
