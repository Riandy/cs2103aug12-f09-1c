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

    void showTodayEvents();

    void show();

    void hide();

    bool interfaceCurrentlyChanging();

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

    void clearTriggered();

    void fadeInChange();

    void fadeOutChange();

private:
    void setTableEventId(int index, QString id);

    void setTableEventName(int index, QString name);

    bool singleInstanceExists();

    void changeGeometry();

    int getPosX(int maxX);

    int getPosY(int maxY);

    void setSignals();

private:
    double opacityLvl;

    QTimer fadeInTimer;

    QTimer fadeOutTimer;

    Ui::StandardView *ui;

//    int _tableCellStart;

//    int _tableCellEnd;
};

#endif // STANDARDVIEW_H
