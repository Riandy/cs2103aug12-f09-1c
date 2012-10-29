#include "SeampleView.h"
#include "ui_SeampleView.h"

SeampleView* SeampleView::_seampleView = NULL;

SeampleView::SeampleView(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),CommonView(),
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

SeampleView* SeampleView:: getInstance()
{
    if (!singleInstanceExists())
    {
        _seampleView = new SeampleView();
    }

    return _seampleView;
}

void SeampleView:: endInstance()
{
    if (singleInstanceExists())
    {
        delete _seampleView;
        _seampleView = NULL;
    }
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

void SeampleView:: showAppropriateColorInputEdit (InputBarFlag color)
{
    switch (color)
    {
        case LOGICAL:
            ui->lineEdit->setStyleSheet(STYLESHEET_INPUT_LINE_BORDER_RADIUS+
                                        STYLESHEET_INPUT_LINE_BORDER_STYLE+
                                        STYLESHEET_INPUT_LINE_BORDER_WIDTH+
                                        STYLESHEET_INPUT_LINE_BORDER_COLOR+
                                        "background-color: rgb(50,205,50);");

            break;

        case UNOPERATIVE:
            ui->lineEdit->setStyleSheet(STYLESHEET_INPUT_LINE_BORDER_RADIUS+
                                        STYLESHEET_INPUT_LINE_BORDER_STYLE+
                                        STYLESHEET_INPUT_LINE_BORDER_WIDTH+
                                        STYLESHEET_INPUT_LINE_BORDER_COLOR+
                                        "background-color: rgb(255,99,71);");

            break;

        default:
            ui->lineEdit->setStyleSheet(STYLESHEET_INPUT_LINE_BORDER_RADIUS+
                                        STYLESHEET_INPUT_LINE_BORDER_STYLE+
                                        STYLESHEET_INPUT_LINE_BORDER_WIDTH+
                                        STYLESHEET_INPUT_LINE_BORDER_COLOR+
                                        STYLESHEET_INPUT_LINE_BACKGROUND_COLOR);
            break;
    }
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
    emit run(COMMAND_UNDO, ui->lineEdit->getFocusInput());
}

void SeampleView::redoTriggered()
{
    emit run(COMMAND_REDO, ui->lineEdit->getFocusInput());
}

void SeampleView::addTriggered()
{
    ui->lineEdit->setText(COMMAND_ADD);
    showFocusInInputEdit(true);
}

void SeampleView::findTriggered()
{
    ui->lineEdit->setText(COMMAND_FIND);
    showFocusInInputEdit(true);
}

void SeampleView::displayTriggered()
{
    emit run(COMMAND_DISPLAY, ui->lineEdit->getFocusInput());
}

void SeampleView::deleteTriggered()
{
    ui->lineEdit->setText(COMMAND_DELETE);
    showFocusInInputEdit(true);
}

void SeampleView::editTriggered()
{
    ui->lineEdit->setText(COMMAND_EDIT);
    showFocusInInputEdit(true);
}

void SeampleView::clearTriggered()
{
    showFocusInInputEdit(true);
    showFeedbackInputEdit("");
    emit relay("");
}

bool SeampleView:: singleInstanceExists()
{
    bool result;

    if (_seampleView == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
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

    connect(_allShortcuts.getClearKey(),SIGNAL(triggered()),
            this,SLOT(clearTriggered()));
}
