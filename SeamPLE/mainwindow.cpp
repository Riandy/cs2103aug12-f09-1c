#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changeGeometry();
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

MainWindow::~MainWindow()
{
    delete ui;
}

//Function to change GUI interface label to contain output string
void MainWindow::showFeedbackLabel(QString output)
{
    ui->label->setText(output);
}

//Function to change GUI interface label to contain output string
void MainWindow::showFeedbackInputEdit(QString output)
{
    ui->lineEdit->setText(output);
}

void MainWindow::recieve(QString input)
{
    emit relay(input);
}

void MainWindow::enterTriggered()
{
    emit run(ui->lineEdit->text());
}

void MainWindow::changeViewTriggered()
{
    emit toStandardView();
}

void MainWindow:: changeGeometry()
{
    this->setWindowState(Qt::WindowMaximized);
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    this->ui->frame->setGeometry(getPosX(sample.bottomRight().x()),
                                 getPosY(sample.bottomRight().y()),
                                 this->ui->frame->width(),
                                 this->ui->frame->height());
}

int MainWindow:: getPosX(int maxX)
{
    return maxX - this->ui->frame->width();
}

int MainWindow:: getPosY(int maxY)
{
    return maxY - this->ui->frame->height();
}
