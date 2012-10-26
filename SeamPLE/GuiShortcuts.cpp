#include "GuiShortcuts.h"

GuiShortcuts::GuiShortcuts()
{
    _switchView = NULL;
    _undo = NULL;
    _redo = NULL;
    _changeWorkingTab = NULL;
    _add = NULL;
    _find = NULL;
    _display = NULL;
    _delete = NULL;
    _edit = NULL;
    _clear = NULL;
    //_showHideView = NULL;
}

GuiShortcuts::~GuiShortcuts()
{
    if (_switchView != NULL)
    {
        delete _switchView;
    }
    if (_undo != NULL)
    {
        delete _undo;
    }
    if (_redo != NULL)
    {
        delete _redo;
    }
    if (_changeWorkingTab != NULL)
    {
        delete _changeWorkingTab;
    }
    if (_add != NULL)
    {
        delete _add;
    }
    if (_find != NULL)
    {
        delete _find;
    }
    if (_display != NULL)
    {
        delete _display;
    }
    if (_delete != NULL)
    {
        delete _delete;
    }
    if (_edit != NULL)
    {
        delete _edit;
    }
    if (_clear != NULL)
    {
        delete _clear;
    }
//    if (_showHideView != NULL)
//    {
//        delete _showHideView;
//    }
}



void GuiShortcuts::setShortcutsTo(QMainWindow *Gui)
{
    _switchView = new QAction(Gui);
    Gui->addAction(_switchView);
    _switchView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));

    _undo = new QAction(Gui);
    Gui->addAction(_undo);
    _undo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));

    _redo = new QAction(Gui);
    Gui->addAction(_redo);
    _redo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));

    _add = new QAction(Gui);
    Gui->addAction(_add);
    _add->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

    _find = new QAction(Gui);
    Gui->addAction(_find);
    _find->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));

    _display = new QAction(Gui);
    Gui->addAction(_display);
    _display->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));

    _delete = new QAction(Gui);
    Gui->addAction(_delete);
    _delete->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));

    _edit = new QAction(Gui);
    Gui->addAction(_edit);
    _edit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));

    _clear = new QAction(Gui);
    Gui->addAction(_clear);
    _clear->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
}

void GuiShortcuts::setStandardShortcutsTo(QMainWindow *Gui)
{
    setShortcutsTo(Gui);

    _changeWorkingTab = new QAction(Gui);
    Gui->addAction(_changeWorkingTab);
    _changeWorkingTab->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
}

//void GuiShortcuts::setGlobalShortcuts()
//{
//    _showHideView = new QxtGlobalShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S),NULL);
//}

QAction* GuiShortcuts::getSwitchViewKey()
{
    return _switchView;
}

QAction* GuiShortcuts::getUndoKey()
{
    return _undo;
}

QAction* GuiShortcuts::getRedoKey()
{
    return _redo;
}

QAction* GuiShortcuts::getChangeWorkingTabKey()
{
    return _changeWorkingTab;
}

QAction* GuiShortcuts::getAddKey()
{
    return _add;
}

QAction* GuiShortcuts::getFindKey()
{
    return _find;
}

QAction* GuiShortcuts::getDisplayKey()
{
    return _display;
}

QAction* GuiShortcuts::getDeleteKey()
{
    return _delete;
}

QAction* GuiShortcuts::getEditKey()
{
    return _edit;
}

QAction* GuiShortcuts::getClearKey()
{
    return _clear;
}

//QxtGlobalShortcut* GuiShortcuts::getShowHideViewKey()
//{
//    return _showHideView;
//}
