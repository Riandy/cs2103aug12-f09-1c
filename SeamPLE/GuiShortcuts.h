#ifndef GUISHORTCUTS_H
#define GUISHORTCUTS_H

#include <QAction>
#include <QMainWindow>

class GuiShortcuts
{
public:
    ~GuiShortcuts();

    void setShortcutsTo(QMainWindow* Gui);

public:
    QAction* switchView;

};

#endif // GUISHORTCUTS_H
