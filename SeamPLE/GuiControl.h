#ifndef GUICONTROL_H
#define GUICONTROL_H

#include <QVector>
#include "SeampleView.h"
#include "StandardView.h"
#include "seample.h"

class GuiControl: public QObject
{
    Q_OBJECT

public:
    explicit GuiControl(QObject *parent = 0);

    void showGui();

    void setStandardView (bool flag);


private slots:
    void check(QString input);

    void passScheduler(QString input, bool inputBarHasFocus);

    void changeView(QString input, QString inputChecked, bool inputBarHasFocus);

private:
    bool isStandardView();

    void emptyResponse();

    void send(QVector <QString> feedback);

    void setStandardGuiSignals();

    void setSeampleGuiSignals();

private:
    bool standardViewFlag;

    //Control class that controls the input sent in and send the appropriate
    //results back to be printed
    Seample inputProcessor;

    const static QString MESSAGE_AVAILABLE_COMMANDS;

    //GUI interfaces ==================
    SeampleView seampleGui;
    StandardView standardGui;
    //=================================


};
#endif // GUICONTROL_H
