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

public slots:
    void runInput(QString input);

private:
    bool standardViewFlag;

    //GUI interfaces ==================
    MainWindow seample;
    StandardView standard;
    //=================================

    QVector <QString> feedback;


};
#endif // GUICONTROL_H
