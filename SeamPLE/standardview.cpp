#include "StandardView.h"
#include "ui_StandardView.h"

#include <QDebug>

StandardView* StandardView::_standardView = NULL;

const QString StandardView::MESSAGE_NO_CURRENT_RESULTS =
        "No Search Results Available";
const QString StandardView::MESSAGE_VIEW_TYPE_WRONG =
        "View type in StandardView is not given a valid input";

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
    setStartView();
    _currentlyChanging = false;

    _faulty = _faulty->getInstance();
}

StandardView::~StandardView()
{
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

void StandardView:: showAppropriateColorInputEdit (InputBarFlag color) throw (string)
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
    showTableResults();
}

//Remove all dynamically allocated memory given to table widget
void StandardView:: resetTableContents()
{
    resetTableNumber();
    resetTableName();
    resetTableStartDate();
    resetTableEndDate();
    hideTableAllPriority();
    informNoDisplayResults();
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

void StandardView::changeDisplayTriggered()
{
    try
    {
        if (_currentType == RESULTS_TABLE || _currentType == HELP_VIEW)
        {
            showViewWithType(TODAY_EVENTS);
        }
        else
        {
            showViewWithType(RESULTS_TABLE);
        }
    }
    catch (string error)
    {
         _faulty->report(error);
    }
}

void StandardView::helpTriggered()
{
    showViewWithType(HELP_VIEW);
}

void StandardView::resetTableNumber()
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
}

void StandardView::resetTableName()
{
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

void StandardView::resetTableStartDate()
{
    ui->label_77->setText("");
    ui->label_78->setText("");
    ui->label_79->setText("");
    ui->label_80->setText("");
    ui->label_81->setText("");
    ui->label_82->setText("");
    ui->label_83->setText("");
    ui->label_84->setText("");
    ui->label_85->setText("");
    ui->label_86->setText("");
}

void StandardView::resetTableEndDate()
{
    ui->label_87->setText("");
    ui->label_88->setText("");
    ui->label_89->setText("");
    ui->label_90->setText("");
    ui->label_91->setText("");
    ui->label_92->setText("");
    ui->label_93->setText("");
    ui->label_94->setText("");
    ui->label_95->setText("");
    ui->label_96->setText("");
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

void StandardView::setStartView()
{
    _currentType = TODAY_EVENTS;

    hideTable();
    hideHelp();
}

void StandardView::showTable()
{
    ui->frame_14->show();
}

void StandardView::hideTable()
{
    ui->frame_14->hide();
}

void StandardView::showHelp()
{
    ui->frame_13->show();
}

void StandardView::hideHelp()
{
    ui->frame_13->hide();
}

void StandardView::showTodayView()
{
    ui->frame_5->show();
}

void StandardView::hideTodayView()
{
    ui->frame_5->hide();
}

void StandardView::showTodayEvents()
{

}

void StandardView::showViewWithType(viewType type) throw (string)
{
    switch (type)
    {
        case TODAY_EVENTS:
            switch (_currentType)
            {
                case TODAY_EVENTS:
                    break;

                case RESULTS_TABLE:
                    hideTable();
                    break;

                case HELP_VIEW:
                    hideHelp();
                    break;

                default:
                    throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                    break;
            }
            showTodayView();
            break;

        case RESULTS_TABLE:
            switch (_currentType)
            {
                case TODAY_EVENTS:
                    hideTodayView();
                    break;

                case RESULTS_TABLE:
                    break;

                case HELP_VIEW:
                    hideHelp();
                    break;

                default:
                    throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                    break;
            }
            showTable();
            break;

        case HELP_VIEW:
            switch (_currentType)
            {
                    case TODAY_EVENTS:
                        hideTodayView();
                        break;

                    case RESULTS_TABLE:
                        hideTable();
                        break;

                    case HELP_VIEW:
                        break;

                    default:
                        throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
                        break;
            }
            showHelp();
            break;

        default:
            throw(MESSAGE_VIEW_TYPE_WRONG.toStdString());
            break;
    }
    _currentType = type;
}

void StandardView::showTableResults()
{
    //Make sure all contents for last showing is removed and replaced
    //with the current content
    resetTableContents();
    bool isNotTableView = (_currentType != RESULTS_TABLE);

    if (isNotTableView)
    {
        showViewWithType(RESULTS_TABLE);
    }

    if (tableIsEmpty())
    {
        informNoDisplayResults();
    }
    else
    {
        qDebug() << _tableItems.output;
        int i = _tableItems.currentIndex;
        bool stillInResultsRange = (i <= _tableItems.endIndex);
        bool stillInTableRange = (i-_tableItems.currentIndex < 10);

        while (stillInResultsRange && stillInTableRange)
        {
            showTableEventId(i,_tableItems.output[(i*6)]);
            showTableEventName(i, _tableItems.output[(i*6)+1]);
            showTableStartDate(i, _tableItems.output[(i*6)+2]);
            showTableEndDate(i, _tableItems.output[(i*6)+3]);
            showTablePriorityIcon(i, _tableItems.output[(i*6)+4]);

            i++;
            stillInResultsRange = (i <= _tableItems.endIndex);
            stillInTableRange = (i-_tableItems.currentIndex < 10);
        }

        //Reduce i as it will increment for one extra time in instantiating the bool conditions
        i--;

        ui->label_27->setText("    "
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

void StandardView:: showTableStartDate(int index, QString startDate)
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

void StandardView:: showTableEndDate(int index, QString endDate)
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

void StandardView:: showTablePriorityIcon(int index, QString priority)
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

    connect(_allShortcuts.getPageUpKey(),SIGNAL(triggered()),
            this,SLOT(pageUpTriggered()));

    connect(_allShortcuts.getPageDownKey(),SIGNAL(triggered()),
            this,SLOT(pageDownTriggered()));

    connect(_allShortcuts.getChangeDisplayKey(),SIGNAL(triggered()),
            this,SLOT(changeDisplayTriggered()));

    connect(_allShortcuts.getHelpKey(),SIGNAL(triggered()),
            this,SLOT(helpTriggered()));
}

bool StandardView::tableIsEmpty()
{
    return (_tableItems.output.size() == 0);
}
