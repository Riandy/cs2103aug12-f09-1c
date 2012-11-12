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
    const static string VALIDBOXFLAG;
    const static string INVALIDBOXFLAG;
    const static string LINEBREAK;
    static bool instanceFlag;
    static Seample *seample;
    Seample();
    string userInput;
    Action response;
    Intellisense *intellisense;
    scheduler  *_scheduler;
    QVector <QString> feedback;
    QVector <QString> convertQString (vector <string> buffer);
    void updateInternalInput(string _userInput);
    void updateResponse();
    void setShortCutRequirementsMet(string);

public:
    static Seample* getInstance();
    ~Seample();
    void init(int argc, char *argv[]);
    void updateUserInput(string userInput);
    QVector <QString> run(Command operationType, string _userInput);
    void intellisenseHandler();
    void schedulerHandler();
    void editCommandHandler();
    void interpretEditCommand();
    void normalCommandHandler();
    void updateIntellisenseFeedBack();
    void distributeTasks(Command componentType);
    QVector <QString> fireAction();
    void sendBoxColourFlag();
    bool requirementsMet();
};

#endif // SEAMPLE_H
