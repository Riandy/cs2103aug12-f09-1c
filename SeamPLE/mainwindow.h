#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showFeedbackLabel(QString output);

    void showFeedbackInputEdit(QString output);

signals:
    void relay(QString input);

    void run(QString input);

    void toStandardView(QString input, QString inputChecked);

private slots:
    void recieve(QString input);

    void enterTriggered();

    void changeViewTriggered();

private:
    void changeGeometry();
    int getPosX(int maxX);
    int getPosY(int maxY);

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
