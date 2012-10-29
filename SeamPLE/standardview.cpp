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

    _tail = NULL;

    setTableParam();
    opacityLvl = 0;
}

StandardView::~StandardView()
{
    resetTableContents();
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

void StandardView::showTableResults(QVector <QString> output)
{
    //Make sure all contents for last showing is removed and replaced
    //with the current content
    resetTableContents();

//    ui->tabWidget->setCurrentIndex(1);
//    int rowAmount = output.size();
//    ui->tableWidget->setRowCount(rowAmount);

//    for (int i = 0; i < rowAmount ; i++)
//    {
//        TableListNode *cell = new TableListNode;
//        cell->index.setText(QString("[%1]").arg(i+1));
//        cell->index.setTextAlignment(Qt::AlignCenter);
//        cell->content.setText(output[i]);
//        ui->tableWidget->setItem(i,0,&(cell->index));
//        ui->tableWidget->setItem(i,1,&(cell->content));
//        addTableContent(cell);
//    }

    ui->tabWidget->setCurrentIndex(1);
    int rowAmount = output.size()/6;
    ui->tableWidget->setRowCount(rowAmount);

    for (int i = 0; i < rowAmount ; i++)
    {
        TableListNode *cell = new TableListNode;
        cell->index.setText(QString("[%1]").arg(i+1));
        cell->index.setTextAlignment(Qt::AlignCenter);
        cell->content.setText(output[1+(i*6)]);
        ui->tableWidget->setItem(i,0,&(cell->index));
        ui->tableWidget->setItem(i,1,&(cell->content));
        addTableContent(cell);
    }

    if (rowAmount > 0)
    {
        ui->label_8->setText("");
    }
}

//Remove all dynamically allocated memory given to table widget
void StandardView:: resetTableContents()
{
    while (_tail != NULL)
    {
        if (_tail->next == _tail)
        {
            delete _tail;
            _tail = NULL;
        }
        else
        {
            TableListNode *curr = _tail->next;
            _tail->next = curr->next;
            _tail->next->prev = _tail;
            delete curr;
        }
        ui->tableWidget->removeRow(0);
    }
}

void StandardView:: showNoTableDisplay()
{
    ui->label_8->setText(MESSAGE_NO_CURRENT_RESULTS);
}

//void StandardView:: showTodayEvents(QString events)
//{

//}

void StandardView::show()
{
    //Reset interface to original position
    changeGeometry();

    opacityLvl = 0;
    setWindowOpacity(NONE);
    QMainWindow::show();
    connect(&fadeInTimer,SIGNAL(timeout()), this, SLOT(fadeInChange()));
    fadeInTimer.start(1);
}

void StandardView::hide()
{
    opacityLvl = 1;
    setWindowOpacity(LOGICAL);
    connect(&fadeOutTimer,SIGNAL(timeout()), this, SLOT(fadeOutChange()));
    fadeOutTimer.start(1);
}

bool StandardView::interfaceCurrentlyChanging()
{
    bool result;

    if (opacityLvl < LOGICAL && opacityLvl > NONE)
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

void StandardView::changeWorkingTabTriggered()
{
    bool atFirstTab = ui->tabWidget->currentIndex() == 0;

    if (atFirstTab)
    {
        ui->tabWidget->setCurrentIndex(1);
    }
    else
    {
        ui->tabWidget->setCurrentIndex(0);
    }
}

void StandardView::clearTriggered()
{
    showFocusInInputEdit(true);
    showFeedbackInputEdit("");
    emit relay("");
}

void StandardView::fadeInChange()
{
    opacityLvl += 0.08;

    if (opacityLvl >= LOGICAL)
    {
        opacityLvl = 1;
        fadeInTimer.stop();
        disconnect(&fadeInTimer,SIGNAL(timeout()), this, SLOT(fadeInChange()));
    }

    setWindowOpacity(opacityLvl);
}

void StandardView::fadeOutChange()
{
    opacityLvl -= 0.08;

    if (opacityLvl <= NONE)
    {
        opacityLvl = 0;
        fadeOutTimer.stop();
        QMainWindow::hide();
        disconnect(&fadeOutTimer,SIGNAL(timeout()), this, SLOT(fadeOutChange()));
    }

    setWindowOpacity(opacityLvl);
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

//Add a table cell to the linklist for all table cells
void StandardView::addTableContent(TableListNode *curr)
{
    //For the first element in linklist, we must ensure that it
    //links back to itself
    if (_tail == NULL)
    {
        _tail = curr;
        _tail->next = _tail;
        _tail->prev = _tail;
    }
    //Subsequent elements are placed as the last cell of the link list
    else
    {
        curr->next = _tail->next;
        curr->prev = _tail;
        _tail->next = curr;
        curr->next->prev = curr;
        _tail = curr;
    }
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

void StandardView::setTableParam()
{
    //Table should always have 2 column. No change is done
    //to column count in the rest of the code
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, 40);
    ui->tableWidget->setColumnWidth(1, 662);

    showNoTableDisplay();
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

    connect(_allShortcuts.getChangeWorkingTabKey(),SIGNAL(triggered()),
            this,SLOT(changeWorkingTabTriggered()));

    connect(_allShortcuts.getClearKey(),SIGNAL(triggered()),
            this,SLOT(clearTriggered()));
}
