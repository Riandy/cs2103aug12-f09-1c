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



class GuiControl;


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
    QVector <QString> run(bool runCommand, string _userInput);
    QVector <QString> fireAction();
};

#endif // SEAMPLE_H
