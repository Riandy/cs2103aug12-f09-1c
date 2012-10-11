#ifndef GUICONTROL_H
#define GUICONTROL_H

#include <QVector>
#include "mainwindow.h"
#include "standardview.h"
#include <QDebug>

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

    const static QString MESSAGE_AVAILABLE_COMMANDS;

    //GUI interfaces ==================
    MainWindow seample;
    StandardView standard;
    //=================================


};
#endif // GUICONTROL_H
