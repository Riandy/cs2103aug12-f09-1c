#include "seample.h"


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
    //cout<<string("Req Met : ")<<task.getrequirementsMet()<<endl;
    cout<<string("******************")<<endl;
}


Seample::Seample()
{

}

void Seample::init(int argc, char *argv[])
{
    QApplication a(argc, argv);
    scheduler scheduler;
    _scheduler = &scheduler;
    this->_scheduler->init(this);
    a.exec();
}

 void Seample::updateUserInput(string userInput)
 {
     this->userInput=userInput;
 }

 QVector <QString> Seample::run(bool runCommand, string _userInput)
 {
     userInput=_userInput;
     response=intellisense.check(userInput);

     if (runCommand)
     {
          fireAction();
     }
     else
     {
         feedback.push_back(QString::fromStdString(intellisense.getParameter()));

         //Following line is running the input back to GUI. Needs to be
         //replaced by feedback string later
         feedback.push_back(QString::fromStdString(_userInput));
         qDebug()<<feedback[1];
         DisplayEvent(response);

     }

     QVector <QString> result = feedback;
     feedback.clear();

     return result;
 }

 QVector <QString> Seample::fireAction()
 {
     vector <string> result =_scheduler->executeCommand(response);
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
