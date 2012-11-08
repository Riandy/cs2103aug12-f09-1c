#ifndef SEAMPLE_H
#define SEAMPLE_H
#include <QtGui/QApplication>

#include "Intellisense.h"
#include "Action.h"
#include <QDebug>
#include <string>
#include <iostream>
#include "seample.h"
#include "scheduler.h"

enum Command
{
    TO_INTELLISENSE,
    TO_SCHEDULER_AND_RETURN_RESULTS,
    TO_SCHEDULER_AND_RETURN_TODAY_EVENTS
};


class Seample
{

private:
    static bool instanceFlag;
    static Seample *seample;
    Seample();
    string userInput;
    Action response;
    Intellisense *intellisense;
    scheduler  *_scheduler;
    QVector <QString> feedback;

    //Following function is for converting vector of QString
    //to QVector of QString
    QVector <QString> convertQString (vector <string> buffer);

    void setShortCutRequirementsMet(string);

public:
    static Seample* getInstance();
    ~Seample();
    void init(int argc, char *argv[]);
    void updateUserInput(string userInput);
    QVector <QString> run(Command operationType, string _userInput);
    QVector <QString> fireAction();
    bool requirementsMet();
};

#endif // SEAMPLE_H
