#include "StandardView.h"
#include "ui_StandardView.h"

StandardView* StandardView::_standardView = NULL;

const QString StandardView::MESSAGE_NO_CURRENT_RESULTS =
        "No Search Results Available";

StandardView::StandardView(QWidget *parent):
    QMainWindow(parent, Qt::FramelessWindowHint),CommonView(),
    ui(new Ui::StandardView)
{
    //Default settings according to UI form
    ui->setupUi(this);
    changeGeometry();

    //To make pri window transparent as focus is on
    //sec window
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    _allShortcuts.setStandardShortcutsTo(this);
    setSignals();

    //Prevent change view push button from snatching focus
    //from input line
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);

    resetTableContents();
    _tableItems.currentIndex = 0;
    _tableItems.endIndex = 0;
}

StandardView::~StandardView()
{
    delete ui;
}

StandardView* StandardView:: getInstance()
{
    if (!singleInstanceExists())
    {
        _standardView = new StandardView();
    }

    return _standardView;
}

void StandardView:: endInstance()
{
    if (singleInstanceExists())
    {
        delete _standardView;
        _standardView = NULL;
    }
}

void StandardView::showFeedbackLabel(QString output)
{
    ui->label->setText(output);
}

void StandardView::showFeedbackInputEdit(QString output)
{
    ui->lineEdit->setText(output);
}

void StandardView:: showFocusInInputEdit (bool focus)
{
    ui->lineEdit->setFocusInput(focus);
}

void StandardView:: showAppropriateColorInputEdit (InputBarFlag color)
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

void StandardView:: instantiateTable(QVector <QString> output)
{
    _tableItems.output = output;
    _tableItems.currentIndex = 0;
    _tableItems.endIndex = output.size()/6;

    showTableResults();
}

//Remove all dynamically allocated memory given to table widget
void StandardView:: resetTableContents()
{
    ui->label_7->setText("");
    ui->label_8->setText("");
    ui->label_9->setText("");
    ui->label_10->setText("");
    ui->label_11->setText("");
    ui->label_12->setText("");
    ui->label_13->setText("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->label_16->setText("");
    ui->label_17->setText("");
    ui->label_18->setText("");
    ui->label_19->setText("");
    ui->label_20->setText("");
    ui->label_21->setText("");
    ui->label_22->setText("");
    ui->label_23->setText("");
    ui->label_24->setText("");
    ui->label_25->setText("");
    ui->label_26->setText("");
}

//void StandardView:: showTodayEvents(QString events)
//{

//}

void StandardView::show()
{
    //Reset interface to original position
    changeGeometry();

    _opacityLvl = 0;
    setWindowOpacity(NONE);
    QMainWindow::show();
    connect(&_fadeInTimer,SIGNAL(timeout()), this, SLOT(fadeInChange()));
    _fadeInTimer.start(1);
}

void StandardView::hide()
{
    _opacityLvl = 1;
    setWindowOpacity(LOGICAL);
    connect(&_fadeOutTimer,SIGNAL(timeout()), this, SLOT(fadeOutChange()));
    _fadeOutTimer.start(1);
}

bool StandardView::interfaceCurrentlyChanging()
{
    bool result;

    if (_opacityLvl > 0.001 && _opacityLvl < LOGICAL)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

void StandardView::recieve(QString input)
{
    emit relay(input);
}

void StandardView::enterTriggered()
{
    emit run(ui->lineEdit->text(), ui->lineEdit->getFocusInput());
}

void StandardView::changeViewTriggered()
{
    emit toSeampleView(ui->lineEdit->text(),ui->label->text(), ui->lineEdit->getFocusInput());
}

void StandardView::undoTriggered()
{
    emit run(COMMAND_UNDO, ui->lineEdit->getFocusInput());
}

void StandardView::redoTriggered()
{
    emit run(COMMAND_REDO, ui->lineEdit->getFocusInput());
}

void StandardView::addTriggered()
{
    ui->lineEdit->setText(COMMAND_ADD);
    showFocusInInputEdit(true);
}

void StandardView::findTriggered()
{
    ui->lineEdit->setText(COMMAND_FIND);
    showFocusInInputEdit(true);
}

void StandardView::displayTriggered()
{
    emit run(COMMAND_DISPLAY, ui->lineEdit->getFocusInput());
}

void StandardView::deleteTriggered()
{
    ui->lineEdit->setText(COMMAND_DELETE);
    showFocusInInputEdit(true);
}

void StandardView::editTriggered()
{
    ui->lineEdit->setText(COMMAND_EDIT);
    showFocusInInputEdit(true);
}

void StandardView::clearTriggered()
{
    showFocusInInputEdit(true);
    showFeedbackInputEdit("");
    emit relay("");
}

void StandardView::fadeInChange()
{
    _opacityLvl += 0.08;

    if (_opacityLvl >= LOGICAL)
    {
        _opacityLvl = 1;
        _fadeInTimer.stop();
        disconnect(&_fadeInTimer,SIGNAL(timeout()), this, SLOT(fadeInChange()));
    }

    setWindowOpacity(_opacityLvl);
}

void StandardView::fadeOutChange()
{
    _opacityLvl -= 0.08;

    if (_opacityLvl <= NONE)
    {
        _opacityLvl = 0;
        _fadeOutTimer.stop();
        QMainWindow::hide();
        disconnect(&_fadeOutTimer,SIGNAL(timeout()), this, SLOT(fadeOutChange()));
    }

    setWindowOpacity(_opacityLvl);
}

void StandardView::pageUpTriggered()
{
    bool currInputNotAtFrontDisplay = (_tableItems.currentIndex >= 10);

    if (!tableIsEmpty() && currInputNotAtFrontDisplay)
    {
        _tableItems.currentIndex -= 10;
        showTableResults();
    }
}

void StandardView::pageDownTriggered()
{
    bool currInputNotAtLastDisplay =
            (_tableItems.endIndex - _tableItems.endIndex%10 !=
             _tableItems.currentIndex -_tableItems.currentIndex%10);
    if (!tableIsEmpty()&& currInputNotAtLastDisplay)
    {
        _tableItems.currentIndex += 10;
        showTableResults();
    }
}

void StandardView::showTableResults()
{
    //Make sure all contents for last showing is removed and replaced
    //with the current content
    resetTableContents();

    if (tableIsEmpty())
    {
        informNoDisplayResults();
    }
    else
    {
        int i = _tableItems.currentIndex;
        bool stillInResultsRange = (i < _tableItems.endIndex);
        bool stillInTableRange = (i-_tableItems.currentIndex < 10);

        while (stillInResultsRange && stillInTableRange)
        {
            showTableEventId(i%10,_tableItems.output[(i*6)]);
            showTableEventName(i%10, _tableItems.output[(i*6)+1]);

            i++;
            stillInResultsRange = (i < _tableItems.endIndex);
            stillInTableRange = (i-_tableItems.currentIndex < 10);
        }

        //Reduce i as it will increment for one extra time in instantiating the bool conditions
        i--;

        ui->label_27->setText(" Showing "
                              +QString::number(_tableItems.currentIndex+1)
                              +" to "
                              +QString::number(i+1)
                              +" of "
                              +QString::number(_tableItems.endIndex+1)
                              +" results ");
    }
}

void StandardView:: showTableEventId(int index, QString id)
{
    int reformatIndex = index%10;

    switch (reformatIndex)
    {
        case 0:
            ui->label_17->setText(id);
            break;

        case 1:
            ui->label_18->setText(id);
            break;

        case 2:
            ui->label_19->setText(id);
            break;

        case 3:
            ui->label_20->setText(id);
            break;

        case 4:
            ui->label_21->setText(id);
            break;

        case 5:
            ui->label_22->setText(id);
            break;

        case 6:
            ui->label_23->setText(id);
            break;

        case 7:
            ui->label_24->setText(id);
            break;

        case 8:
            ui->label_25->setText(id);
            break;

        case 9:
            ui->label_26->setText(id);
            break;

        default:
            break;
    }
}

void StandardView:: showTableEventName(int index, QString name)
{
    int reformatIndex = index%10;

    switch (reformatIndex)
    {
        case 0:
            ui->label_7->setText(name);
            break;

        case 1:
            ui->label_8->setText(name);
            break;

        case 2:
            ui->label_9->setText(name);
            break;

        case 3:
            ui->label_10->setText(name);
            break;

        case 4:
            ui->label_11->setText(name);
            break;

        case 5:
            ui->label_12->setText(name);
            break;

        case 6:
            ui->label_13->setText(name);
            break;

        case 7:
            ui->label_14->setText(name);
            break;

        case 8:
            ui->label_15->setText(name);
            break;

        case 9:
            ui->label_16->setText(name);
            break;

        default:
            break;
    }
}

void StandardView:: informNoDisplayResults()
{
    ui->label_27->setText(MESSAGE_NO_CURRENT_RESULTS);
}

bool StandardView:: singleInstanceExists()
{
    bool result;

    if (_standardView == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

void StandardView:: changeGeometry()
{
    this->setWindowState(Qt::WindowMaximized);
    QDesktopWidget screen;
    QRect sample = screen.availableGeometry(-1);

    this->ui->frame->setGeometry(getPosX(sample.bottomRight().x()),
                                 getPosY(sample.bottomRight().y()),
                                 this->ui->frame->width(),
                                 this->ui->frame->height());
}

int StandardView:: getPosX(int maxX)
{
    return maxX - this->ui->frame->width();
}

int StandardView:: getPosY(int maxY)
{
    return maxY - this->ui->frame->height();
}

void StandardView:: setSignals()
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

    connect(_allShortcuts.getDisplayKey(),SIGNAL(triggered()),
            this,SLOT(displayTriggered()));

    connect(_allShortcuts.getDeleteKey(),SIGNAL(triggered()),
            this,SLOT(deleteTriggered()));

    connect(_allShortcuts.getEditKey(),SIGNAL(triggered()),
            this,SLOT(editTriggered()));

    connect(_allShortcuts.getClearKey(),SIGNAL(triggered()),
            this,SLOT(clearTriggered()));

    connect(_allShortcuts.getLeftKey(),SIGNAL(triggered()),
            this,SLOT(pageUpTriggered()));

    connect(_allShortcuts.getRightKey(),SIGNAL(triggered()),
            this,SLOT(pageDownTriggered()));
}

bool StandardView::tableIsEmpty()
{
    return (_tableItems.output.size() == 0);
}
