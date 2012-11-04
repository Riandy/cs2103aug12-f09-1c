#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QVector>
#include <QTableWidgetItem>
#include <QTimer>
#include "CommonView.h"

namespace Ui {
class StandardView;
}

class StandardView : public QMainWindow, public CommonView
{
    Q_OBJECT

private:
    enum viewType
    {
        TODAY_EVENTS,
        RESULTS_TABLE,
        HELP_VIEW
    };

    struct table
    {
        QVector <QString> output;
        int currentIndex;
        int endIndex;
    };

private:
    static StandardView* _standardView;

    const static QString MESSAGE_NO_CURRENT_RESULTS;
    const static QString MESSAGE_VIEW_TYPE_WRONG;
    
private:
    explicit StandardView(QWidget *parent = 0);
    ~StandardView();

public:
    StandardView* getInstance();

    void endInstance();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

    void showFocusInInputEdit (bool focus);

    void showAppropriateColorInputEdit (InputBarFlag color) throw (string);

    void instantiateTable(QVector <QString> output) throw (string);

    void resetTableContents();

    void resetTableExpandedContents();

    void show();

    void hide();

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

    void findFloatTriggered();

    void displayTriggered();

    void deleteTriggered();

    void editTriggered();

    void clearTriggered();

    void fadeInChange();

    void fadeOutChange();

    void pageUpTriggered();

    void pageDownTriggered();

    void changeDisplayTriggered();

    void changeTableViewKey();

    void checkAnimationDone(QAbstractAnimation::State newState,QAbstractAnimation::State oldState);

    void calibrateCloseMechanism();

    void screenTwoTriggered();

    void screenThreeTriggered();

public slots:
    void helpTriggered();

private:
    void resetTableNumber();

    void resetTableName();

    void resetTableStartDate();

    void resetTableEndDate();

    void hideTableAllPriority();

    void resetTableExpandedNotes();

    void resetTableExpandedCounter();

    void setStartView();

    void showResultsTableType();

    void setFrameAnimationProperties(QFrame* frame, int xCoord, int yCoord);

    void showTable();

    void showHelp();

    void showTodayView();

    void showViewWithType(viewType type) throw (string);

    void displayTodayEvents();

    void displayTableResults();

    void displayTableNotExpanded();

    void displayTableExpanded();

    void showTableExpandedNotes (int reformatIndex , QString result);

    void showTableEventId(int index, QString id);

    void showTableEventName(int index, QString name);

    void showTableStartDate(int index, QString startDate);

    void showTableEndDate(int index, QString endDate);

    void showTablePriorityIcon(int index, QString priority);

    void informNoDisplayResults();

    void calibrateTableIndex();

    bool singleInstanceExists();

    void changeGeometry();

    int getPosX(int maxX);

    int getPosY(int maxY);

    void setSignals();

    bool tableIsEmpty();

private:
    bool _resultsTableViewExpanded;

    ErrorLogger* _faulty;

    viewType _currentType;

    table _tableItems;

    double _opacityLvl;

    QTimer _fadeTimer;

    Ui::StandardView *ui;
};

#endif // STANDARDVIEW_H
