#include "GuiControl.h"

const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"MV Boli\" color = \"orange\">"
        "Available Commands: add, delete, mark, unmark, "
        "edit and find</font>";

GuiControl::GuiControl()
{
    setStandardGuiSignals();
    setSeampleGuiSignals();
    _inputProcessor = Seample::getInstance();
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

void GuiControl::setStandardView (bool flag)
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
            output.push_back(input);
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

        //Only commands to hold this should be find and search for now
        if (needStandardView)
        {
            if (!isStandardView())
            {
                changeView("",output[0], inputBarHasFocus);
            }
            else
            {
                _standardGui.showFeedbackInputEdit("");
                _standardGui.showFeedbackLabel(output[0]);
                _standardGui.showFocusInInputEdit(inputBarHasFocus);
            }
            _standardGui.showTableResults(output.mid(1,capacity - 1));
        }
        else
        {
            //Push empty line to the start of the vector. This additional portion
            //is required for send function to output empty line for input line
            output.push_back("");
            bool invalidSchedulerReturn = (output.size() == 1);

            if (invalidSchedulerReturn)
            {
                output.push_front("SCHEDULER IS NOT WORKING");
            }

            send(output);
        }
    }
}

void GuiControl::changeView(QString input, QString inputChecked, bool inputBarHasFocus)
{
    setStandardView(!isStandardView());

    if(isStandardView())
    {
        _seampleGui.hide();
        _standardGui.show();
        _standardGui.showFeedbackInputEdit(input);
        _standardGui.showFeedbackLabel(inputChecked);
        _standardGui.showFocusInInputEdit(inputBarHasFocus);
    }
    else
    {
        _standardGui.hide();
        _seampleGui.show();
        _seampleGui.showFeedbackInputEdit(input);
        _seampleGui.showFeedbackLabel(inputChecked);
        _seampleGui.showFocusInInputEdit(inputBarHasFocus);
    }
}

bool GuiControl::isStandardView()
{
    return _standardViewFlag;
}

void GuiControl::emptyResponse()
{
    if (isStandardView())
    {
        _standardGui.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
    }
    else
    {
        _seampleGui.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
    }
}

void GuiControl::send(QVector <QString> feedback)
{

    if (isStandardView())
    {
        _standardGui.showFeedbackLabel(feedback[0]);
    }
    else
    {
        _seampleGui.showFeedbackLabel(feedback[0]);
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
