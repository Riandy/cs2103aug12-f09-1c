#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QString>
#include "GuiShortcuts.h"
#include "SLineEdit.h"

namespace Ui {
class StandardView;
}

class StandardView : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit StandardView(QWidget *parent = 0);
    ~StandardView();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

    void showFocusInInputEdit (bool focus);

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

    Ui::StandardView *ui;

    GuiShortcuts allShortcuts;
};

#endif // STANDARDVIEW_H
