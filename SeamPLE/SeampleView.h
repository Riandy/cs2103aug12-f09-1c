#ifndef SEAMPLEVIEW_H
#define SEAMPLEVIEW_H

#include <QDesktopWidget>
#include <QString>
#include "GuiShortcuts.h"
#include "SLineEdit.h"

namespace Ui {
class SeampleView;
}

class SeampleView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeampleView(QWidget *parent = 0);
    ~SeampleView();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

    void showFocusInInputEdit (bool focus);

signals:
    void relay(QString input);

    void run(QString input, bool focus);

    void toStandardView(QString input, QString inputChecked, bool focus);

private slots:
    void recieve(QString input);

    void enterTriggered();

    void changeViewTriggered();

private:
    void changeGeometry();

    int getPosX(int maxX);

    int getPosY(int maxY);

    void setSignals();

    Ui::SeampleView *ui;

    GuiShortcuts _allShortcuts;

};

#endif // SEAMPLEVIEW_H
