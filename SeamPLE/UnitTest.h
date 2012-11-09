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
    void testSchedulerAdd2();
    void testSchedulerAdd3();
    void testSchedulerAdd4();
    void testSchedulerAdd5();
    void testSchedulerDelete();
    void testSchedulerDelete2();
    void testSchedulerDelete3();
    void testSchedulerDelete3_2();
    void testSchedulerDelete4();

    void testSchedulerUnknownCommand();
    void testSchedulerUnknownCommand2();
    void testSchedulerUnknownCommand3();
    void testSchedulerUnknownCommand4();
    void testUndo();
    void testUnd2();
    void testUndo3();
    void testUndo4();

    void testRedo();
    void testRedo2();
    void testRedo3();
    void testRedo4();
        void testUndo5();
    void testRedo5();

#pragma endregion Scheduler UnitTesting

};

#endif // UNITTEST_H
