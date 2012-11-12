#ifndef SEAMPLE_H
#define SEAMPLE_H
#include <QtGui/QApplication>

#include <QDebug>
#include <iostream>
#include "Intellisense.h"
#include "Action.h"
#include "seample.h"
#include "scheduler.h"
#include "QuickCheck.h"

enum Command
{
    TO_INTELLISENSE,
    TO_SCHEDULER_AND_RETURN_RESULTS,
    TO_SCHEDULER_AND_RETURN_TODAY_EVENTS
};


class Seample
{

private:
    const static string VALIDBOXFLAG;
    const static string INVALIDBOXFLAG;
    const static string LINEBREAK;
    static bool instanceFlag;
    static Seample *seample;

    string userInput;
    Action response;
    Intellisense *intellisense;
    scheduler  *_scheduler;

    //string manipulation functions
    QVector <QString> feedback;
    QVector <QString> convertQString (vector <string> buffer);


    Seample();
    ~Seample();

    void distributeTasks(Command componentType);

    void intellisenseHandler();
    void schedulerHandler();
    void normalCommandHandler();
    void editCommandHandler();
    void interpretEditCommand();
    void updateUserInput(string userInput);
    void updateIntellisenseFeedBack();
    void updateInternalInput(string _userInput);
    void updateResponse();
    void sendBoxColourFlag();

public:
    static Seample* getInstance();
    QVector <QString> run(Command operationType, string _userInput);
    QVector <QString> fireAction();
    void init(int argc, char *argv[]);
    bool requirementsMet();

private:
    void setShortCutRequirementsMet(string input);
};

#endif // SEAMPLE_H
