#include "seample.h"

bool Seample::instanceFlag=false;
Seample* Seample::seample=NULL;
const string Seample::VALIDBOXFLAG = "1";
const string Seample::INVALIDBOXFLAG = "2";
const string Seample::LINEBREAK = "<br>";

//Debugging Functions start
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
//Debugging Functions End
//@author: U094659H
//singleton constructor
Seample::Seample()
{
    intellisense=Intellisense::getInstance();
    _scheduler=scheduler::getInstance();

}
//@author: U094659H
Seample::~Seample()
{
    instanceFlag = false;
}
//@author: U094659H
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
//@PAN WENREN A0083711L
void Seample::updateIntellisenseFeedBack()
{
        feedback.push_back(QString::fromStdString(intellisense->getParameter()));
}
//@PAN WENREN A0083711L
void Seample::normalCommandHandler()
{
    updateIntellisenseFeedBack();
    sendBoxColourFlag();
}
//@PAN WENREN A0083711L
void Seample::sendBoxColourFlag()
{
    if (intellisense->getrequirementsMet())
    {
        feedback.push_back(QString::fromStdString(VALIDBOXFLAG));
    }
    else
    {
        feedback.push_back(QString::fromStdString(INVALIDBOXFLAG));
    }
}
//@PAN WENREN A0083711L
void Seample::editCommandHandler()
{
    feedback += fireAction(); //append the results at the end
    feedback[0] = QString::fromStdString( intellisense->getParameter() + LINEBREAK ) + feedback[0];
    sendBoxColourFlag();

}

//@PAN WENREN A0083711L
void Seample::intellisenseHandler()
{
    if( (response.getCommand()) != Intellisense::EDITCOMMAND )
    {
        normalCommandHandler();
    }

    if( (response.getCommand()) == Intellisense::EDITCOMMAND )
    {
        editCommandHandler();
    }

}
//@PAN WENREN A0083711L
void Seample::interpretEditCommand()
{
    if( (response.getCommand()) == Intellisense::EDITCOMMAND )
        response.setCommand(Intellisense::EDITENTERCOMMAND) ;
}
void Seample::schedulerHandler()
{
    interpretEditCommand();
    feedback = fireAction();
}

//@PAN WENREN A0083711L
void Seample::distributeTasks(Command componentType)
{
    if (componentType == TO_SCHEDULER_AND_RETURN_RESULTS && intellisense->getrequirementsMet())
    {
        schedulerHandler();
    }
    else if (componentType == TO_INTELLISENSE)
    {
        intellisenseHandler();
        DisplayEvent(response); //for debugging info only

    }
    else if (componentType == TO_SCHEDULER_AND_RETURN_TODAY_EVENTS)
    {
        feedback = convertQString(_scheduler->getTodayEvents());
    }
}
//@PAN WENREN A0083711L
void Seample::updateInternalInput(string _userInput)
{
        userInput = _userInput;
}
//@PAN WENREN A0083711L
void Seample::updateResponse()
{
     response = intellisense->check(userInput);
}

//@PAN WENREN A0083711L
QVector <QString> Seample::run(Command componentType, string _userInput)
{
    updateInternalInput(_userInput);
    updateResponse();
    setShortCutRequirementsMet(_userInput);
    distributeTasks(componentType);

    QVector <QString> result = feedback;
    feedback.clear();

    return result;
}

//@author: U094659H
//scheduler to perform a task and return feedback
QVector <QString> Seample::fireAction()
{
    vector <string> result =_scheduler->executeCommand(response);
    return convertQString(result);
}

//@author: U094659H
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

//@LIU WEIYUAN: A0086030R
bool Seample::requirementsMet()
{
    return intellisense->getrequirementsMet();
}

//@LIU WEIYUAN: A0086030R
void Seample::setShortCutRequirementsMet(string input)
{
    QuickCheck evaluate;
    bool inputIsAppropriate = evaluate.shortcutCheck(input);

    if (inputIsAppropriate)
    {
        intellisense->setRequirementsMet(true);
    }
}
