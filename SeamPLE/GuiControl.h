#ifndef GUICONTROL_H
#define GUICONTROL_H

#include "NotifyView.h"
#include "SeampleView.h"
#include "StandardView.h"
#include "seample.h"
#include "timekeeper.h"

//@WEIYUAN A0086030R
class GuiControl: public QObject
{
    Q_OBJECT

private:
    static GuiControl* _guiControl;

    const static QString MESSAGE_AVAILABLE_COMMANDS;
    const static QString MESSAGE_INTELLISENSE_INVALID_RETURN;
    const static QString MESSAGE_INVALID_COLOUR_FLAG_RETURN;
    const static QString MESSAGE_SCHEDULER_INVALID_RETURN;
    const static QString MESSAGE_CANNOT_CREATE_SYSTEM_TRAY;
    const static QString MESSAGE_GUI_DISPLAY;
    const static QString MESSAGE_EMPTY;

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
    //void showHideView();
    void showHelpView();
    void getTodaysEvents();

private:
    bool singleInstanceExists();
    bool implementInputColorFlagFailure(QCharRef colorFlag) throw (string);
    bool interfaceIsStandardView();
    //bool interfaceIsCurrentlyShown();
    //void setInterfaceShownFlag(bool flag);
    void setInputColourFlag(InputBarFlag flag);
    void emptyResponse();
    void send(QString feedback);
    void sendWithInputEditItem (QString input, QString feedback);
    void sendWithInputEditAndFocus (bool inputBarHasFocus, QString input, QString feedback);
    void setStandardGuiSignals();
    void setSeampleGuiSignals();
    void setTimedSignals();
    //void setGlobalSignals();


private:
    //Flags ===========================
    bool _standardViewFlag;
    //bool _interfaceShownFlag;
    InputBarFlag _inputColorFlag;
    //=================================

    Timekeeper _timeControl;
    //GuiShortcuts _allShortcuts;

    //GUI interfaces ==================
    SeampleView* _seampleGui;
    StandardView* _standardGui;
    //=================================

    //Error Logger ====================
    ErrorLogger* _faulty;
    //=================================

    //Control Class ===================
    Seample *_inputProcessor;
    //=================================

};
#endif // GUICONTROL_H
