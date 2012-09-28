#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void changeGeometry();
    int getPosX(int maxX);
    int getPosY(int maxY);

    Ui::MainWindow *ui;
    QPoint dragStartPosition;

};

#endif // MAINWINDOW_H
