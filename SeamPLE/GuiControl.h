#ifndef GUICONTROL_H
#define GUICONTROL_H

#include "NotifyView.h"
#include "SeampleView.h"
#include "StandardView.h"
#include "seample.h"
#include "timekeeper.h"

//@LIU WEIYUAN: A0086030R

//GuiControl class is the control class for GUIs in this application.
//Both SeampleView and StandardView are accessed only through this class
//Information is sent from the GUIs to the processor via the run method

class GuiControl: public QObject
{
    Q_OBJECT

private:
    static GuiControl* _guiControl;
    static int MINIMUM_SIZE;

    const static QString MESSAGE_AVAILABLE_COMMANDS;
    const static QString MESSAGE_INTELLISENSE_INVALID_RETURN;
    const static QString MESSAGE_INVALID_COLOUR_FLAG_RETURN;
    const static QString MESSAGE_SCHEDULER_INVALID_RETURN;
    const static QString MESSAGE_CANNOT_CREATE_SYSTEM_TRAY;
    const static QString MESSAGE_GUI_DISPLAY;
    const static QString MESSAGE_ONLY_STAN_GUI_DISPLAY;
    const static QString MESSAGE_EMPTY;

    const static string MESSAGE_CHANGING_AT_WRONG_INTERFACE;

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
    void toggleView(QString input, QString inputChecked,
                    bool inputBarHasFocus);
    void showHelpView();
    void displayTodaysEvents();

private:
    void updateInterface(QString input, QString inputChecked,
                         bool inputBarHasFocus);
    void showOnlySeampleView(QString input, QString inputChecked,
                                bool inputBarHasFocus);
    void showOnlyStandardView(QString input, QString inputChecked,
                                 bool inputBarHasFocus);
    void parse(QString input);
    QVector <QString> getInvalidIntellisenseFeedback();
    void processInputBarColour(QVector <QString> output);
    void processForStandardView(QVector <QString> output, QString input);
    void displayStandardMultipleResults(QVector <QString> results);
    bool singleInstanceExists();
    bool implementInputColorFlagFailure(QCharRef colorFlag) throw (string);
    bool interfaceIsStandardView();
    void setInputColourFlag(InputBarFlag flag);
    void emptyResponse();
    void send(QString feedback);
    void sendWithInputEditItem (QString input, QString feedback);
    void sendWithInputEditAndFocus (bool inputBarHasFocus, QString input,
                                    QString feedback);
    void setStandardGuiSignals();
    void setSeampleGuiSignals();
    void setTimedSignals();
    bool checkStandardViewRequired(QVector <QString> output);
    QCharRef getInputColorFlag(QVector <QString> output);

private:
    bool _standardViewFlag;
    InputBarFlag _inputColorFlag;
    Timekeeper _timeControl; 
    SeampleView* _seampleGui;
    StandardView* _standardGui;
    ErrorLogger* _faulty;
    Seample *_inputProcessor;

};
#endif // GUICONTROL_H
