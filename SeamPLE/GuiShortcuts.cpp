#include "GuiShortcuts.h"

GuiShortcuts::GuiShortcuts()
{
    _switchView = NULL;
    _undo = NULL;
    _redo = NULL;
    _add = NULL;
    _find = NULL;
    _display = NULL;
    _delete = NULL;
    _edit = NULL;
    _clear = NULL;
    _left = NULL;
    _right = NULL;
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
    if (_left != NULL)
    {
        delete _left;
    }
    if (_right != NULL)
    {
        delete _right;
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
    _undo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_1));

    _redo = new QAction(Gui);
    Gui->addAction(_redo);
    _redo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_2));

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

void GuiShortcuts::setStandardShortcutsTo(QMainWindow* Gui)
{
    setShortcutsTo(Gui);

    _left = new QAction(Gui);
    Gui->addAction(_left);
    _left->setShortcut(QKeySequence(Qt::Key_PageUp));

    _right = new QAction(Gui);
    Gui->addAction(_right);
    _right->setShortcut(QKeySequence(Qt::Key_PageDown));
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

QAction* GuiShortcuts::getLeftKey()
{
    return _left;
}

QAction* GuiShortcuts::getRightKey()
{
    return _right;
}

//QxtGlobalShortcut* GuiShortcuts::getShowHideViewKey()
//{
//    return _showHideView;
//}
