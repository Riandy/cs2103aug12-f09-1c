#ifndef SEAMPLE_H
#define SEAMPLE_H
#include <QtGui/QApplication>
#include "GuiControl.h"
#include "Intellisense.h"
#include "Action.h"
#include <QDebug>
#include <string>
#include <iostream>
#include "seample.h"
#include "scheduler.h"

class GuiControl;
class scheduler;

class Seample
{

private:
    string userInput;
    Action response;
    Intellisense intellisense;
    GuiControl *_view;
    scheduler  *_scheduler;
    QVector <QString> feedback;

public:
    Seample();
    void init(int argc, char *argv[]);
    void updateUserInput(string userInput);
    void run(string _userInput);
    void fireAction();
};

#endif // SEAMPLE_H
