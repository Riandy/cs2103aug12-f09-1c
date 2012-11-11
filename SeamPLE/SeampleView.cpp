#include "SeampleView.h"
#include "ui_SeampleView.h"

//@WEIYUAN A0086030R

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

//SeampleView is a singleton class as well. A pointer has to be created
//to get the address of seampleview through the use of this function
SeampleView* SeampleView:: getInstance()
{
    if (!singleInstanceExists())
    {
        _seampleView = new SeampleView();
    }

    return _seampleView;
}

//Use this function to remove the singleton existence of seampleview
void SeampleView:: endInstance()
{
    if (singleInstanceExists())
    {
        delete _seampleView;
        _seampleView = NULL;
    }
}

//This function is overwritten to show the animation when seampleview is
//shown. Call QMainWindow::show() to invoke the original show function
void SeampleView::show()
{
  connect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,
                                         QAbstractAnimation::State)),
          this,SLOT(checkShowViewFinished(QAbstractAnimation::State,
                                          QAbstractAnimation::State)));

    _currentlyChanging = true;
    _animation->setEasingCurve(QEasingCurve::OutQuart);
    _animation->setDuration(200);
    _animation->setStartValue(getHiddenGeometry());
    _animation->setEndValue(getDefaultGeometry());

    QMainWindow::show();
    _animation->start();
}

//This function is overwritten to show the animation when seampleview is
//going to hide. Call QMainWindow::hide() to invoke the original hide function
void SeampleView::hide()
{
    connect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,
                                           QAbstractAnimation::State)),
            this,SLOT(checkHideViewFinished(QAbstractAnimation::State,
                                            QAbstractAnimation::State)));

    _currentlyChanging = true;
    _animation->setEasingCurve(QEasingCurve::Linear);
    _animation->setDuration(200);
    _animation->setStartValue(getDefaultGeometry());
    _animation->setEndValue(getHiddenGeometry());

    _animation->start();
}

//Function to change GUI interface label to contain output string
void SeampleView::displayFeedbackLabel(QString output)
{
    ui->label->setText(output);
}

//Function to change GUI interface label to contain output string
void SeampleView::displayFeedbackInputEdit(QString output)
{
    ui->lineEdit->setText(output);
}

//Function to change GUI interface label to contain output string
void SeampleView:: displayFocusInInputEdit (bool focus)
{
    ui->lineEdit->setFocusInput(focus);
}

//Function to display the colour of the input edit bar given the bool
//value returned from intellisense through seample control class
void SeampleView:: displayAppropriateColorInputEdit (
        InputBarFlag color) throw (string)
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
                                        STYLESHEET_INPUT_LINE_BACKGRD_COLOR);
            break;

        default:
            throw (MESSAGE_ERROR_INVALID_COLOUR);
            break;
    }
}

//This function is a slot function that will emit a signal when the
//text is the input bar is changed by the user
void SeampleView::recieve(QString input)
{
    emit relay(input);
}

//This function is a slot function that will emit a signal when the user
//presses enter in the input bar
void SeampleView::enterTriggered()
{
    emit run(ui->lineEdit->text(), ui->lineEdit->getFocusInput());
}

//This function is a slot function that will emit a signal for changing of
//user interfaces when the shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::changeViewTriggered()
{
    emit toStandardView(ui->lineEdit->text(), ui->label->text(),
                        ui->lineEdit->getFocusInput());
}

//This function is a slot function that will emit a signal for the undo
//command when the undo shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::undoTriggered()
{
    emit run(COMMAND_UNDO, ui->lineEdit->getFocusInput());
}

//This function is a slot function that will emit a signal for the redo
//command when the redo shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::redoTriggered()
{
    emit run(COMMAND_REDO, ui->lineEdit->getFocusInput());
}

//This function is a slot function that will add the "add" command text
//when the add shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::addTriggered()
{
    ui->lineEdit->setText(COMMAND_ADD);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

//This function is a slot function that will add the "find" command text
//when the find shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::findTriggered()
{
    ui->lineEdit->setText(COMMAND_FIND);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

//This function is a slot function that will emit a signal for the find float
//option when the float shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::findFloatTriggered()
{
    emit run(COMMAND_FIND_FLOAT, ui->lineEdit->getFocusInput());
}

//This function is a slot function that will emit a signal for the display
//command when the display shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::displayTriggered()
{
    emit run(COMMAND_DISPLAY, ui->lineEdit->getFocusInput());
}

//This function is a slot function that will add the "delete" command text
//when the delete shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::deleteTriggered()
{
    ui->lineEdit->setText(COMMAND_DELETE);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

//This function is a slot function that will add the "edit" command text
//when the edit shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::editTriggered()
{
    ui->lineEdit->setText(COMMAND_EDIT);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

//This function is a slot function that will remove all text from the input
//when the clear shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::clearTriggered()
{
    displayFocusInInputEdit(true);
    displayFeedbackInputEdit("");
    emit relay("");
}

//This function is a slot function that triggers a signal to ask for the
//help menu to be displayed in standardview. The signal to the help
//shortcut trigger must be connected to this slot for this slot function
//to be triggered
void SeampleView::helpTriggered()
{
    changeViewTriggered();
    emit getHelpView();
}

//This function is a slot function that is triggered by the timer, allowing
//the application to know if the animation for hiding has finished
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

//This function is a slot function that is triggered by the timer, allowing
//the application to know if the animation for showing has finished
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

//This function is a slot function that will add the "mark" command text
//when the mark shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::markTriggered()
{
    ui->lineEdit->setText(COMMAND_MARK);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

//This function is a slot function that will emit a signal for the today
//command when the today shortcut is triggered. The signal to the shortcut
//must be connected to this slot for this slot function to be triggered
void SeampleView::todayTriggered()
{
    emit run(COMMAND_TODAY, ui->lineEdit->getFocusInput());
}

//This function checks if there is a singleton existence for this class
// at the point when of the function call
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

//Function is for setting the default position for the application
//on the screen
void SeampleView:: setDefaultGeometry()
{
    ui->frame->setGeometry(getDefaultGeometry());
}

//Function is for returning the default coordinates of position for the
//application
QRect SeampleView:: getDefaultGeometry()
{  
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    return QRect(getPosX(sample.bottomRight().x()),
                 getPosY(sample.bottomRight().y()),
                 this->ui->frame->width(),
                 this->ui->frame->height());
}

//Function is for getting the coordinates of when the application
//is hidden from using view
QRect SeampleView:: getHiddenGeometry()
{
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    return QRect(getPosX(sample.bottomRight().x()),
                 screen.height(),
                 this->ui->frame->width(),
                 this->ui->frame->height());
}

//Get the x coordinates of the position of the application in
//integer form
int SeampleView:: getPosX(int maxX)
{
    return maxX - this->ui->frame->width();
}

//Get the y coordinates of the default position of the application in
//integer form
int SeampleView:: getPosY(int maxY)
{
    return maxY - this->ui->frame->height();
}

//In several slot functions for this class, the slots are required to be
//connected to singnal functions so that the trigger can be attached to the
//slots. This is done through this function
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
