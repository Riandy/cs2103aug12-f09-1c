#include "GuiControl.h"

GuiControl* GuiControl::_guiControl = NULL;

const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"MV Boli\" color = \"orange\">"
        "Available Commands: add, delete, mark, unmark, "
        "edit and find</font>";
const QString GuiControl:: MESSAGE_INTELLISENSE_INVALID_RETURN =
        "INTELLISENSE IS NOT WORKING";
const QString GuiControl:: MESSAGE_INVALID_COLOUR_FLAG_RETURN =
        "SEAMPLE NOT RETURNING APPROPRIATE COLOR FLAG";
const QString GuiControl:: MESSAGE_SCHEDULER_INVALID_RETURN =
        "SCHEDULER IS NOT RETURNING ANY OUTPUT";

GuiControl::GuiControl()
{
    _standardGui = _standardGui->getInstance();
    _seampleGui = _seampleGui->getInstance();
    setStandardGuiSignals();
    setSeampleGuiSignals();
    //setGlobalSignals();
    _inputProcessor = Seample::getInstance();
    setInterfaceShownFlag(true);
    _inputColorFlag = NONE;
    createSystemTrayIconIfPossible();
    //QVector <QString> events = getTodaysEvents();
    //toShow(events);
    //timekeep.init(this->popUp);
    //timekeep.start();
}

GuiControl::~GuiControl()
{
    _seampleGui->endInstance();
    _standardGui->endInstance();
    _notifyInterface->endInstance();
}

GuiControl* GuiControl::getInstance()
{
    if (!singleInstanceExists())
    {
        _guiControl = new GuiControl();
    }

    return _guiControl;
}

void GuiControl::endInstance()
{
    if (singleInstanceExists())
    {
        delete _guiControl;
        _guiControl = NULL;
    }
}

void GuiControl:: showGui()
{   
    if (interfaceIsStandardView())
    {
        _standardGui->show();
    }
    else
    {
        _seampleGui->show();
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
            output.push_front(MESSAGE_INTELLISENSE_INVALID_RETURN);
            _inputColorFlag = NONE;
        }
        else
        {
            if (implementInputColorFlagFailure((output[1])[0]))
            {
                output.push_front(MESSAGE_INVALID_COLOUR_FLAG_RETURN);
            }
        }
        send(output[0]);
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
        bool needStandardView = (capacity>1);
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
                sendWithInputEditAndFocus(inputBarHasFocus,"",output[0]);
            }
            _standardGui->showTableResults(output.mid(1,capacity - 1));
        }
        else
        {
            //Scheduler must send results back. If not, we error handle it
            //to produce an output that informs that no output is returned
            bool invalidSchedulerReturn = (output.size() == 0);

            if (invalidSchedulerReturn)
            {
                output.push_front(MESSAGE_SCHEDULER_INVALID_RETURN);
            }

            if (interfaceIsStandardView())
            {
                _standardGui->resetTableContents();
            }

            sendWithInputEditItem("",output[0]);
        }
    }
}

void GuiControl::changeView(QString input, QString inputChecked, bool inputBarHasFocus)
{
    setStandardViewFlag(!interfaceIsStandardView());

    if(interfaceIsStandardView())
    {
        _seampleGui->hide();
        _standardGui->show();
        sendWithInputEditAndFocus(inputBarHasFocus, input, inputChecked);
    }
    else
    {
        _standardGui->hide();
        _seampleGui->show();
        sendWithInputEditAndFocus(inputBarHasFocus, input, inputChecked);
    }
}

void GuiControl::showHideView()
{
    QMainWindow* currentInterface;

    if (interfaceIsStandardView())
    {
        currentInterface = _standardGui;
    }
    else
    {
        currentInterface = _seampleGui;
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

bool GuiControl:: singleInstanceExists()
{
    bool result;

    if (_guiControl == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

bool GuiControl::implementInputColorFlagFailure(QCharRef colorFlag)
{
    bool result;

    if (colorFlag.isDigit())
    {
        _inputColorFlag = (InputBarFlag) colorFlag.digitValue();
        result = false;
    }
    else
    {
        _inputColorFlag = NONE;
        result = true;
    }

    return result;
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
        _standardGui->showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
        _standardGui->showAppropriateColorInputEdit(_inputColorFlag);
    }
    else
    {
        _seampleGui->showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
        _seampleGui->showAppropriateColorInputEdit(_inputColorFlag);
    }
}

void GuiControl::send(QString feedback)
{
    if (interfaceIsStandardView())
    {
        _standardGui->showFeedbackLabel(feedback);
        _standardGui->showAppropriateColorInputEdit(_inputColorFlag);
    }
    else
    {
        _seampleGui->showFeedbackLabel(feedback);
        _seampleGui->showAppropriateColorInputEdit(_inputColorFlag);
    }
}

void GuiControl:: sendWithInputEditItem(QString input,QString feedback)
{
    send(feedback);

    if (interfaceIsStandardView())
    {
        _standardGui->showFeedbackInputEdit(input);
    }
    else
    {
        _seampleGui->showFeedbackInputEdit(input);
    }
}

void GuiControl:: sendWithInputEditAndFocus(bool inputBarHasFocus, QString input, QString feedback)
{
    sendWithInputEditItem(input,feedback);

    if (interfaceIsStandardView())
    {
        _standardGui->showFocusInInputEdit(inputBarHasFocus);
    }
    else
    {
        _seampleGui->showFocusInInputEdit(inputBarHasFocus);
    }
}

void GuiControl::setStandardGuiSignals()
{
    //Recieve signal from standardGui to run slot for checking
    //intellisense
    connect(_standardGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Recieve signal from standardGui to run slot for checking
    //scheduler
    connect(_standardGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    //Recieve signal from standardGui to run slot for changing views
    connect(_standardGui,SIGNAL(toSeampleView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));

}

void GuiControl::setSeampleGuiSignals()
{
    //Recieve signal from seampleGui to run slot for checking
    //intellisense
    connect(_seampleGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Recieve signal from standardGui to run slot for checking
    //scheduler
    connect(_seampleGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    //Recieve signal from standardGui to run slot for changing views
    connect(_seampleGui,SIGNAL(toStandardView(QString, QString, bool)),
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
    if (QSystemTrayIcon::isSystemTrayAvailable())
    {
        _notifyInterface = _notifyInterface->getInstance();
        _notifyInterface->showMessage("SeamPLE", "(>^.^)> MEOW <(^.^<)", QSystemTrayIcon::Information);
    }
}


