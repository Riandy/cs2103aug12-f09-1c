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
    GuiControl view;
    _view=&view;
    view.init(this);
    view.setStandardView(false);
    view.showGui();

    a.exec();
}

 void Seample::updateUserInput(string userInput)
 {
     this->userInput=userInput;
 }

  void Seample::run(string _userInput)
  {
      userInput=_userInput;


      response=intellisense.check(userInput);
      feedback.push_back(QString::fromUtf8(intellisense.getParameter().c_str()));
      feedback.push_back("");
      qDebug()<<feedback[0];
      DisplayEvent(response);
      _view->feedback(feedback[0]);
      feedback.clear();

  }
