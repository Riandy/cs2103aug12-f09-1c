#include "GuiControl.h"

//@author: A0086030R
GuiControl* GuiControl::_guiControl = NULL;

int GuiControl::MINIMUM_SIZE = 2;

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

const string GuiControl::MESSAGE_CHANGING_AT_WRONG_INTERFACE =
        "Changing at inappropriate user inteface. Flag setted wrongly.";


//Constructor is used to set several default signals as well as to
//get the singleton instances of different classes
GuiControl::GuiControl()
{
    _standardGui = _standardGui->getInstance();
    _seampleGui = _seampleGui->getInstance();
    setStandardGuiSignals();
    setSeampleGuiSignals();
    setTimedSignals();
    _faulty = _faulty->getInstance();
    _inputProcessor = Seample::getInstance();
    setInputColourFlag(NONE);
    displayTodaysEvents();
}

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
        parse(input);
    }
}

//This function generates the result from passing a command into the scheduler
//and relays this result to the Gui for display purposes
void GuiControl::passScheduler(QString input, bool inputBarHasFocus)
{
    bool emptyInput = (input.size() == 0);

    if (emptyInput)
    {
        emptyResponse();
    }
    else
    {
        execute(input, inputBarHasFocus);
    }
}

//Function to toggle the GUI interface being displayed
void GuiControl::toggleView(QString input, QString inputChecked,
                            bool inputBarHasFocus)
{
    bool allInterfaceNotCurrentlyChanging =
            !(_standardGui->interfaceCurrentlyChanging())&&
            !(_seampleGui->interfaceCurrentlyChanging());

    if (allInterfaceNotCurrentlyChanging)
    {
        setStandardViewFlag(!interfaceIsStandardView());
        updateInterface(input,inputChecked,inputBarHasFocus);
    }
}

//Function is called by _seampleGui when f1 or ctrl-1 shortcuts are entered.
//Triggers help interface to appear
void GuiControl::showHelpView()
{
    _standardGui->helpTriggered();
}

//Function displays the day's events through _standardGui
void GuiControl::displayTodaysEvents()
{
    QVector <QString> todayItems =
            _inputProcessor->run(TO_SCHEDULER_AND_RETURN_TODAY_EVENTS,"");

    _standardGui->displayTodayView(todayItems);
}

//Make any changes to interface if the flag is set at a different value
void GuiControl::updateInterface(QString input, QString inputChecked,
                     bool inputBarHasFocus)
{
    if(interfaceIsStandardView())
    {
        showOnlyStandardView(input,inputChecked,inputBarHasFocus);
    }
    else
    {
        showOnlySeampleView(input,inputChecked,inputBarHasFocus);
    }
}

void GuiControl::showOnlySeampleView(QString input, QString inputChecked,
                                        bool inputBarHasFocus)
{
    //Defensive programming in case flag is not set to seample view
    if (!interfaceIsStandardView())
    {
        _standardGui->hide();
        _seampleGui->show();
        sendWithInputEditAndFocus(inputBarHasFocus, input, inputChecked);
    }
    else
    {
        _faulty->report(MESSAGE_CHANGING_AT_WRONG_INTERFACE);
    }
}

void GuiControl::showOnlyStandardView(QString input, QString inputChecked,
                                         bool inputBarHasFocus)
{
    //Defensive programming in case flag is not set to standard view
    if (interfaceIsStandardView())
    {
        _seampleGui->hide();
        _standardGui->show();
        sendWithInputEditAndFocus(inputBarHasFocus, input, inputChecked);
    }
    else
    {
        _faulty->report(MESSAGE_CHANGING_AT_WRONG_INTERFACE);
    }
}

void GuiControl::execute(QString input, bool inputBarHasFocus)
{
    QVector <QString> output = _inputProcessor->run(
                TO_SCHEDULER_AND_RETURN_RESULTS,
                input.toStdString());

    if (_inputProcessor->requirementsMet())
    {
        interpretResults(output, inputBarHasFocus);
    }
}

void GuiControl::interpretResults(QVector <QString> output,
                                  bool inputBarHasFocus)
{
    bool needStandardView = checkStandardViewRequired(output);
    setInputColourFlag(NONE);

    if (needStandardView)
    {
        processStandardViewForScheduler(output,inputBarHasFocus);
    }
    else
    {
        processAnyViewForScheduler(output);
    }
}

//Function for processing results from scheduler to be displayed in
//standard view
void GuiControl::processStandardViewForScheduler(QVector <QString> output,
                                                 bool inputBarHasFocus)
{
    int capacity = output.size();

    if (interfaceIsStandardView())
    {
        sendWithInputEditAndFocus(inputBarHasFocus,MESSAGE_EMPTY,
                                  output[0]);
    }
    else
    {
        toggleView(MESSAGE_EMPTY,output[0], inputBarHasFocus);
    }
    try
    {
        //Start from position one as the feedback for the user is
        //at position 0. Amount to copy has a deduction of 2 as
        //the last position is the code flag, and the feedback
        //position is not included for the copy
        displayStandardMultipleResults(output.mid(1,capacity - 2));
    }
    catch (string& error)
    {
        _faulty->report(error);
    }
}

//Process minimum results from scheduler that any view can show
void GuiControl::processAnyViewForScheduler(QVector <QString> output)
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

void GuiControl::parse(QString input)
{
    QVector <QString> output =
            _inputProcessor->run(TO_INTELLISENSE,input.toStdString());

    bool invalidIntellisenseReturn = (output.size() < MINIMUM_SIZE);
    if (invalidIntellisenseReturn)
    {
        output = getInvalidIntellisenseFeedback();
    }
    else
    {
        processInputBarColour(output);
        processForStandardView(output, input);
    }
    send(output[0]);
}

QVector <QString> GuiControl:: getInvalidIntellisenseFeedback()
{
    QVector <QString> feedback;
    feedback.push_front(MESSAGE_INTELLISENSE_INVALID_RETURN);
    _faulty->report(MESSAGE_INTELLISENSE_INVALID_RETURN.toStdString());
    setInputColourFlag(NONE);

    return feedback;
}

//Process the input bar colour from the QString flag
void GuiControl::processInputBarColour(QVector <QString> output)
{
    try
    {
        QCharRef flag = getInputColorFlag(output);
        if (implementInputColorFlagFailure(flag))
        {
            output.push_front(MESSAGE_INVALID_COLOUR_FLAG_RETURN);
        }
    }
    catch (string& error)
    {
        _faulty->report(error);
    }
}

//Process intellisense results for standard view
void GuiControl::processForStandardView(QVector<QString> output,QString input)
{
    bool needStandardView = (output[output.size()-MINIMUM_SIZE]
                             == (MESSAGE_GUI_DISPLAY));
    if (needStandardView)
    {
        if (!interfaceIsStandardView())
        {
            bool inputBarFocus = true;
            toggleView(input,MESSAGE_EMPTY,inputBarFocus);
        }
        //Start from position one as the feedback for the user is
        //at position 0. Amount to copy has a deduction of 3 as
        //the last position is the colour flag, the second last
        //position is the code flag, andalso of the feedback being
        //in the first position
        displayStandardMultipleResults(output.mid(1,output.size()-3));
    }
    else
    {
        _standardGui->resetAllTablesContents();
    }
}

void GuiControl::displayStandardMultipleResults(QVector <QString> results)
{
    try
    {
        _standardGui->instantiateTable(results);
    }
    catch (string& error)
    {
        _faulty->report(error);
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

//Function checks if the flag sent in to implement the text bar colour is valid
//A bool value corresponding to the validity is sent back and the colour is
//resetted to NONE for invalid colour flags
bool GuiControl::implementInputColorFlagFailure(
        QCharRef colorFlag) throw (string)
{
    bool result;
    bool colorFlagPresent = colorFlag.isDigit();

    if (colorFlagPresent)
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
            this,SLOT(toggleView(QString, QString, bool)));

    connect(_standardGui,SIGNAL(todayViewTriggered()),
            this, SLOT(displayTodaysEvents()));
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
            this,SLOT(toggleView(QString, QString, bool)));

    connect(_seampleGui,SIGNAL(getHelpView()),
            this,SLOT(showHelpView()));
}

//Function set all required signals from the time tracker the slots there are
//supposed to run periodically
void GuiControl:: setTimedSignals()
{
    connect(&_timeControl,SIGNAL(oneMinuteTrigger()),
            this, SLOT(displayTodaysEvents()));
}

//Function returns a bool value if the scheduler results needs to
//be displayed fully in standardview or not
bool GuiControl::checkStandardViewRequired(QVector <QString> output)
{
    bool needStandardView = (output[output.size()-1] == MESSAGE_GUI_DISPLAY);
    bool needWhenAtStandardView =
            (output[output.size()-1] == MESSAGE_ONLY_STAN_GUI_DISPLAY
             && interfaceIsStandardView());
    bool standardViewRequired = needStandardView || needWhenAtStandardView;

    return standardViewRequired;
}

//Function returns the input color flag from the QVector of
//QStrings returned from seample
QCharRef GuiControl::getInputColorFlag(QVector <QString> output)
{
    return ((output[output.size()-1])[0]);
}


