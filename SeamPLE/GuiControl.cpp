#include "GuiControl.h"

const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"MV Boli\" color = \"orange\">"
        "Available Commands: add, delete, mark, unmark, "
        "edit and find</font>";

GuiControl::GuiControl(QObject *parent) :
    QObject(parent)
{
    setStandardGuiSignals();
    setSeampleGuiSignals();
}

void GuiControl:: showGui()
{
    if (standardViewFlag)
    {
        standardGui.show();
    }
    else
    {
        seampleGui.show();
    }
}

void GuiControl::setStandardView (bool flag)
{
    standardViewFlag = flag;
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
        QVector <QString> output = inputProcessor.run(command,input.toStdString());
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
        QVector <QString> output = inputProcessor.run(command,input.toStdString());
        bool needStandardView = (output.size()>2);

        //Only commands to hold this should be find and search for now
        if (needStandardView)
        {
            if (!isStandardView())
            {
                changeView("",output[0], inputBarHasFocus);
            }
            else
            {
                standardGui.showFeedbackInputEdit("");
                standardGui.showFeedbackLabel(output[0]);
                standardGui.showFocusInInputEdit(inputBarHasFocus);
            }
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
        seampleGui.hide();
        standardGui.show();
        standardGui.showFeedbackInputEdit(input);
        standardGui.showFeedbackLabel(inputChecked);
        standardGui.showFocusInInputEdit(inputBarHasFocus);
    }
    else
    {
        standardGui.hide();
        seampleGui.show();
        seampleGui.showFeedbackInputEdit(input);
        seampleGui.showFeedbackLabel(inputChecked);
        seampleGui.showFocusInInputEdit(inputBarHasFocus);
    }
}

bool GuiControl::isStandardView()
{
    return standardViewFlag;
}

void GuiControl::emptyResponse()
{
    if (isStandardView())
    {
        standardGui.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
    }
    else
    {
        seampleGui.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
    }
}

void GuiControl::send(QVector <QString> feedback)
{

    if (isStandardView())
    {
        standardGui.showFeedbackLabel(feedback[0]);
        standardGui.showFeedbackInputEdit(feedback[1]);
    }
    else
    {
        seampleGui.showFeedbackLabel(feedback[0]);
        seampleGui.showFeedbackInputEdit(feedback[1]);
    }
}

void GuiControl::setStandardGuiSignals()
{
    //Recieve signal from standardGui to run slot for checking
    //intellisense
    connect(&standardGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Recieve signal from standardGui to run slot for checking
    //scheduler
    connect(&standardGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    //Recieve signal from standardGui to run slot for changing views
    connect(&standardGui,SIGNAL(toSeampleView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));

}

void GuiControl::setSeampleGuiSignals()
{
    //Recieve signal from seampleGui to run slot for checking
    //intellisense
    connect(&seampleGui,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Recieve signal from standardGui to run slot for checking
    //scheduler
    connect(&seampleGui,SIGNAL(run(QString, bool)),
            this,SLOT(passScheduler(QString, bool)));

    //Recieve signal from standardGui to run slot for changing views
    connect(&seampleGui,SIGNAL(toStandardView(QString, QString, bool)),
            this,SLOT(changeView(QString, QString, bool)));
}
