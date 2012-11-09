#include "GuiControl.h"

GuiControl* GuiControl::_guiControl = NULL;

const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"Gill Sans Ultra Bold Condensed\" color = \"orange\">"
        "Available Commands: add, delete, mark, unmark, "
        "edit,<br>      find, undo, redo , display </font>";
const QString GuiControl:: MESSAGE_INTELLISENSE_INVALID_RETURN =
        "INTELLISENSE IS NOT WORKING";
const QString GuiControl:: MESSAGE_INVALID_COLOUR_FLAG_RETURN =
        "SEAMPLE NOT RETURNING APPROPRIATE COLOR FLAG";
const QString GuiControl:: MESSAGE_SCHEDULER_INVALID_RETURN =
        "SCHEDULER IS NOT RETURNING ANY OUTPUT";
const QString GuiControl:: MESSAGE_CANNOT_CREATE_SYSTEM_TRAY =
        "SYSTEM TRAY NOT CREATED";
const QString GuiControl:: MESSAGE_GUI_DISPLAY =
        "%123TABLE_SEAMPLE_&987";



GuiControl::GuiControl()
{
    _standardGui = _standardGui->getInstance();
    _seampleGui = _seampleGui->getInstance();
    setStandardGuiSignals();
    setSeampleGuiSignals();
    //setGlobalSignals();
    _faulty = _faulty->getInstance();
    _inputProcessor = Seample::getInstance();
    setInterfaceShownFlag(true);
    _inputColorFlag = NONE;
    getTodaysEvents();
    try
    {
        createSystemTrayIconIfPossible();
    }
    catch (string& error)
    {
        _faulty->report(error);
    }
}

GuiControl::~GuiControl()
{
    _seampleGui->endInstance();
    _standardGui->endInstance();
    _notifyInterface->endInstance();
    _faulty->endInstance();
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
        QVector <QString> output =
                _inputProcessor->run(TO_INTELLISENSE,input.toStdString());
        bool invalidSchedulerReturn = (output.size() < 2);
        qDebug() << "THIS";
        if (invalidSchedulerReturn)
        {
            output.clear();
            output.push_front(MESSAGE_INTELLISENSE_INVALID_RETURN);
            _faulty->report(MESSAGE_INTELLISENSE_INVALID_RETURN.toStdString());
            _inputColorFlag = NONE;
        }
        else
        {
            //Minus 2 because last string holds the colour flag
            bool needStandardView =
                    (output[output.size()-2] == (MESSAGE_GUI_DISPLAY));

            try
            {
                if (implementInputColorFlagFailure((output[output.size()-1])[0]))
                {
                    output.push_front(MESSAGE_INVALID_COLOUR_FLAG_RETURN);
                }
            }
            catch (string& error)
            {
                _faulty->report(error);
            }

            if (needStandardView)
            {
                if (!interfaceIsStandardView())
                {
                    changeView(input,"",true);
                }
                try
                {
                    _standardGui->instantiateTable(output.mid(1,output.size() - 3));
                }
                catch (string& error)
                {
                    _faulty->report(error);
                }
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
        QVector <QString> output =
                _inputProcessor->run(TO_SCHEDULER_AND_RETURN_RESULTS,input.toStdString());
        if (_inputProcessor->requirementsMet())
        {
            int capacity = output.size();
            bool needStandardView =
                    (output[output.size()-1] == (MESSAGE_GUI_DISPLAY));
            _inputColorFlag = NONE;

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
                try
                {
                    _standardGui->instantiateTable(output.mid(1,capacity - 2));
                }
                catch (string& error)
                {
                    _faulty->report(error);
                }
            }
            else
            {
                //Scheduler must send results back. If not, we error handle it
                //to produce an output that informs that no output is returned
                bool invalidSchedulerReturn = (output.size() == 0);

                if (invalidSchedulerReturn)
                {
                    output.push_front(MESSAGE_SCHEDULER_INVALID_RETURN);
                    _faulty->report(MESSAGE_SCHEDULER_INVALID_RETURN.toStdString());
                }

                if (interfaceIsStandardView())
                {
                    _standardGui->resetAllTablesContents();
                }
                sendWithInputEditItem("",output[0]);
            }
        }
    }
}

void GuiControl::changeView(QString input, QString inputChecked, bool inputBarHasFocus)
{
    if (!(_standardGui->interfaceCurrentlyChanging())&&
            !(_seampleGui->interfaceCurrentlyChanging()))
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

void GuiControl::showHelpView()
{
    _standardGui->helpTriggered();
}

void GuiControl::getTodaysEvents()
{
    _standardGui->displayTodayView(
                _inputProcessor->run(TO_SCHEDULER_AND_RETURN_TODAY_EVENTS,""));
    qDebug() << _inputProcessor->run(TO_SCHEDULER_AND_RETURN_TODAY_EVENTS,"");
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

bool GuiControl::implementInputColorFlagFailure(QCharRef colorFlag) throw (string)
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
        throw MESSAGE_INVALID_COLOUR_FLAG_RETURN.toStdString();
    }

    return result;
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
        _standardGui->displayFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
        _standardGui->displayAppropriateColorInputEdit(_inputColorFlag);
    }
    else
    {
        _seampleGui->displayFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
        _seampleGui->displayAppropriateColorInputEdit(_inputColorFlag);
    }
}

void GuiControl::send(QString feedback)
{
    try
    {
        if (interfaceIsStandardView())
        {
            _standardGui->displayFeedbackLabel(feedback);
            _standardGui->displayAppropriateColorInputEdit(_inputColorFlag);
        }
        else
        {
            _seampleGui->displayFeedbackLabel(feedback);
            _seampleGui->displayAppropriateColorInputEdit(_inputColorFlag);
        }
    }
    catch (string& error)
    {
        _faulty->report(error);
    }
}

void GuiControl:: sendWithInputEditItem(QString input,QString feedback)
{
    send(feedback);

    if (interfaceIsStandardView())
    {
        _standardGui->displayFeedbackInputEdit(input);
    }
    else
    {
        _seampleGui->displayFeedbackInputEdit(input);
    }
}

void GuiControl:: sendWithInputEditAndFocus(bool inputBarHasFocus, QString input, QString feedback)
{
    sendWithInputEditItem(input,feedback);

    if (interfaceIsStandardView())
    {
        _standardGui->displayFocusInInputEdit(inputBarHasFocus);
    }
    else
    {
        _seampleGui->displayFocusInInputEdit(inputBarHasFocus);
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

    connect(_standardGui,SIGNAL(todayViewTriggered()),
            this, SLOT(getTodaysEvents()));

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

    //Recieve signal from standardGui to run slot for changing views
    connect(_seampleGui,SIGNAL(getHelpView()),
            this,SLOT(showHelpView()));
}

//void GuiControl:: setGlobalSignals()
//{
//    _allShortcuts.setGlobalShortcuts();

//    connect(_allShortcuts.getShowHideViewKey(),SIGNAL(activated()),
//            this,SLOT(showHideView()));
//}

void GuiControl:: createSystemTrayIconIfPossible() throw (string)
{
    if (QSystemTrayIcon::isSystemTrayAvailable())
    {
        _notifyInterface = _notifyInterface->getInstance();
        //_notifyInterface->showMessage("SeamPLE", "Welcome to Seample. Press \"F1\" for help menu.", QSystemTrayIcon::Information);
    }
    else
    {
        throw MESSAGE_CANNOT_CREATE_SYSTEM_TRAY.toStdString();
    }
}


