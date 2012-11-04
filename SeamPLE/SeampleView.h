#ifndef SEAMPLEVIEW_H
#define SEAMPLEVIEW_H

#include "CommonView.h"

namespace Ui {
class SeampleView;
}

class SeampleView : public QMainWindow, public CommonView
{
    Q_OBJECT

public:
    static SeampleView* _seampleView;

private:
    explicit SeampleView(QWidget *parent = 0);
    ~SeampleView();    

public:
    SeampleView* getInstance();

    void endInstance();

    void show();

    void hide();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

    void showFocusInInputEdit (bool focus);

    void showAppropriateColorInputEdit (InputBarFlag color) throw (string);

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

    void checkHideViewFinished(QAbstractAnimation::State,QAbstractAnimation::State);

    void checkShowViewFinished(QAbstractAnimation::State,QAbstractAnimation::State);

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
