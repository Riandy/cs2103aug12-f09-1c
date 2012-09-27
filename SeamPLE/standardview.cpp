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
}

StandardView::~StandardView()
{
    delete ui;
}

void StandardView:: changeAutoResolution()
{
    this->setWindowState(Qt::WindowMaximized);
}
