#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QVector>
#include <QString>
#include <QTableWidgetItem>
#include "GuiShortcuts.h"
#include "SLineEdit.h"

namespace Ui {
class StandardView;
}

class StandardView : public QMainWindow
{
    Q_OBJECT

private:
    //New struct for holding the table contents
    struct TableListNode{
        QTableWidgetItem index;
        QTableWidgetItem content;
        TableListNode *prev;
        TableListNode *next;
    };
    
public:
    explicit StandardView(QWidget *parent = 0);
    ~StandardView();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

    void showFocusInInputEdit (bool focus);

    void showTableResults(QVector <QString> output);

signals:
    void relay(QString input);

    void run (QString input, bool focus);

    void toSeampleView(QString input, QString inputChecked, bool focus);

private slots:
    void recieve(QString input);

    void enterTriggered();

    void changeViewTriggered();

private:
    void changeAutoResolution();

    void addTableContent(TableListNode *curr);

    void resetTableContents();

    Ui::StandardView *ui;

    GuiShortcuts _allShortcuts;

    TableListNode *_tail;
};

#endif // STANDARDVIEW_H
