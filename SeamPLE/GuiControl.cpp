#include "GuiControl.h"
#include "seample.h"



const QString GuiControl::MESSAGE_AVAILABLE_COMMANDS =
        "<font size=3 face=\"MV Boli\" color = \"orange\">"
        "Available Commands: add, delete, mark, unmark, "
        "edit and find</font>";

GuiControl::GuiControl(QObject *parent) :
    QObject(parent)
{


    //Connecting local slot to signal for text input
    //generated by Standard UI
    connect(&standard,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Connecting local slot to signal for text input
    //generated by Seample UI
    connect(&seample,SIGNAL(relay(QString)),
            this,SLOT(check(QString)));

    //Connecting local slot to signal for text input
    //generated by Standard UI when enter key is pressed
    connect(&standard,SIGNAL(run(QString)),
            this,SLOT(passScheduler(QString)));

    //Connecting local slot to signal for text input
    //generated by Seample UI when enter key is pressed
    connect(&seample,SIGNAL(run(QString)),
            this,SLOT(passScheduler(QString)));

    //Connecting local slot to signal generated when a
    //button is pressed to change the UI interface.
    connect(&standard,SIGNAL(toSeampleView()),
            this,SLOT(changeView()));

    //Connecting local slot to signal generated when a
    //button is pressed to change the UI interface.
    connect(&seample,SIGNAL(toStandardView()),
            this,SLOT(changeView()));
}


void GuiControl::init(Seample *_app)
{
    this->app=_app;
}

void GuiControl:: showGui()
{
    if (standardViewFlag)
    {
        standard.show();
    }
    else
    {
        seample.show();
    }
}

void GuiControl::setStandardView (bool flag)
{
    standardViewFlag = flag;
}



bool GuiControl::isStandardView()
{
    return standardViewFlag;
}

//This function is for recieving input from user and sending
//into intellisense class to interpret the text input. The
//feedback is generated to the user
void GuiControl::check(QString input)
{
    //qDebug() << input;

    bool emptyInput = (input.size() == 0);

    if (emptyInput)
    {
        emptyResponse();
    }
    else
    {
        QString inputToIntellisense=input;
        //cout<<inputToIntellisense.toLocal8Bit().constData()<<endl;
        this->app->run(inputToIntellisense.toLocal8Bit().constData());
    }




}

void GuiControl::passScheduler(QString input)
{
    //Code to be implemented here to be sent into  scheduler classes
    qDebug() << "found";
}

void GuiControl::changeView()
{
    setStandardView(!isStandardView());

    if(isStandardView())
    {
        seample.hide();
        standard.show();
    }
    else
    {
        standard.hide();
        seample.show();
    }
}

void GuiControl::emptyResponse()
{
    if (isStandardView())
    {
        standard.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
    }
    else
    {
        seample.showFeedbackLabel(MESSAGE_AVAILABLE_COMMANDS);
    }
}

void GuiControl::send(QVector <QString> feedback)
{
    if (isStandardView())
    {
        standard.showFeedbackLabel(feedback[0]);
        standard.showFeedbackInputEdit(feedback[1]);
    }
    else
    {
        seample.showFeedbackLabel(feedback[0]);
        seample.showFeedbackInputEdit(feedback[1]);
    }
}

void GuiControl::feedback(QString feedback)
{
    if (isStandardView())
    {
        standard.showFeedbackLabel(feedback);

    }
    else
    {
        seample.showFeedbackLabel(feedback);

    }
}
