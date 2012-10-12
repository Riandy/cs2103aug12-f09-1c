#ifndef GUICONTROL_H
#define GUICONTROL_H

#include <QVector>
#include "mainwindow.h"
#include "standardview.h"
#include "seample.h"

class GuiControl: public QObject
{
    Q_OBJECT

public:
    explicit GuiControl(QObject *parent = 0);

    void showGui();

    void setStandardView (bool flag);

    bool isStandardView();

private slots:
    void check(QString input);

    void passScheduler(QString input);

    void changeView(QString input, QString inputChecked);

private:
    void emptyResponse();

    void send(QVector <QString> feedback);

private:
    bool standardViewFlag;

    //Control class that controls the input sent in and send the appropriate
    //results back to be printed
    Seample inputProcessor;

    const static QString MESSAGE_AVAILABLE_COMMANDS;

    //GUI interfaces ==================
    MainWindow seampleGui;
    StandardView standardGui;
    //=================================


};
#endif // GUICONTROL_H
