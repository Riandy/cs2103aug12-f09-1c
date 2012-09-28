#include "standardview.h"
#include "ui_standardview.h"

StandardView::StandardView(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
    ui(new Ui::StandardView)
{
    //Default settings according to UI form
    ui->setupUi(this);
    changeAutoResolution();

    //To make pri window transparent as focus is on
    //sec window
    this->setAttribute(Qt::WA_TranslucentBackground, true);


    connect(ui->lineEdit,SIGNAL(textEdited(const QString&)),
            this,SLOT(recieve(QString)));

    connect(ui->lineEdit,SIGNAL(returnPressed()),
            this,SLOT(enterTriggered()));

    connect(ui->pushButton_2,SIGNAL(clicked()),
            this,SLOT(changeViewTriggered()));
}

StandardView::~StandardView()
{
    delete ui;
}

void StandardView::showFeedbackLabel(QString output)
{
    ui->label->setText(output);
}

void StandardView::showFeedbackInputEdit(QString output)
{
    ui->lineEdit->setText(output);
}

void StandardView::recieve(QString input)
{
    emit relay(input);
}

void StandardView::enterTriggered()
{
    emit run(ui->lineEdit->text());
}

void StandardView::changeViewTriggered()
{
    emit toSeampleView();
}

void StandardView:: changeAutoResolution()
{
    this->setWindowState(Qt::WindowMaximized);
}

