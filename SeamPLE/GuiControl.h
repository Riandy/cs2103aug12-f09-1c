#ifndef GUICONTROL_H
#define GUICONTROL_H

#include "NotifyView.h"
#include "SeampleView.h"
#include "StandardView.h"
#include "seample.h"
//#include "timekeeper.h"

class GuiControl: public QObject
{
    Q_OBJECT

private:
    static GuiControl* _guiControl;

    const static QString MESSAGE_AVAILABLE_COMMANDS;
    const static QString MESSAGE_INTELLISENSE_INVALID_RETURN;
    const static QString MESSAGE_INVALID_COLOUR_FLAG_RETURN;
    const static QString MESSAGE_SCHEDULER_INVALID_RETURN;

private:
    GuiControl();

    ~GuiControl();

public:
    GuiControl* getInstance();

    void endInstance();

    void showGui();

    void setStandardViewFlag (bool flag);



private slots:
    void check(QString input);

    void passScheduler(QString input, bool inputBarHasFocus);

    void changeView(QString input, QString inputChecked, bool inputBarHasFocus);

    void showHideView();

private:
    bool singleInstanceExists();

    bool implementInputColorFlagFailure(QCharRef colorFlag);

    QVector <QString> getTodaysEvents();

    void toShow(QVector <QString> events);

    bool interfaceIsStandardView();

    bool interfaceIsCurrentlyShown();

    void setInterfaceShownFlag(bool flag);

    void emptyResponse();

    void send(QString feedback);

    void sendWithInputEditItem (QString input, QString feedback);

    void sendWithInputEditAndFocus (bool inputBarHasFocus, QString input, QString feedback);

    void setStandardGuiSignals();

    void setSeampleGuiSignals();

    //void setGlobalSignals();

    void createSystemTrayIconIfPossible();


private:

    bool _standardViewFlag;

    bool _interfaceShownFlag;

    InputBarFlag _inputColorFlag;

    //Control class that controls the input sent in and send the appropriate
    //results back to be printed
    Seample *_inputProcessor;

    //Timekeeper timekeep;

    //GuiShortcuts _allShortcuts;

    //GUI interfaces ==================
    SeampleView* _seampleGui;
    StandardView* _standardGui;
    NotifyView* _notifyInterface;
    //=================================



};
#endif // GUICONTROL_H
