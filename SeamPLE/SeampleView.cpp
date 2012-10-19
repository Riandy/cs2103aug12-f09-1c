#include "SeampleView.h"
#include "ui_SeampleView.h"

SeampleView::SeampleView(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
    ui(new Ui::SeampleView)
{
    ui->setupUi(this);
    changeGeometry();

    //To make pri window transparent as focus is on
    //sec window
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    _allShortcuts.setShortcutsTo(this);
    setSignals();

    //Prevent change view push button from snatching focus
    //from input line
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
}

SeampleView::~SeampleView()
{
    delete ui;
}

//Function to change GUI interface label to contain output string
void SeampleView::showFeedbackLabel(QString output)
{
    ui->label->setText(output);
}

//Function to change GUI interface label to contain output string
void SeampleView::showFeedbackInputEdit(QString output)
{
    ui->lineEdit->setText(output);
}

void SeampleView:: showFocusInInputEdit (bool focus)
{
    ui->lineEdit->setFocusInput(focus);
}

void SeampleView::recieve(QString input)
{
    emit relay(input);
}

void SeampleView::enterTriggered()
{
    emit run(ui->lineEdit->text(), ui->lineEdit->getFocusInput());
}

void SeampleView::changeViewTriggered()
{
    emit toStandardView(ui->lineEdit->text(), ui->label->text(), ui->lineEdit->getFocusInput());
}

void SeampleView::undoTriggered()
{
    //emit run("undo", ui->lineEdit->getFocusInput());
}

void SeampleView::redoTriggered()
{
    //emit run("redo", ui->lineEdit->getFocusInput());
}

void SeampleView::addTriggered()
{
    ui->lineEdit->setText("add ");
    ui->lineEdit->setFocusInput(true);
}

void SeampleView::findTriggered()
{
    ui->lineEdit->setText("find ");
    ui->lineEdit->setFocusInput(true);
}

void SeampleView::displayTriggered()
{
    emit run("display", ui->lineEdit->getFocusInput());
}

void SeampleView::deleteTriggered()
{
    ui->lineEdit->setText("delete ");
    ui->lineEdit->setFocusInput(true);
}

void SeampleView::editTriggered()
{
    ui->lineEdit->setText("edit ");
    ui->lineEdit->setFocusInput(true);
}

void SeampleView:: changeGeometry()
{
    this->setWindowState(Qt::WindowMaximized);
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    this->ui->frame->setGeometry(getPosX(sample.bottomRight().x()),
                                 getPosY(sample.bottomRight().y()),
                                 this->ui->frame->width(),
                                 this->ui->frame->height());
}

int SeampleView:: getPosX(int maxX)
{
    return maxX - this->ui->frame->width();
}

int SeampleView:: getPosY(int maxY)
{
    return maxY - this->ui->frame->height();
}

void SeampleView:: setSignals()
{
    connect(ui->lineEdit,SIGNAL(textEdited(const QString&)),
            this,SLOT(recieve(QString)));

    connect(ui->lineEdit,SIGNAL(returnPressed()),
            this,SLOT(enterTriggered()));

    connect(ui->pushButton_2,SIGNAL(clicked()),
            this,SLOT(changeViewTriggered()));

    connect(_allShortcuts.getSwitchViewKey(),SIGNAL(triggered()),
            this,SLOT(changeViewTriggered()));
    \
    connect(_allShortcuts.getUndoKey(),SIGNAL(triggered()),
            this,SLOT(undoTriggered()));

    connect(_allShortcuts.getRedoKey(),SIGNAL(triggered()),
            this,SLOT(redoTriggered()));

    connect(_allShortcuts.getAddKey(),SIGNAL(triggered()),
            this,SLOT(addTriggered()));

    connect(_allShortcuts.getFindKey(),SIGNAL(triggered()),
            this,SLOT(findTriggered()));

    connect(_allShortcuts.getDisplayKey(),SIGNAL(triggered()),
            this,SLOT(displayTriggered()));

    connect(_allShortcuts.getDeleteKey(),SIGNAL(triggered()),
            this,SLOT(deleteTriggered()));

    connect(_allShortcuts.getEditKey(),SIGNAL(triggered()),
            this,SLOT(editTriggered()));
}
