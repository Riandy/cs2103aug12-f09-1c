#include "StandardView.h"
#include "ui_StandardView.h"

StandardView* StandardView::_standardView = NULL;

const QString StandardView::MESSAGE_NIL = "";
const QString StandardView::MESSAGE_NO_CURRENT_RESULTS =
        "No Search Results Available";
const QString StandardView::MESSAGE_VIEW_TYPE_WRONG =
        "View type in StandardView is not given a valid input";
const QString StandardView::MESSAGE_EVENT_NAME_LABEL =
        "<b>Event Name:</b><br>";
const QString StandardView::MESSAGE_EVENT_ID_LABEL =
        "<br><br><b>Event ID:</b><br>";
const QString StandardView::MESSAGE_CATEGORY_LABEL =
        "<br><br><b>Category:</b><br>";
const QString StandardView::MESSAGE_START_DATE_LABEL =
        "<br><br><b>Start Date:</b><br>";
const QString StandardView::MESSAGE_END_DATE_LABEL =
        "<br><br><b>End Date:</b><br>";
const QString StandardView::MESSAGE_PRIORITY_LABEL =
        "<br><br><b>Priority:</b><br>";

const QString StandardView::MESSAGE_FONT_COLOUR_RED =
        "<font color = \"#6A0D10\">";
const QString StandardView::MESSAGE_FONT_COLOUR_GREEN =
        "<font color = \"#0F6A0D\">";
const QString StandardView::MESSAGE_FONT_END = "</font>";

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

    resetAllTablesContents();
    _resultsTableViewExpanded = false;
    _helpPageNo = 1;

    setStartView();
    _currentlyChanging = false;
    _currentlySliding = false;
    _animation = NULL;
    _faulty = _faulty->getInstance();
}

StandardView::~StandardView()
{
    if (_animation != NULL)
    {
        delete _animation;
    }
    _faulty->endInstance();
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

void StandardView::displayFeedbackLabel(QString output)
{
    ui->label->setText(output);
}

void StandardView::displayFeedbackInputEdit(QString output)
{
    ui->lineEdit->setText(output);
}

void StandardView:: displayFocusInInputEdit (bool focus)
{
    ui->lineEdit->setFocusInput(focus);
}

void StandardView:: displayAppropriateColorInputEdit (InputBarFlag color) throw (string)
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
            throw(MESSAGE_ERROR_INVALID_COLOUR);
            break;
    }
}

void StandardView:: instantiateTable(QVector <QString> output) throw (string)
{
    //Defensive coding: output must be a factor of 6
    if(output.size() % 6 == 0)
    {
        _tableItems.output = output;
        _tableItems.currentIndex = 0;
        _tableItems.endIndex = ((output.size()-1)/6);
    }
    else
    {
        throw MESSAGE_ERROR_INCOMPLETE_RESULTS;
    }
    displayTableResults();
}

void StandardView::resetAllTablesContents()
{
    resetTableContents();
    resetTableExpandedContents();
    _tableItems.output.clear();
    _tableItems.currentIndex = 0;
    _tableItems.endIndex = 0;
}

void StandardView::displayTodayView(QVector<QString> info)
{
    QString outstandingEvents = info[0];
    QString priorityEvents = info[1];

    ui->label_72->setText(MESSAGE_FONT_COLOUR_GREEN+outstandingEvents
                          +MESSAGE_FONT_END);
    ui->label_71->setText(MESSAGE_FONT_COLOUR_RED+priorityEvents
                          +MESSAGE_FONT_END);

    if (priorityEvents != "0")
    {
        displayTodayViewPriority(info.mid(2,6));
        displayTodayViewNotes(info.mid(8,info.size()-8));
    }
    else
    {
        ui->label_70->setText("");
        displayTodayViewNotes(info.mid(2,info.size()-2));
    }
}

void StandardView::show()
{
    _currentlyChanging = true;

    //Reset interface to original position
    changeGeometry();

    _opacityLvl = 0;
    setWindowOpacity(NONE);
    QMainWindow::show();
    connect(&_fadeTimer,SIGNAL(timeout()), this, SLOT(fadeInChange()));
    _fadeTimer.start(1);
}

void StandardView::hide()
{
    _currentlyChanging = true;
    _opacityLvl = 1;
    setWindowOpacity(LOGICAL);
    connect(&_fadeTimer,SIGNAL(timeout()), this, SLOT(fadeOutChange()));
    _fadeTimer.start(1);
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
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void StandardView::findTriggered()
{
    ui->lineEdit->setText(COMMAND_FIND);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void StandardView::findFloatTriggered()
{
    emit run(COMMAND_FIND_FLOAT, ui->lineEdit->getFocusInput());
}

void StandardView::displayTriggered()
{
    emit run(COMMAND_DISPLAY, ui->lineEdit->getFocusInput());
}

void StandardView::deleteTriggered()
{
    ui->lineEdit->setText(COMMAND_DELETE);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void StandardView::editTriggered()
{
    ui->lineEdit->setText(COMMAND_EDIT);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void StandardView::clearTriggered()
{
    displayFocusInInputEdit(true);
    displayFeedbackInputEdit("");
    emit relay("");
}

void StandardView::fadeInChange()
{
    _opacityLvl += 0.08;

    setWindowOpacity(_opacityLvl);

    if (_opacityLvl >= LOGICAL)
    {
        _opacityLvl = 1;
        _fadeTimer.stop();
        disconnect(&_fadeTimer,SIGNAL(timeout()), this, SLOT(fadeInChange()));
        _currentlyChanging = false;
    }
}

void StandardView::fadeOutChange()
{
    _opacityLvl -= 0.08;

    setWindowOpacity(_opacityLvl);

    if (_opacityLvl <= NONE)
    {
        _opacityLvl = 0;
        _fadeTimer.stop();
        QMainWindow::hide();
        disconnect(&_fadeTimer,SIGNAL(timeout()), this, SLOT(fadeOutChange()));
        _currentlyChanging = false;
    }
}

void StandardView::pageUpTriggered()
{
    int varyAmount = (_resultsTableViewExpanded ? 3 : 10);

    bool currInputAtFrontDisplayExcept1stIndex = (_tableItems.currentIndex < 3 && _tableItems.currentIndex > 0);
    if (currInputAtFrontDisplayExcept1stIndex)
    {
        _tableItems.currentIndex = 3;
    }

    bool currInputNotAtFrontDisplay = (_tableItems.currentIndex >= varyAmount);
    bool currViewTypeIsTable = (_currentType == RESULTS_TABLE);

    if (!tableIsEmpty() && currInputNotAtFrontDisplay && currViewTypeIsTable)
    {

        _tableItems.currentIndex -= varyAmount;
        displayTableResults();
    }
}

void StandardView::pageDownTriggered()
{
    int varyAmount = (_resultsTableViewExpanded ? 3 : 10);

    bool currInputNotAtLastDisplay =
            (_tableItems.endIndex - _tableItems.currentIndex >= varyAmount);
    bool currViewTypeIsTable = (_currentType == RESULTS_TABLE);

    if (!tableIsEmpty()&& currInputNotAtLastDisplay && currViewTypeIsTable)
    {
        _tableItems.currentIndex += varyAmount;
        displayTableResults();
    }
}

void StandardView::changeDisplayTriggered()
{
    try
    {
        switch (_currentType)
        {
            case RESULTS_TABLE:
            case HELP_VIEW:
                showViewWithType(TODAY_EVENTS);
                break;

            case TODAY_EVENTS:
                showViewWithType(RESULTS_TABLE);
                break;

            default:
                break;
        }
    }
    catch (string& error)
    {
         _faulty->report(error);
    }
}

void StandardView::changeViewModeTriggered()
{
    if (!screenCurrentlySliding())
    {
        if (_currentType == RESULTS_TABLE)
        {
            _resultsTableViewExpanded = !_resultsTableViewExpanded;
            showResultsTableType();
            displayTableResults();
        }
        else if (_currentType == HELP_VIEW)
        {
            _helpPageNo++;
            if (_helpPageNo == 4)
            {
                _helpPageNo = 1;
            }
            showHelpViewType();
        }
    }
}

void StandardView::checkAnimationDone(
        QAbstractAnimation::State newState,QAbstractAnimation::State oldState)
{
    if (oldState == QAbstractAnimation::Running && newState == QAbstractAnimation::Stopped)
    {
        disconnect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
                this,SLOT(checkAnimationDone(QAbstractAnimation::State,QAbstractAnimation::State)));
        delete _animation;
        _animation = NULL;
        _currentlySliding = false;
    }
}

void StandardView::calibrateCloseMechanism()
{
    if (!screenCurrentlySliding() && !interfaceCurrentlyChanging())
    {
        this->close();
    }
}

void StandardView::screenTwoTriggered()
{
    showViewWithType(TODAY_EVENTS);
}

void StandardView::screenThreeTriggered()
{
    showViewWithType(RESULTS_TABLE);
}

void StandardView::markTriggered()
{
    ui->lineEdit->setText(COMMAND_MARK);
    displayFocusInInputEdit(true);
    emit relay(ui->lineEdit->text());
}

void StandardView::todayTriggered()
{
    emit run(COMMAND_TODAY, ui->lineEdit->getFocusInput());
}

void StandardView::helpTriggered()
{
    showViewWithType(HELP_VIEW);
}

void StandardView:: resetTableContents()
{
    resetTableNumber();
    resetTableName();
    resetTableStartDate();
    resetTableEndDate();
    hideTableAllPriority();
    informNoDisplayResults();
}

void StandardView:: resetTableExpandedContents()
{
    resetTableExpandedNotes();
    resetTableExpandedCounter();
    informNoDisplayResults();
}

void StandardView::resetTableNumber()
{
    ui->label_7->setText(MESSAGE_NIL);
    ui->label_8->setText(MESSAGE_NIL);
    ui->label_9->setText(MESSAGE_NIL);
    ui->label_10->setText(MESSAGE_NIL);
    ui->label_11->setText(MESSAGE_NIL);
    ui->label_12->setText(MESSAGE_NIL);
    ui->label_13->setText(MESSAGE_NIL);
    ui->label_14->setText(MESSAGE_NIL);
    ui->label_15->setText(MESSAGE_NIL);
    ui->label_16->setText(MESSAGE_NIL);
}

void StandardView::resetTableName()
{
    ui->label_17->setText(MESSAGE_NIL);
    ui->label_18->setText(MESSAGE_NIL);
    ui->label_19->setText(MESSAGE_NIL);
    ui->label_20->setText(MESSAGE_NIL);
    ui->label_21->setText(MESSAGE_NIL);
    ui->label_22->setText(MESSAGE_NIL);
    ui->label_23->setText(MESSAGE_NIL);
    ui->label_24->setText(MESSAGE_NIL);
    ui->label_25->setText(MESSAGE_NIL);
    ui->label_26->setText(MESSAGE_NIL);
}

void StandardView::resetTableStartDate()
{
    ui->label_77->setText(MESSAGE_NIL);
    ui->label_78->setText(MESSAGE_NIL);
    ui->label_79->setText(MESSAGE_NIL);
    ui->label_80->setText(MESSAGE_NIL);
    ui->label_81->setText(MESSAGE_NIL);
    ui->label_82->setText(MESSAGE_NIL);
    ui->label_83->setText(MESSAGE_NIL);
    ui->label_84->setText(MESSAGE_NIL);
    ui->label_85->setText(MESSAGE_NIL);
    ui->label_86->setText(MESSAGE_NIL);
}

void StandardView::resetTableEndDate()
{
    ui->label_87->setText(MESSAGE_NIL);
    ui->label_88->setText(MESSAGE_NIL);
    ui->label_89->setText(MESSAGE_NIL);
    ui->label_90->setText(MESSAGE_NIL);
    ui->label_91->setText(MESSAGE_NIL);
    ui->label_92->setText(MESSAGE_NIL);
    ui->label_93->setText(MESSAGE_NIL);
    ui->label_94->setText(MESSAGE_NIL);
    ui->label_95->setText(MESSAGE_NIL);
    ui->label_96->setText(MESSAGE_NIL);
}

void StandardView::hideTableAllPriority()
{
    ui->label_97->hide();
    ui->label_98->hide();
    ui->label_99->hide();
    ui->label_100->hide();
    ui->label_101->hide();
    ui->label_102->hide();
    ui->label_103->hide();
    ui->label_104->hide();
    ui->label_105->hide();
    ui->label_106->hide();
}

void StandardView::resetTableExpandedNotes()
{
    ui->label_107->setText(MESSAGE_NIL);
    ui->label_108->setText(MESSAGE_NIL);
    ui->label_109->setText(MESSAGE_NIL);
}

void StandardView::resetTableExpandedCounter()
{
    ui->label_74->setText(MESSAGE_NIL);
}

void StandardView::setStartView()
{
    _currentType = TODAY_EVENTS;
}

void StandardView::showResultsTableType()
{
    if (_resultsTableViewExpanded)
    {
        setFrameAnimationProperties(ui->frame_23, 1480,0);
    }
    else
    {
        setFrameAnimationProperties(ui->frame_23, 1480, -437);
    }
}

void StandardView::showHelpViewType()
{
    switch (_helpPageNo)
    {
        case 1:
            setFrameAnimationProperties(ui->frame_17, 0,0);
            break;

        case 2:
            setFrameAnimationProperties(ui->frame_17, 0,-437);
            break;

        case 3:
            setFrameAnimationProperties(ui->frame_17, 0,-874);
            break;

        default:
            break;
    }
}

void StandardView::setFrameAnimationProperties(QFrame* frame, int xCoord, int yCoord)
{
    _currentlySliding = true;

    _animation = new QPropertyAnimation(frame, "geometry");

    connect(_animation,SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
            this,SLOT(checkAnimationDone(QAbstractAnimation::State,QAbstractAnimation::State)));

    _animation->setEasingCurve(QEasingCurve::OutQuart);
    _animation->setDuration(500);
    _animation->setStartValue(frame->geometry());
    _animation->setEndValue(QRect(xCoord,yCoord,frame->width(),frame->height()));
    _animation->start();
}

void StandardView::showTable()
{
    setFrameAnimationProperties(ui->frame_22, -1464,14);
}

void StandardView::showHelp()
{
    setFrameAnimationProperties(ui->frame_22, 16,14);
}

void StandardView::showTodayView()
{
    setFrameAnimationProperties(ui->frame_22, -723,14);
    emit todayViewTriggered();
}

void StandardView::showViewWithType(viewType type) throw (string)
{
    if (!screenCurrentlySliding())
    {
        switch (type)
        {
            case TODAY_EVENTS:
                switch (_currentType)
                {
                    case TODAY_EVENTS:
                        break;

                    case RESULTS_TABLE:
                    case HELP_VIEW:
                        showTodayView();
                        break;

                    default:
                        throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                        break;
                }
                break;

            case RESULTS_TABLE:
                switch (_currentType)
                {
                    case RESULTS_TABLE:
                        break;

                    case TODAY_EVENTS:
                    case HELP_VIEW:
                        showTable();
                        break;

                    default:
                        throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                        break;
                }
                break;

            case HELP_VIEW:
                switch (_currentType)
                {
                    case TODAY_EVENTS:
                    case RESULTS_TABLE:
                        showHelp();
                        break;

                    case HELP_VIEW:
                        break;

                    default:
                        throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                        break;
                }
                break;

            default:
                throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                break;
        }
        _currentType = type;
    }
}

void StandardView::displayTableResults()
{
    bool isNotTableView = (_currentType != RESULTS_TABLE);

    if (isNotTableView)
    {
        showViewWithType(RESULTS_TABLE);
    }

    if (_resultsTableViewExpanded)
    {
        resetTableExpandedContents();

        if (tableIsEmpty())
        {
            informNoDisplayResults();
        }
        else
        {
            displayTableExpanded();
        }
    }
    else
    {
        //Make sure all contents for last showing is removed and replaced
        //with the current content
        resetTableContents();

        //Condition is repeated as it must be after the appropriate reset
        if (tableIsEmpty())
        {
            informNoDisplayResults();
        }
        else
        {
            calibrateTableIndex();
            displayTableNotExpanded();
        }
    }
}

void StandardView::displayTableNotExpanded()
{
    int i = _tableItems.currentIndex;
    bool stillInResultsRange = (i <= _tableItems.endIndex);
    bool stillInTableRange = (i-_tableItems.currentIndex < 10);

    while (stillInResultsRange && stillInTableRange)
    {
        displayTableEventId(i,_tableItems.output[(i*6)]);
        displayTableEventName(i, _tableItems.output[(i*6)+1]);
        displayTableStartDate(i, _tableItems.output[(i*6)+2]);
        displayTableEndDate(i, _tableItems.output[(i*6)+3]);
        displayTablePriorityIcon(i, _tableItems.output[(i*6)+4]);

        i++;
        stillInResultsRange = (i <= _tableItems.endIndex);
        stillInTableRange = (i-_tableItems.currentIndex < 10);
    }

    ui->label_27->setText("    "
                          +QString::number(_tableItems.currentIndex+1)
                          +" to "
                          +QString::number(i)
                          +" of "
                          +QString::number(_tableItems.endIndex+1)
                          +" results ");
}

void StandardView:: displayTableExpanded()
{
    int i = _tableItems.currentIndex;
    bool stillInResultsRange = (i <= _tableItems.endIndex);
    bool stillInNotesRange = (i-_tableItems.currentIndex < 3);

    while (stillInResultsRange && stillInNotesRange)
    {
        QString result =
                MESSAGE_EVENT_NAME_LABEL+
                _tableItems.output[(i*6)+1]+
                MESSAGE_EVENT_ID_LABEL+
                _tableItems.output[(i*6)]+
                MESSAGE_CATEGORY_LABEL+
                _tableItems.output[(i*6)+5]+
                MESSAGE_START_DATE_LABEL+
                _tableItems.output[(i*6)+2]+
                MESSAGE_END_DATE_LABEL+
                _tableItems.output[(i*6)+3]+
                MESSAGE_PRIORITY_LABEL+
                _tableItems.output[(i*6)+4];

        displayTableExpandedNotes(i-_tableItems.currentIndex,result);

        i++;
        stillInResultsRange = (i <= _tableItems.endIndex);
        stillInNotesRange = (i-_tableItems.currentIndex < 3);
    }

    ui->label_74->setText("    "
                          +QString::number(_tableItems.currentIndex+1)
                          +" to "
                          +QString::number(i)
                          +" of "
                          +QString::number(_tableItems.endIndex+1)
                          +" results ");
}

void StandardView::displayTableExpandedNotes(int reformatIndex, QString result)
{
    switch (reformatIndex)
    {
        case 0:
            ui->label_107->setText(result);
            break;

        case 1:
            ui->label_108->setText(result);
            break;

        case 2:
            ui->label_109->setText(result);
            break;

        default:
            break;
    }
}

void StandardView:: displayTableEventId(int index, QString id)
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

void StandardView:: displayTableEventName(int index, QString name)
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

void StandardView:: displayTableStartDate(int index, QString startDate)
{
    int reformatIndex = index%10;

    switch (reformatIndex)
    {
        case 0:
            ui->label_77->setText(startDate);
            break;

        case 1:
            ui->label_78->setText(startDate);
            break;

        case 2:
            ui->label_80->setText(startDate);
            break;

        case 3:
            ui->label_79->setText(startDate);
            break;

        case 4:
            ui->label_84->setText(startDate);
            break;

        case 5:
            ui->label_81->setText(startDate);
            break;

        case 6:
            ui->label_83->setText(startDate);
            break;

        case 7:
            ui->label_82->setText(startDate);
            break;

        case 8:
            ui->label_86->setText(startDate);
            break;

        case 9:
            ui->label_85->setText(startDate);
            break;

        default:
            break;
    }
}

void StandardView:: displayTableEndDate(int index, QString endDate)
{
    int reformatIndex = index%10;

    switch (reformatIndex)
    {
        case 0:
            ui->label_96->setText(endDate);
            break;

        case 1:
            ui->label_88->setText(endDate);
            break;

        case 2:
            ui->label_91->setText(endDate);
            break;

        case 3:
            ui->label_90->setText(endDate);
            break;

        case 4:
            ui->label_87->setText(endDate);
            break;

        case 5:
            ui->label_93->setText(endDate);
            break;

        case 6:
            ui->label_95->setText(endDate);
            break;

        case 7:
            ui->label_94->setText(endDate);
            break;

        case 8:
            ui->label_92->setText(endDate);
            break;

        case 9:
            ui->label_89->setText(endDate);
            break;

        default:
            break;
    }
}

void StandardView:: displayTablePriorityIcon(int index, QString priority)
{
    int reformatIndex = index%10;

    if (priority == "HIGH")
    {
        switch (reformatIndex)
        {
            case 0:
                ui->label_97->show();
                break;

            case 1:
                ui->label_98->show();
                break;

            case 2:
                ui->label_99->show();
                break;

            case 3:
                ui->label_100->show();
                break;

            case 4:
                ui->label_101->show();
                break;

            case 5:
                ui->label_104->show();
                break;

            case 6:
                ui->label_102->show();
                break;

            case 7:
                ui->label_103->show();
                break;

            case 8:
                ui->label_105->show();
                break;

            case 9:
                ui->label_106->show();
                break;

            default:
                break;
        }
    }
}

void StandardView:: informNoDisplayResults()
{    
    if (_resultsTableViewExpanded)
    {
        ui->label_74->setText(MESSAGE_NO_CURRENT_RESULTS);
    }
    else
    {
        ui->label_27->setText(MESSAGE_NO_CURRENT_RESULTS);
    }
}

//Function is used to reduce current table index back to original 0 - 9
//list size after possible changes made from expanded view
void StandardView::calibrateTableIndex()
{
    _tableItems.currentIndex -= (_tableItems.currentIndex%10);
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
    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(calibrateCloseMechanism()));
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
    connect(_allShortcuts.getPageUpKey(),SIGNAL(triggered()),
            this,SLOT(pageUpTriggered()));
    connect(_allShortcuts.getPageDownKey(),SIGNAL(triggered()),
            this,SLOT(pageDownTriggered()));
    connect(_allShortcuts.getChangeDisplayKey(),SIGNAL(triggered()),
            this,SLOT(changeDisplayTriggered()));
    connect(_allShortcuts.getHelpKey(),SIGNAL(triggered()),
            this,SLOT(helpTriggered()));
    connect(_allShortcuts.getChangeTableViewKey(), SIGNAL(triggered()),
            this, SLOT(changeViewModeTriggered()));
    connect(_allShortcuts.getChangeScreenOneViewKey(), SIGNAL(triggered()),
            this, SLOT(helpTriggered()));
    connect(_allShortcuts.getChangeScreenTwoViewKey(), SIGNAL(triggered()),
            this, SLOT(screenTwoTriggered()));
    connect(_allShortcuts.getChangeScreenThreeViewKey(), SIGNAL(triggered()),
            this, SLOT(screenThreeTriggered()));
    connect(_allShortcuts.getMarkKey(),SIGNAL(triggered()),
            this,SLOT(markTriggered()));
    connect(_allShortcuts.getTodayKey(),SIGNAL(triggered()),
            this,SLOT(todayTriggered()));
}

bool StandardView::tableIsEmpty()
{
    return (_tableItems.output.size() == 0);
}

void StandardView::displayTodayViewPriority (QVector <QString> priority)
{
    QString result = MESSAGE_FONT_COLOUR_RED+
            MESSAGE_EVENT_NAME_LABEL+priority[1]+
            MESSAGE_START_DATE_LABEL+priority[2]+
            MESSAGE_END_DATE_LABEL+priority[3]+
            MESSAGE_FONT_END;

    ui->label_70->setText(result);
}

void StandardView::displayTodayViewNotes (QVector<QString> notes)
{
    int count, size = notes.size();
    QString event;

    for(count = 0; count < 3 ; count++)
    {
        if (count < (size/6))
        {
            event = MESSAGE_EVENT_NAME_LABEL+notes[(count*6)+1]+
                    MESSAGE_START_DATE_LABEL+notes[(count*6)+2]+
                    MESSAGE_END_DATE_LABEL+notes[(count*6)+3];
        }
        else
        {
            event = "";
        }
        displayTodayViewNotesIndividual(event,count);
    }
}

void StandardView::displayTodayViewNotesIndividual(QString event, int flag)
{
    switch (flag)
    {
        case 0:
            ui->label_67->setText(event);
            break;
        case 1:
            ui->label_68->setText(event);
            break;
        case 2:
            ui->label_69->setText(event);
            break;

        default:
            break;
    }
}
