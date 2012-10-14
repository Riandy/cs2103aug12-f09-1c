#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QMainWindow>
#include <QString>

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

signals:
    void relay(QString input);

    void run (QString input);

    void toSeampleView(QString input, QString inputChecked);

private slots:
    void recieve(QString input);

    void enterTriggered();

    void changeViewTriggered();

private:
    void changeAutoResolution();
    Ui::StandardView *ui;





};

#endif // STANDARDVIEW_H
