#ifndef GUISHORTCUTS_H
#define GUISHORTCUTS_H

#include <QAction>
#include <QMainWindow>
#include <QString>

class GuiShortcuts
{
public:
    //Following will contain strings that will be used by StandardView and SeampleView
    //in triggering of the shortcuts
    const static QString COMMAND_UNDO;
    const static QString COMMAND_REDO;
    const static QString COMMAND_ADD;
    const static QString COMMAND_FIND;
    const static QString COMMAND_DISPLAY;
    const static QString COMMAND_DELETE;
    const static QString COMMAND_EDIT;

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

    QAction* getClearKey();

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
    QAction* _clear;
};

#endif // GUISHORTCUTS_H
