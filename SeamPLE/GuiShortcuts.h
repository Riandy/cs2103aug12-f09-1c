#ifndef GUISHORTCUTS_H
#define GUISHORTCUTS_H

#include <QAction>
#include <QMainWindow>

class GuiShortcuts: public QWidget
{
public:
    ~GuiShortcuts();

    void setShortcutsTo(QMainWindow* Gui);

public:
    QAction* switchView;

    QAction* undo;

    QAction* redo;

    QAction* changeWorkingTab;

    QAction* hideShowView;

};

#endif // GUISHORTCUTS_H
