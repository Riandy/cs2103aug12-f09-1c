#ifndef GUICONTROL_H
#define GUICONTROL_H

#include "SeampleView.h"
#include "StandardView.h"
#include "seample.h"

class GuiControl: public QObject
{
    Q_OBJECT

public:
    GuiControl();

    void showGui();

    void setStandardViewFlag (bool flag);


private slots:
    void check(QString input);

    void passScheduler(QString input, bool inputBarHasFocus);

    void changeView(QString input, QString inputChecked, bool inputBarHasFocus);

    void showHideView();

private:
    QVector <QString> getTodaysEvents();

    void toShow(QVector <QString> events);

    bool interfaceIsStandardView();

    bool interfaceIsCurrentlyShown();

    void setInterfaceShownFlag(bool flag);

    void emptyResponse();

    void send(QVector <QString> feedback);

    void setStandardGuiSignals();

    void setSeampleGuiSignals();

    void setGlobalSignals();

private:
    bool _standardViewFlag;

    bool _interfaceShownFlag;

    InputBarFlag _inputColorFlag;

    //Control class that controls the input sent in and send the appropriate
    //results back to be printed
    Seample *_inputProcessor;

    GuiShortcuts _allShortcuts;

    const static QString MESSAGE_AVAILABLE_COMMANDS;

    //GUI interfaces ==================
    SeampleView _seampleGui;
    StandardView _standardGui;
    //=================================



};
#endif // GUICONTROL_H
