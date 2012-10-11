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

//WY: Comment out for now
//class GuiControl;

class Seample
{

private:
    string userInput;
    Action response;
    Intellisense intellisense;
    GuiControl *_view;
    QVector <QString> feedback;

public:
    Seample();
    void init(int argc, char *argv[]);
    void updateUserInput(string userInput);
    void run(string _userInput);
};

#endif // SEAMPLE_H
