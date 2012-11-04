#include "GuiShortcuts.h"

GuiShortcuts::GuiShortcuts()
{
    _switchView = NULL;
    _undo = NULL;
    _redo = NULL;
    _add = NULL;
    _find = NULL;
    _findFloat = NULL;
    _display = NULL;
    _delete = NULL;
    _edit = NULL;
    _clear = NULL;
    _pageUp = NULL;
    _pageDown = NULL;
    _changeDisplay = NULL;
    _help = NULL;
    _changeTableView = NULL;
    _changeScreenOneView = NULL;
    _changeScreenTwoView = NULL;
    _changeScreenThreeView = NULL;
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
    if (_findFloat != NULL)
    {
        delete _findFloat;
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
    if (_pageUp != NULL)
    {
        delete _pageUp;
    }
    if (_pageDown != NULL)
    {
        delete _pageDown;
    }
    if (_changeDisplay != NULL)
    {
        delete _changeDisplay;
    }
    if (_help != NULL)
    {
        delete _help;
    }
    if (_changeTableView != NULL)
    {
        delete _changeTableView;
    }
    if (_changeScreenOneView != NULL)
    {
        delete _changeScreenOneView;
    }
    if (_changeScreenTwoView != NULL)
    {
        delete _changeScreenTwoView;
    }
    if (_changeScreenThreeView != NULL)
    {
        delete _changeScreenThreeView;
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
    _undo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));

    _redo = new QAction(Gui);
    Gui->addAction(_redo);
    _redo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));

    _add = new QAction(Gui);
    Gui->addAction(_add);
    _add->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

    _find = new QAction(Gui);
    Gui->addAction(_find);
    _find->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));

    _findFloat = new QAction(Gui);
    Gui->addAction(_findFloat);
    _findFloat->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_G));

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

    _help = new QAction(Gui);
    Gui->addAction(_help);
    _help->setShortcut(QKeySequence(Qt::Key_F1));
}

void GuiShortcuts::setStandardShortcutsTo(QMainWindow* Gui)
{
    setShortcutsTo(Gui);

    _pageUp = new QAction(Gui);
    Gui->addAction(_pageUp);
    _pageUp->setShortcut(QKeySequence(Qt::Key_PageUp));

    _pageDown = new QAction(Gui);
    Gui->addAction(_pageDown);
    _pageDown->setShortcut(QKeySequence(Qt::Key_PageDown));

    _changeDisplay = new QAction(Gui);
    Gui->addAction(_changeDisplay);
    _changeDisplay->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));

    _changeTableView = new QAction(Gui);
    Gui->addAction(_changeTableView);
    _changeTableView->setShortcut(QKeySequence(Qt::Key_Tab));

    _changeScreenOneView = new QAction(Gui);
    Gui->addAction(_changeScreenOneView);
    _changeScreenOneView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_1));

    _changeScreenTwoView = new QAction(Gui);
    Gui->addAction(_changeScreenTwoView);
    _changeScreenTwoView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_2));

    _changeScreenThreeView = new QAction(Gui);
    Gui->addAction(_changeScreenThreeView);
    _changeScreenThreeView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_3));
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

QAction* GuiShortcuts::getFindFloatKey()
{
    return _findFloat;
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

QAction* GuiShortcuts::getPageUpKey()
{
    return _pageUp;
}

QAction* GuiShortcuts::getPageDownKey()
{
    return _pageDown;
}

QAction* GuiShortcuts::getChangeDisplayKey()
{
    return _changeDisplay;
}

QAction* GuiShortcuts::getHelpKey()
{
    return _help;
}

QAction* GuiShortcuts::getChangeTableViewKey()
{
    return _changeTableView;
}

QAction* GuiShortcuts::getChangeScreenOneView()
{
    return _changeScreenOneView;
}

QAction* GuiShortcuts::getChangeScreenTwoView()
{
    return _changeScreenTwoView;
}

QAction* GuiShortcuts::getChangeScreenThreeView()
{
    return _changeScreenThreeView;
}

//QxtGlobalShortcut* GuiShortcuts::getShowHideViewKey()
//{
//    return _showHideView;
//}
