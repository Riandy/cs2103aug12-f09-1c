#ifndef UNITTEST_H
#define UNITTEST_H

#include <QTtest/QTtest>
#include "intellisense.h"
#include "scheduler.h"
#include "calender.h"
#include "task.h"

class UnitTest: public QObject
{ Q_OBJECT

private slots:
    void dummyTest();
    void dummyTest1();

#pragma region Intellisense UnitTesting
    void testIntellisenseAdd();
    void testIntellisenseAdd2();
    void testIntellisenseAdd3();
    void testIntellisenseAdd4();
    void testIntellisenseAdd5();

    void testIntellisenseDel();
    void testIntellisenseDel2();
    void testIntellisenseDEL3();

    void testIntellisenseEdit();
    void testIntellisenseEdit2();
    void testIntellisenseExit();

    void testIntellisenseDisplay();

    void testIntellisenseMark();

    void testIntellisenseQuickAdd();
    void testIntellisenseQuickAdd2();

    void testIntellisenseSort();

    void testIntellisenseFind();

    void testIntellisenseUndo();

    void testIntellisenseRedo();
#pragma endregion Intellisense UnitTesting

#pragma region Scheduler UnitTesting

    void testSchedulerAdd();
    void testSchedulerAdd2(); //pass
    void testSchedulerAdd3(); //pass
    void testSchedulerAdd4(); //pass
    void testSchedulerAdd5(); //pass
    void testUndo();
    void testUndo2();
    void testUndo3();
    void testUndo4();

    void testRedo();
    void testRedo2();
    void testRedo3();
    void testRedo4();
    void testUndo5();
    void testRedo5();

    void testSchedulerDelete(); //pass
    void testSchedulerDelete2();
    void testSchedulerDelete3();
    void testSchedulerDelete3_2(); //pass
    void testSchedulerDelete4();
    void testUndo6();
    void testUndo7();
    void testUndo8();
    void testUndo9();

    void testRedo6();
    void testRedo7();
    void testRedo8();
    void testRedo9();
    void testUndo10();
    void testRedo10();
    void testSchedulerUnknownCommand();
    void testSchedulerUnknownCommand2();
    void testSchedulerUnknownCommand3();
    void testSchedulerUnknownCommand4();


    void testEdit();
    void testEdit2();
    void testEdit3();
    void testEdit4();
    void testEdit5();
    void testUndo11();
    void testUndo12();
    void testUndo13();
    void testUndo14();

    void testRedo11();
    void testRedo12();
    void testRedo13();
    void testRedo14();
    void testUndo15();
    void testRedo15();

    void testMark();
    void testMark2();
    void testMark3();
    void testMark4();
    void testMark5();
#pragma endregion Scheduler UnitTesting

#pragma region Calender Unit Testing

    void testAddItem();
    void testDeleteItemByID();
    //void testDeleteItemByID2();
    void testDeleteItemByEventName();
    void testDeleteItemByEventName2();
    void checkID();
    void checkID2();
    void deleteAll();
    void searchByCat();
    void searchByCat2();
    void searchByTask();
    void searchByTask2();
//    void searchByPartialTask();
//    void searchByDate();
//    void convertToDate();
//    void getToday();
//    void displayDatabase();
//    void getFloatingEvents();

#pragma endregion Calender Unit Testing

};

#endif // UNITTEST_H
