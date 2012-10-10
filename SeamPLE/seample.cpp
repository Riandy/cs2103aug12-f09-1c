#include "seample.h"

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
      qDebug()<<feedback[1];
      cout<<userInput<<endl;
      _view->send(feedback);

  }
