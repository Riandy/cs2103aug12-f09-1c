#include "SeampleView.h"
#include "ui_SeampleView.h"

#include <QDebug>

SeampleView* SeampleView::_seampleView = NULL;

SeampleView::SeampleView(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),CommonView(),
    ui(new Ui::SeampleView)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    setDefaultGeometry();

    //To make pri window transparent as focus is on
    //sec window
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    _animation = new QPropertyAnimation(ui->frame, "geometry");
    _allShortcuts.setShortcutsTo(this);
    setSignals();

    //Prevent change view push button from snatching focus
    //from input line
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);

    _currentlyChanging = false;
}

SeampleView::~SeampleView()
{
    delete _animation;
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

void SeampleView::show()
{
  connect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
          this,SLOT(checkShowViewFinished(QAbstractAnimation::State,QAbstractAnimation::State)));

    _currentlyChanging = true;
    _animation->setEasingCurve(QEasingCurve::OutQuart);
    _animation->setDuration(200);
    _animation->setStartValue(getHiddenGeometry());
    _animation->setEndValue(getDefaultGeometry());

    QMainWindow::show();
    _animation->start();
}

void SeampleView::hide()
{
    connect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
            this,SLOT(checkHideViewFinished(QAbstractAnimation::State,QAbstractAnimation::State)));

    _currentlyChanging = true;
    _animation->setEasingCurve(QEasingCurve::Linear);
    _animation->setDuration(200);
    _animation->setStartValue(getDefaultGeometry());
    _animation->setEndValue(getHiddenGeometry());

    _animation->start();
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

void SeampleView:: showAppropriateColorInputEdit (InputBarFlag color) throw (string)
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

        case NONE:
            ui->lineEdit->setStyleSheet(STYLESHEET_INPUT_LINE_BORDER_RADIUS+
                                        STYLESHEET_INPUT_LINE_BORDER_STYLE+
                                        STYLESHEET_INPUT_LINE_BORDER_WIDTH+
                                        STYLESHEET_INPUT_LINE_BORDER_COLOR+
                                        STYLESHEET_INPUT_LINE_BACKGROUND_COLOR);
            break;

        default:
            throw (MESSAGE_ERROR_INVALID_COLOUR);
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
    emit relay(ui->lineEdit->text());
}

void SeampleView::findTriggered()
{
    ui->lineEdit->setText(COMMAND_FIND);
    showFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void SeampleView::findFloatTriggered()
{
    emit run(COMMAND_FIND_FLOAT, ui->lineEdit->getFocusInput());
}

void SeampleView::displayTriggered()
{
    emit run(COMMAND_DISPLAY, ui->lineEdit->getFocusInput());
}

void SeampleView::deleteTriggered()
{
    ui->lineEdit->setText(COMMAND_DELETE);
    showFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void SeampleView::editTriggered()
{
    ui->lineEdit->setText(COMMAND_EDIT);
    showFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void SeampleView::clearTriggered()
{
    showFocusInInputEdit(true);
    showFeedbackInputEdit("");
    emit relay("");
}

void SeampleView::helpTriggered()
{
    changeViewTriggered();
    emit getHelpView();
}

void SeampleView::checkHideViewFinished(
        QAbstractAnimation::State newState,QAbstractAnimation::State oldState)
{
    if (oldState == QAbstractAnimation::Running && newState == QAbstractAnimation::Stopped)
    {
        disconnect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
                this,SLOT(checkHideViewFinished(QAbstractAnimation::State,QAbstractAnimation::State)));

        QMainWindow::hide();
        _currentlyChanging = false;
    }
}

void SeampleView::checkShowViewFinished(
        QAbstractAnimation::State newState,QAbstractAnimation::State oldState)
{
    if (oldState == QAbstractAnimation::Running && newState == QAbstractAnimation::Stopped)
    {
        disconnect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
                this,SLOT(checkShowViewFinished(QAbstractAnimation::State,QAbstractAnimation::State)));
        _currentlyChanging = false;
    }
}

void SeampleView::markTriggered()
{
    ui->lineEdit->setText(COMMAND_MARK);
    showFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void SeampleView::todayTriggered()
{
    emit run(COMMAND_TODAY, ui->lineEdit->getFocusInput());
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

void SeampleView:: setDefaultGeometry()
{
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    ui->frame->setGeometry(getPosX(sample.bottomRight().x()),
                           getPosY(sample.bottomRight().y()),
                           this->ui->frame->width(),
                           this->ui->frame->height());
}

QRect SeampleView:: getDefaultGeometry()
{  
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    return QRect(getPosX(sample.bottomRight().x()),
                 getPosY(sample.bottomRight().y()),
                 this->ui->frame->width(),
                 this->ui->frame->height());
}

QRect SeampleView:: getHiddenGeometry()
{
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    return QRect(getPosX(sample.bottomRight().x()),
                 screen.height(),
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

    connect(_allShortcuts.getUndoKey(),SIGNAL(triggered()),
            this,SLOT(undoTriggered()));

    connect(_allShortcuts.getRedoKey(),SIGNAL(triggered()),
            this,SLOT(redoTriggered()));

    connect(_allShortcuts.getAddKey(),SIGNAL(triggered()),
            this,SLOT(addTriggered()));

    connect(_allShortcuts.getFindKey(),SIGNAL(triggered()),
            this,SLOT(findTriggered()));

    connect(_allShortcuts.getFindFloatKey(),SIGNAL(triggered()),
            this,SLOT(findFloatTriggered()));

    connect(_allShortcuts.getDisplayKey(),SIGNAL(triggered()),
            this,SLOT(displayTriggered()));

    connect(_allShortcuts.getDeleteKey(),SIGNAL(triggered()),
            this,SLOT(deleteTriggered()));

    connect(_allShortcuts.getEditKey(),SIGNAL(triggered()),
            this,SLOT(editTriggered()));

    connect(_allShortcuts.getClearKey(),SIGNAL(triggered()),
            this,SLOT(clearTriggered()));

    connect(_allShortcuts.getHelpKey(),SIGNAL(triggered()),
            this,SLOT(helpTriggered()));

    connect(_allShortcuts.getMarkKey(),SIGNAL(triggered()),
            this,SLOT(markTriggered()));

    connect(_allShortcuts.getTodayKey(),SIGNAL(triggered()),
            this,SLOT(todayTriggered()));
}
