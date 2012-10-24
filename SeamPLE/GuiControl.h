#ifndef GUICONTROL_H
#define GUICONTROL_H

#include <QSystemTrayIcon>
#include <QTimer>
#include "SeampleView.h"
#include "StandardView.h"
#include "seample.h"

class GuiControl: public QObject
{
    Q_OBJECT

private:
    const static QString MESSAGE_AVAILABLE_COMMANDS;
    const static QString MESSAGE_INTELLISENSE_INVALID_RETURN;
    const static QString MESSAGE_INVALID_COLOUR_FLAG_RETURN;
    const static QString MESSAGE_SCHEDULER_INVALID_RETURN;
public:
    GuiControl();

    ~GuiControl();

    void showGui();

    void setStandardViewFlag (bool flag);


private slots:
    void check(QString input);

    void passScheduler(QString input, bool inputBarHasFocus);

    void changeView(QString input, QString inputChecked, bool inputBarHasFocus);

    void showHideView();

private:
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

    //GuiShortcuts _allShortcuts;

    QSystemTrayIcon* popUp;

    //GUI interfaces ==================
    SeampleView _seampleGui;
    StandardView _standardGui;
    //=================================



};
#endif // GUICONTROL_H
