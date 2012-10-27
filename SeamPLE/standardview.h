#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QVector>
#include <QTableWidgetItem>
#include "CommonView.h"

namespace Ui {
class StandardView;
}

class StandardView : public QMainWindow, public CommonView
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

    static StandardView* _standardView;

    const static QString MESSAGE_NO_CURRENT_RESULTS;
    
private:
    explicit StandardView(QWidget *parent = 0);
    ~StandardView();

public:
    StandardView* getInstance();

    void endInstance();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

    void showFocusInInputEdit (bool focus);

    void showAppropriateColorInputEdit (InputBarFlag color);

    void showTableResults(QVector <QString> output);

    void resetTableContents();

    void showNoTableDisplay();

signals:
    void relay(QString input);

    void run (QString input, bool focus);

    void toSeampleView(QString input, QString inputChecked, bool focus);

private slots:
    void recieve(QString input);

    void enterTriggered();

    void changeViewTriggered();

    void undoTriggered();

    void redoTriggered();

    void addTriggered();

    void findTriggered();

    void displayTriggered();

    void deleteTriggered();

    void editTriggered();

    void changeWorkingTabTriggered();

    void clearTriggered();


private:
    bool singleInstanceExists();

    void addTableContent(TableListNode *curr);

    void changeGeometry();

    int getPosX(int maxX);

    int getPosY(int maxY);

    void setSignals();

    Ui::StandardView *ui;

    TableListNode *_tail;
};

#endif // STANDARDVIEW_H
