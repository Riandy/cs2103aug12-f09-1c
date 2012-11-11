#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QVector>
#include <QTimer>
#include <QLabel>
#include "CommonView.h"

//@LIU WEIYUAN A0086030R

//This class is the StandardView as observed when running the program
//It can be used by GuiControl in conjuction with SeampleView, where only
//one of the user interfaces will be shown one at a time

//In this class, display___ and show___ functions are used. Display functions
//are generally to display content to user, while show functions are to
//show the UI element itself to the user (for example, changing to help view)

namespace Ui {
class StandardView;
}

class StandardView : public QMainWindow, public CommonView
{
    Q_OBJECT

private:
    enum ViewType
    {
        TODAY_EVENTS,
        RESULTS_TABLE,
        HELP_VIEW
    };

    enum ResultsViewCode
    {
        EMPTY = 0,
        TABLE_ENTRY_SIZE = 6,
        EXPANDED_SIZE = 3,
        NORMAL_SIZE = 10
    };

    enum OpacityCode
    {
        OPACITY_EMPTY = 0,
        OPACITY_FULL = 1,
        TIMING = 1
    };

    enum HelpCode
    {
        LAST_PAGE = 4,
        FIRST_PAGE = 1
    };

    enum AnimationCoordinates
    {
        RESULTS_DEFAULT_X_COORD = 1480,
        RESULTS_NORMAL_Y_COORD = -437,
        RESULTS_EXPANDED_Y_COORD = 0,

        HELP_DEFAULT_X_COORD = 0,
        HELP_PAGE_ONE_Y_COORD = 0,
        HELP_PAGE_TWO_Y_COORD = -437,
        HELP_PAGE_THREE_Y_COORD = -874,

        RESULTS_VIEW_X_COORD = -1464,
        TODAY_VIEW_X_COORD = -723,
        HELP_VIEW_X_COORD = 16,
        DEFAULT_VIEW_Y_COORD = 14
    };

    struct table
    {
        QVector <QString> output;
        int currentIndex;
        int endIndex;
    };

private:
    static StandardView* _standardView;

    const static double OPACITY_INTERVAL;

    const static QString MESSAGE_NO_CURRENT_RESULTS;
    const static QString MESSAGE_VIEW_TYPE_WRONG;
    const static QString MESSAGE_EVENT_NAME_LABEL;
    const static QString MESSAGE_EVENT_ID_LABEL;
    const static QString MESSAGE_CATEGORY_LABEL;
    const static QString MESSAGE_START_DATE_LABEL;
    const static QString MESSAGE_END_DATE_LABEL;
    const static QString MESSAGE_PRIORITY_LABEL;
    const static QString MESSAGE_FONT_COLOUR_RED;
    const static QString MESSAGE_FONT_COLOUR_GREEN;
    const static QString MESSAGE_FONT_END;
    const static QString MESSAGE_ZERO;
    const static QString MESSAGE_HIGH;
    const static QString MESSAGE_BLANK;
    const static QString MESSAGE_TO;
    const static QString MESSAGE_OF;
    const static QString MESSAGE_RESULTS;
    
private:
    explicit StandardView(QWidget *parent = 0);
    ~StandardView();

public:
    StandardView* getInstance();
    void endInstance();
    void displayFeedbackLabel(QString output);
    void displayFeedbackInputEdit(QString output);
    void displayFocusInInputEdit (bool focus);
    void displayAppropriateColorInputEdit (
            InputBarFlag color) throw (string);
    void instantiateTable(QVector <QString> output) throw (string);
    void resetAllTablesContents();
    void displayTodayView(QVector<QString> info);
    void show();
    void hide();

signals:
    void relay(QString input);
    void run (QString input, bool focus);
    void toSeampleView(QString input, QString inputChecked, bool focus);
    void todayViewTriggered();

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
    void changeViewModeTriggered();
    void checkAnimationDone(QAbstractAnimation::State newState,
                            QAbstractAnimation::State oldState);
    void calibrateCloseMechanism();
    void screenTwoTriggered();
    void screenThreeTriggered();
    void markTriggered();
    void todayTriggered();

public slots:
    void helpTriggered();

private:
    void resetTableContents();
    void resetTableExpandedContents();
    void resetTableNumber();
    void resetTableName();
    void resetTableStartDate();
    void resetTableEndDate();
    void hideTableAllPriority();
    void resetTableExpandedNotes();
    void resetTableExpandedCounter();
    void setStartViewAsTodayView();
    void showResultsTableMode();
    void showHelpViewMode();
    void setFrameAnimationProperties(QFrame* frame, int xCoord, int yCoord);
    void showTable();
    void showHelp();
    void showTodayView();
    void showViewWithType(ViewType type) throw (string);
    void displayTableResults();
    void displayTableNotExpanded();
    void displayTableExpanded();
    void displayTableExpandedNotes (int reformatIndex , QString result);
    void displayTableRangeResultLabel(QLabel* label,int to, int from,
                                       int total);
    void displayTableEventId(int index, QString id);
    void displayTableEventName(int index, QString name);
    void displayTableStartDate(int index, QString startDate);
    void displayTableEndDate(int index, QString endDate);
    void displayTablePriorityIcon(int index, QString priority);
    void informNoDisplayResults();
    void calibrateTableIndex();
    bool singleInstanceExists();
    void setDefaultGeometry();
    int getPosX(int maxX);
    int getPosY(int maxY);
    void setSignals();
    bool tableIsEmpty();
    void displayTodayViewPriority (QVector <QString> priority);
    void displayTodayViewNotes (QVector<QString> notes);
    void displayTodayViewNotesIndividual(QString event, int flag);

private:
    bool _resultsTableViewExpanded;
    int _helpPageNo;
    ErrorLogger* _faulty;
    ViewType _currentType;
    table _tableItems;
    double _opacityLvl;
    QTimer _fadeTimer;
    Ui::StandardView *ui;
};

#endif // STANDARDVIEW_H
