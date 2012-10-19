#include "StandardView.h"
#include "ui_StandardView.h"

const QString StandardView::MESSAGE_NO_CURRENT_RESULTS =
        "No Search Results Available";

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

    _allShortcuts.setShortcutsTo(this);

    connect(ui->lineEdit,SIGNAL(textEdited(const QString&)),
            this,SLOT(recieve(QString)));

    connect(ui->lineEdit,SIGNAL(returnPressed()),
            this,SLOT(enterTriggered()));

    connect(ui->pushButton_2,SIGNAL(clicked()),
            this,SLOT(changeViewTriggered()));

    connect(_allShortcuts.switchView,SIGNAL(triggered()),
            this,SLOT(changeViewTriggered()));

    connect(_allShortcuts.hideShowView,SIGNAL(triggered()),
            this,SLOT(changeViewTriggered()));

    //Prevent change view push button from snatching focus
    //from input line
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);

    _tail = NULL;

    //Table should always have 2 column. No change is done
    //to column count in the rest of the code
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, 40);
    ui->tableWidget->setColumnWidth(1, 662);

}

StandardView::~StandardView()
{
    resetTableContents();
    delete ui;
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
        ui->label_6->setText("");
    }
    else
    {
        ui->label_6->setText(MESSAGE_NO_CURRENT_RESULTS);
    }
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

void StandardView:: changeAutoResolution()
{
    this->setWindowState(Qt::WindowMaximized);
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
    }
    ui->tableWidget->clearContents();
}

