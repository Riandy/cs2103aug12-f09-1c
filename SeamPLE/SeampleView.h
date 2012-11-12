#ifndef SEAMPLEVIEW_H
#define SEAMPLEVIEW_H

#include "CommonView.h"

//@author: A0086030R
//This class is the SeampleView as observed when running the program
//It can be used by GuiControl in conjuction with StandardView, where only
//one of the user interfaces will be shown one at a time
namespace Ui {
class SeampleView;
}

class SeampleView : public QMainWindow, public CommonView
{
    Q_OBJECT

public:
    static SeampleView* _seampleView;
    static int ANIMATION_TIMING;

private:
    explicit SeampleView(QWidget *parent = 0);
    ~SeampleView();    

public:
    SeampleView* getInstance();
    void endInstance();
    void show();
    void hide();
    void displayFeedbackLabel(QString output);
    void displayFeedbackInputEdit(QString output);
    void displayFocusInInputEdit (bool focus);
    void displayAppropriateColorInputEdit (
            InputBarFlag color) throw (string);

signals:
    void relay(QString input);
    void run(QString input, bool focus);
    void toStandardView(QString input, QString inputChecked, bool focus);
    void getHelpView();

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
    void helpTriggered();
    void checkHideViewFinished(QAbstractAnimation::State,
                               QAbstractAnimation::State);
    void checkShowViewFinished(QAbstractAnimation::State,
                               QAbstractAnimation::State);
    void markTriggered();
    void todayTriggered();

private:
    bool singleInstanceExists();
    void setDefaultGeometry();
    QRect getDefaultGeometry();
    QRect getHiddenGeometry();
    int getPosX(int maxX);
    int getPosY(int maxY);
    void setSignals();

private:
    Ui::SeampleView *ui;
    QPropertyAnimation *_animation;

};

#endif // SEAMPLEVIEW_H
