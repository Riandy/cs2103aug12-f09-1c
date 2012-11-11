#include "GuiControl.h"

//@WEIYUAN A0086030R
GuiControl* GuiControl::_guiControl = NULL;

const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"Gill Sans Ultra Bold Condensed\" color ="
        "\"orange\"> Available Commands: add, delete, mark, unmark, "
        "edit,<br>find, undo, redo , display </font>";
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
const QString GuiControl:: MESSAGE_ONLY_STAN_GUI_DISPLAY =
        "%987TABLE_SEAMPLE_&123";

const QString GuiControl:: MESSAGE_EMPTY = "";

//Constructor is used to set several default signals as well as to
//get the singleton instances of different classes
GuiControl::GuiControl()
{
    _standardGui = _standardGui->getInstance();
    _seampleGui = _seampleGui->getInstance();
    setStandardGuiSignals();
    setSeampleGuiSignals();
    setTimedSignals();
    //setGlobalSignals();
    _faulty = _faulty->getInstance();
    _inputProcessor = Seample::getInstance();
    //setInterfaceShownFlag(true);
    setInputColourFlag(NONE);
    getTodaysEvents();
}

//Destructor is called to end the instances of the singletons
GuiControl::~GuiControl()
{
    _seampleGui->endInstance();
    _standardGui->endInstance();
    _faulty->endInstance();
}

//This function supports this class as a singleton. Creates only a
//dynamically allocated version of itself if it has not been created
//yet
GuiControl* GuiControl::getInstance()
{
    if (!singleInstanceExists())
    {
        _guiControl = new GuiControl();
    }

    return _guiControl;
}

//This function supports the class as a singleton which assist in the
//removal of the dynamically allocated singleton
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

        if (invalidSchedulerReturn)
        {
            output.clear();
            output.push_front(MESSAGE_INTELLISENSE_INVALID_RETURN);
            _faulty->report(MESSAGE_INTELLISENSE_INVALID_RETURN.toStdString());
            setInputColourFlag(NONE);
        }
        else
        {
            //Minus 2 because last string holds the colour flag, and the
            //second last flag is the code for parser to request Gui to display
            //the contents in a table
            bool needStandardView =
                    (output[output.size()-2] == (MESSAGE_GUI_DISPLAY));

            try
            {
                QCharRef flag = ((output[output.size()-1])[0]);
                if (implementInputColorFlagFailure(flag))
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
                    bool inputBarFocus = true;
                    changeView(input,MESSAGE_EMPTY,inputBarFocus);
                }
                try
                {
                    QVector <QString> results = output.mid(1,output.size()-3);
                    _standardGui->instantiateTable(results);
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

//This function generates the result from passing a command into the scheduler
//and relays this result to the Gui for display purposes
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
        QVector <QString> output = _inputProcessor->run(
                    TO_SCHEDULER_AND_RETURN_RESULTS,
                    input.toStdString());

        if (_inputProcessor->requirementsMet())
        {
            int capacity = output.size();
            bool needStandardView =
                    (output[output.size()-1] == MESSAGE_GUI_DISPLAY) ||
                    (output[output.size()-1] == MESSAGE_ONLY_STAN_GUI_DISPLAY
                     && interfaceIsStandardView());

            setInputColourFlag(NONE);

            if (needStandardView)
            {
                if (!interfaceIsStandardView())
                {
                    changeView(MESSAGE_EMPTY,output[0], inputBarHasFocus);
                }
                else
                {
                    sendWithInputEditAndFocus(inputBarHasFocus,MESSAGE_EMPTY,
                                              output[0]);
                }
                try
                {
                    QVector <QString> results = output.mid(1,capacity - 2);
                    _standardGui->instantiateTable(results);
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
                    _faulty->report(
                                MESSAGE_SCHEDULER_INVALID_RETURN.
                                toStdString());
                }

                if (interfaceIsStandardView())
                {
                    _standardGui->resetAllTablesContents();
                }
                sendWithInputEditItem(MESSAGE_EMPTY,output[0]);
            }
        }
    }
}

//Function to change the GUI interface being displayed
void GuiControl::changeView(QString input, QString inputChecked,
                            bool inputBarHasFocus)
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

////Function toggles between whether the application is minimised through a
////shortcut orcurrently shown.
//void GuiControl::showHideView()
//{
//    QMainWindow* currentInterface;

//    if (interfaceIsStandardView())
//    {
//        currentInterface = _standardGui;
//    }
//    else
//    {
//        currentInterface = _seampleGui;
//    }

//    if(interfaceIsCurrentlyShown())
//    {
//        currentInterface->hide();
//        setInterfaceShownFlag(false);
//    }
//    else
//    {
//        currentInterface->show();
//        currentInterface->activateWindow();
//        setInterfaceShownFlag(true);
//    }
//}

//Function is called by _seampleGui when f1 or ctrl-1 shortcuts are entered.
//Triggers help interface to appear
void GuiControl::showHelpView()
{
    _standardGui->helpTriggered();
}
\
//Function displays the day's events through _standardGui
void GuiControl::getTodaysEvents()
{
    _standardGui->displayTodayView(
                _inputProcessor->run(TO_SCHEDULER_AND_RETURN_TODAY_EVENTS,""));
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

//Function checks if the flag sent in to implement the text bar colour is valid
//A bool value corresponding to the validity is sent back and the colour is
//resetted to NONE for invalid colour flags
bool GuiControl::implementInputColorFlagFailure(
        QCharRef colorFlag) throw (string)
{
    bool result;

    if (colorFlag.isDigit())
    {
        setInputColourFlag( (InputBarFlag) colorFlag.digitValue());
        result = false;
    }
    else
    {
        setInputColourFlag(NONE);
        result = true;
        throw MESSAGE_INVALID_COLOUR_FLAG_RETURN.toStdString();
    }

    return result;
}

bool GuiControl::interfaceIsStandardView()
{
    return _standardViewFlag;
}

////Function returns a bool value on whether interface is minimised or running
//bool GuiControl::interfaceIsCurrentlyShown()
//{
//    return _interfaceShownFlag;
//}

////Function sets the boolean value for _interfaceShownFlag given a boolean
////parameter
//void GuiControl::setInterfaceShownFlag(bool flag)
//{
//    _interfaceShownFlag = flag;
//}

void GuiControl::setInputColourFlag(InputBarFlag flag)
{
    _inputColorFlag = flag;
}

//Function returns a "empty response", which is basically what is displayed
//to the user when nothing is typed in the text input bar. It comprises of
//an advisory message to guide the user in using the program
void GuiControl::emptyResponse()
{
    setInputColourFlag(NONE);

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

//Function sends logic components' feedback to the GUI that is currently
//displayed so that it can be shown to the user
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

//Function is an advanced form of the send function. It includes the showing
//of feedback in the input bar of the GUIs. This is normally used for flushing
//the input bars
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

//Function is an advanced form of sendWithInputEditItem with the addition of
//the overwritting of focus for the input bar of both GUIs.
void GuiControl:: sendWithInputEditAndFocus(bool inputBarHasFocus,
                                            QString input, QString feedback)
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

//Function set all required signals from _standardGui to local slots in
//this class
void GuiControl::setStandardGuiSignals()
{
    connect(_standardGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    connect(_standardGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    connect(_standardGui,SIGNAL(toSeampleView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));

    connect(_standardGui,SIGNAL(todayViewTriggered()),
            this, SLOT(getTodaysEvents()));
}

//Function set all required signals from _seampleGui to local slots in
//this class
void GuiControl::setSeampleGuiSignals()
{
    connect(_seampleGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    connect(_seampleGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    connect(_seampleGui,SIGNAL(toStandardView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));

    connect(_seampleGui,SIGNAL(getHelpView()),
            this,SLOT(showHelpView()));
}

//Function set all required signals from the time tracker the slots there are
//supposed to run periodically
void GuiControl:: setTimedSignals()
{
    connect(&_timeControl,SIGNAL(oneMinuteTrigger()),
            this, SLOT(getTodaysEvents()));
}

////Function set global shortcut signals from shortcuts class to local slots in
////this class
//void GuiControl:: setGlobalSignals()
//{
//    _allShortcuts.setGlobalShortcuts();

//    connect(_allShortcuts.getShowHideViewKey(),SIGNAL(activated()),
//            this,SLOT(showHideView()));
//}




