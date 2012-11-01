#ifndef UNITTEST_H
#define UNITTEST_H

#include <QTtest/QTtest>
#include "intellisense.h"
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


};

#endif // UNITTEST_H
