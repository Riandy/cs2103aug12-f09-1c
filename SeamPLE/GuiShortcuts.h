#ifndef GUISHORTCUTS_H
#define GUISHORTCUTS_H

#include <QAction>
#include <QMainWindow>


class GuiShortcuts
{

public:
    GuiShortcuts();

    ~GuiShortcuts();

    void setShortcutsTo(QMainWindow* Gui);

    void setStandardShortcutsTo(QMainWindow* Gui);

    QAction* getSwitchViewKey();

    QAction* getUndoKey();

    QAction* getRedoKey();

    QAction* getChangeWorkingTabKey();

    QAction* getAddKey();

    QAction* getFindKey();

    QAction* getDisplayKey();

    QAction* getDeleteKey();

    QAction* getEditKey();

private:
    QAction* _switchView;
    QAction* _undo;
    QAction* _redo;
    QAction* _changeWorkingTab;
    QAction* _add;
    QAction* _find;
    QAction* _display;
    QAction* _delete;
    QAction* _edit;
};

#endif // GUISHORTCUTS_H
