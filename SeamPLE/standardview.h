#ifndef STANDARDVIEW_H
#define STANDARDVIEW_H

#include <QMainWindow>

namespace Ui {
class StandardView;
}

class StandardView : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit StandardView(QWidget *parent = 0);
    ~StandardView();
    
private:
    void changeAutoResolution();

    Ui::StandardView *ui;
};

#endif // STANDARDVIEW_H
