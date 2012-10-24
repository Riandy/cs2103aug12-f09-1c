#include "GuiControl.h"

const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"MV Boli\" color = \"orange\">"
        "Available Commands: add, delete, mark, unmark, "
        "edit and find</font>";

GuiControl::GuiControl()
{
    setStandardGuiSignals();
    setSeampleGuiSignals();
    //setGlobalSignals();
    _inputProcessor = Seample::getInstance();
    setInterfaceShownFlag(true);
    _inputColorFlag = NONE;
    createSystemTrayIconIfPossible();
    //QVector <QString> events = getTodaysEvents();
    //toShow(events);
}

GuiControl::~GuiControl()
{
    if (popUp != NULL)
    {
        delete popUp;
    }
}

void GuiControl:: showGui()
{
    if (_standardViewFlag)
    {
        _standardGui.show();
    }
    else
    {
        _seampleGui.show();
    }
}

void GuiControl::setStandardViewFlag (bool flag)
{
    _standardViewFlag = flag;
}

//This function is for recieving input from user and sending
//into intellisense class to interpret the text input. The
//feedback is generated to the user
void GuiControl::check(QString input)
{
    bool emptyInput = (input.size() == 0);

    if (emptyInput)
    {
        emptyResponse();
    }
    else
    {
        bool command = false;
        QVector <QString> output = _inputProcessor->run(command,input.toStdString());

        bool invalidSchedulerReturn = (output.size() < 2);

        if (invalidSchedulerReturn)
        {
            output.clear();
            output.push_front("INTELLISENSE IS NOT WORKING");
            _inputColorFlag = NONE;
        }
        else
        {
            if ((output[1])[0].isDigit())
            {
                _inputColorFlag = (InputBarFlag) (output[1])[0].digitValue();
            }
            else
            {
                output.push_front("SEAMPLE NOT RETURNING APPROPRIATE COLOR FLAG");
                _inputColorFlag = NONE;
            }
        }
        send(output);
    }
}

void GuiControl::passScheduler(QString input, bool inputBarHasFocus)
{
    //Code to be implemented here to be sent into  scheduler classes
    bool emptyInput = (input.size() == 0);

    if (emptyInput)
    {
        emptyResponse();
    }
    else
    {
        bool command = true;
        QVector <QString> output = _inputProcessor->run(command,input.toStdString());
        int capacity = output.size();
        bool needStandardView = (capacity>2);
        _inputColorFlag = NONE;

        //Only commands to hold this should be find and search for now
        if (needStandardView)
        {
            if (!interfaceIsStandardView())
            {
                changeView("",output[0], inputBarHasFocus);
            }
            else
            {
                send(output);
                _standardGui.showFeedbackInputEdit("");
                _standardGui.showFocusInInputEdit(inputBarHasFocus);
            }
            _standardGui.showTableResults(output.mid(1,capacity - 1));
        }
        else
        {
            //Scheduler must send results back. If not, we error handle it
            //to produce an output that informs that no output is returned
            bool invalidSchedulerReturn = (output.size() == 0);

            if (invalidSchedulerReturn)
            {
                output.push_front("SCHEDULER IS NOT RETURNING ANY OUTPUT");
            }
            _standardGui.showFeedbackInputEdit("");
            _standardGui.resetTableContents();
            send(output);
        }
    }
}

void GuiControl::changeView(QString input, QString inputChecked, bool inputBarHasFocus)
{
    setStandardViewFlag(!interfaceIsStandardView());

    if(interfaceIsStandardView())
    {
        _seampleGui.hide();
        _standardGui.show();
        _standardGui.showFeedbackInputEdit(input);
        _standardGui.showFeedbackLabel(inputChecked);
        _standardGui.showFocusInInputEdit(inputBarHasFocus);
        _standardGui.showAppropriateColorInputEdit(_inputColorFlag);
    }
    else
    {
        _standardGui.hide();
        _seampleGui.show();
        _seampleGui.showFeedbackInputEdit(input);
        _seampleGui.showFeedbackLabel(inputChecked);
        _seampleGui.showFocusInInputEdit(inputBarHasFocus);
        _seampleGui.showAppropriateColorInputEdit(_inputColorFlag);
    }
}

void GuiControl::showHideView()
{
    QMainWindow* currentInterface;

    if (interfaceIsStandardView())
    {
        currentInterface = &_standardGui;
    }
    else
    {
        currentInterface = &_seampleGui;
    }

    if(interfaceIsCurrentlyShown())
    {
        currentInterface->hide();
        setInterfaceShownFlag(false);
    }
    else
    {
        currentInterface->show();
        currentInterface->activateWindow();
        setInterfaceShownFlag(true);
    }
}

QVector <QString> GuiControl::getTodaysEvents()
{
    return _inputProcessor->run(true, "TODAY");
}

void GuiControl::toShow(QVector <QString> events)
{
    //implement code here to show events retrieved.
}

bool GuiControl::interfaceIsStandardView()
{
    return _standardViewFlag;
}

bool GuiControl::interfaceIsCurrentlyShown()
{
    return _interfaceShownFlag;
}

void GuiControl::setInterfaceShownFlag(bool flag)
{
    _interfaceShownFlag = flag;
}

void GuiControl::emptyResponse()
{
    _inputColorFlag = NONE;

    if (interfaceIsStandardView())
    {
        _standardGui.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
        _standardGui.showAppropriateColorInputEdit(_inputColorFlag);
    }
    else
    {
        _seampleGui.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
        _seampleGui.showAppropriateColorInputEdit(_inputColorFlag);
    }
}

void GuiControl::send(QVector <QString> feedback)
{

    if (interfaceIsStandardView())
    {
        _standardGui.showFeedbackLabel(feedback[0]);
        _standardGui.showAppropriateColorInputEdit(_inputColorFlag);
    }
    else
    {
        _seampleGui.showFeedbackLabel(feedback[0]);
        _seampleGui.showAppropriateColorInputEdit(_inputColorFlag);
    }
}

void GuiControl::setStandardGuiSignals()
{
    //Recieve signal from standardGui to run slot for checking
    //intellisense
    connect(&_standardGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Recieve signal from standardGui to run slot for checking
    //scheduler
    connect(&_standardGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    //Recieve signal from standardGui to run slot for changing views
    connect(&_standardGui,SIGNAL(toSeampleView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));

}

void GuiControl::setSeampleGuiSignals()
{
    //Recieve signal from seampleGui to run slot for checking
    //intellisense
    connect(&_seampleGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Recieve signal from standardGui to run slot for checking
    //scheduler
    connect(&_seampleGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    //Recieve signal from standardGui to run slot for changing views
    connect(&_seampleGui,SIGNAL(toStandardView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));
}

//void GuiControl:: setGlobalSignals()
//{
//    _allShortcuts.setGlobalShortcuts();

//    connect(_allShortcuts.getShowHideViewKey(),SIGNAL(activated()),
//            this,SLOT(showHideView()));
//}

void GuiControl:: createSystemTrayIconIfPossible()
{
    popUp = NULL;
    if (QSystemTrayIcon::isSystemTrayAvailable())
    {
        popUp = new QSystemTrayIcon();
        popUp->show();
    }

    if (popUp != NULL)
    {
        popUp->showMessage("SeamPLE","Welcome To Seample!!!",QSystemTrayIcon::Information, 10000);
    }
}
