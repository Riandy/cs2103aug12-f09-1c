#include "seample.h"

bool Seample::instanceFlag=false;
Seample* Seample::seample=NULL;

void DisplayDate(tm date)
{
    cout<<string("Date : ")<<date.tm_mday;
    cout<<string("/")<<date.tm_mon;
    cout<<string("/")<<date.tm_year;
    cout<<string(" , ");
    cout<<date.tm_hour<<string(":")<<date.tm_min<<endl;
}


void DisplayEvent(Action task)
{
    cout<<string("******************")<<endl;
    cout<<string("Command : ")<<task.getCommand()<<endl;
    DisplayDate(task.getStartDate());
    DisplayDate(task.getEndDate());
    cout<<string("Priority : ")<<task.getPriority()<<endl;
    cout<<string("Event Name : ")<<task.getEventName()<<endl;
    cout<<string("Category : ")<<task.getCategory()<<endl;
    cout<<string("ID : ")<<task.getID()<<endl;
    cout<<string("Date Type: ")<<task.getDateType()<<endl;

    cout<<string("******************")<<endl;
}


Seample::Seample()
{
    intellisense=Intellisense::getInstance();
    _scheduler=scheduler::getInstance();

}

Seample::~Seample()
{
    instanceFlag = false;
}

Seample* Seample::getInstance()
{
    if(!instanceFlag)
    {
        seample=new Seample();
        instanceFlag=true;
        return seample;
    }
    else
    {
        return seample;
    }
}

void Seample::init(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.exec();
}

void Seample::updateUserInput(string userInput)
{
    this->userInput=userInput;
}

QVector <QString> Seample::run(bool runCommand, string _userInput)
{
    userInput = _userInput;
    response = intellisense->check(userInput);
    setShortCutRequirementsMet(_userInput);
    cout<<"Requirements met:"<<intellisense->getrequirementsMet()<<endl;
    if (runCommand && intellisense->getrequirementsMet())
        //only allow action to be sent to scheduler if min req met to reduce check done by scheduler
        //if for user experience we can call upon GUI to erase what user last typed,and indicate with a tick or a cross to simulate sending
    {
        //added adhoc edit code
        if( (response.getCommand()) == "EDIT" )
            response.setCommand("EDITENTER") ;
        //end of adhoc edit code
        feedback = fireAction();
    }
    else
    {

            feedback.push_back(QString::fromStdString(intellisense->getParameter()));
            if (intellisense->getrequirementsMet())
            {
                feedback.push_back("1");
            }
            else
            {
                feedback.push_back("2");
            }
            //added adhoc edit code
            if( (response.getCommand()) == "EDIT" )
            {
                feedback += fireAction(); //append the results at the end
            }

            //end of adhoc edit code


        DisplayEvent(response);//for debugging info only

    }

    QVector <QString> result = feedback;
    feedback.clear();

    return result;
}

QVector <QString> Seample::fireAction()
{
    vector <string> result =_scheduler->executeCommand(response);
cout<<"i am fin here"<<endl;
    return convertQString(result);
}

//Following function is for converting vector of QString
//to QVector of QString
QVector <QString> Seample::convertQString(vector <string> input)
{
    int size = input.size();
    QVector <QString> converted;

    for (int i = 0 ; i < size ; i++)
    {
        converted.push_back(QString::fromStdString(input[i]));
    }

    return converted;
}

void Seample::setShortCutRequirementsMet(string command)
{
    if (command == "undo" || command == "redo" || command == "display")
    {
        intellisense->setRequirementsMet(true);
    }
}
