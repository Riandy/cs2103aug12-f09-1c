#ifndef GUICONTROL_H
#define GUICONTROL_H

#include <QVector>
#include "mainwindow.h"
#include "standardview.h"
#include <QDebug>
#include <string>
#include "seample.h"


using namespace std;

class Seample;

class GuiControl: public QObject
{
    Q_OBJECT



public:
    explicit GuiControl(QObject *parent = 0);

    void showGui();

    void init(Seample *_app);

    void setStandardView (bool flag);

    bool isStandardView();

    void send(QVector <QString> feedback);

    void feedback(QString feedback);

private slots:
    void check(QString input);

    void passScheduler(QString input);

    void changeView();

private:

    Seample *app;


    void emptyResponse();




private:
    bool standardViewFlag;



    const static QString MESSAGE_AVAILABLE_COMMANDS;

    //GUI interfaces ==================
    MainWindow seample;
    StandardView standard;
    //=================================


};
#endif // GUICONTROL_H
