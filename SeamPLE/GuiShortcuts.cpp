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
    _mark = NULL;
    _today = NULL;
    //_showHideView = NULL;
}

GuiShortcuts::~GuiShortcuts()
{
    removeSwitchView();
    removeUndo();
    removeRedo();
    removeAdd();
    removeFind();
    removeFindFloat();
    removeDisplay();
    removeDelete();
    removeEdit();
    removeClear();
    removePageUp();
    removePageDown();
    removeChangeDisplay();
    removeHelp();
    removeChangeTableView();
    removeChangeScreenOneView();
    removeChangeScreenTwoView();
    removeChangeScreenThreeView();
    removeMark();
    removeToday();
    //removeShowHideView();
}



void GuiShortcuts::setShortcutsTo(QMainWindow *Gui)
{
    setSwitchView(Gui);
    setUndo(Gui);
    setRedo(Gui);
    setAdd(Gui);
    setFind(Gui);
    setFindFloat(Gui);
    setDisplay(Gui);
    setDelete(Gui);
    setEdit(Gui);
    setClear(Gui);
    setHelp(Gui);
    setMark(Gui);
    setToday(Gui);
}

void GuiShortcuts::setStandardShortcutsTo(QMainWindow* Gui)
{
    setShortcutsTo(Gui);
    setPageUp(Gui);
    setPageDown(Gui);
    setChangeDisplay(Gui);
    setChangeTableView(Gui);
    setChangeScreenOneView(Gui);
    setChangeScreenTwoView(Gui);
    setChangeScreenThreeView(Gui);
}

//void GuiShortcuts::setGlobalShortcuts()
//{
//    if (_showHideView == NULL)
//    {
//        _showHideView = new QxtGlobalShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S),NULL);
//    }
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

QAction* GuiShortcuts::getChangeScreenOneViewKey()
{
    return _changeScreenOneView;
}

QAction* GuiShortcuts::getChangeScreenTwoViewKey()
{
    return _changeScreenTwoView;
}

QAction* GuiShortcuts::getChangeScreenThreeViewKey()
{
    return _changeScreenThreeView;
}

QAction* GuiShortcuts::getMarkKey()
{
    return  _mark;
}

QAction* GuiShortcuts::getTodayKey()
{
    return _today;
}

//QxtGlobalShortcut* GuiShortcuts::getShowHideViewKey()
//{
//    return _showHideView;
//}

void GuiShortcuts::setSwitchView(QMainWindow* Gui)
{
    if (_switchView == NULL)
    {
        _switchView = new QAction(Gui);
        Gui->addAction(_switchView);
        _switchView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    }
}

void GuiShortcuts::setUndo(QMainWindow* Gui)
{
    if (_undo == NULL)
    {
        _undo = new QAction(Gui);
        Gui->addAction(_undo);
        _undo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    }
}

void GuiShortcuts::setRedo(QMainWindow* Gui)
{
    if (_redo == NULL)
    {
        _redo = new QAction(Gui);
        Gui->addAction(_redo);
        _redo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    }
}

void GuiShortcuts::setAdd(QMainWindow* Gui)
{
    if (_add == NULL)
    {
        _add = new QAction(Gui);
        Gui->addAction(_add);
        _add->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    }
}

void GuiShortcuts::setFind(QMainWindow* Gui)
{
    if (_find == NULL)
    {
        _find = new QAction(Gui);
        Gui->addAction(_find);
        _find->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    }
}

void GuiShortcuts::setFindFloat(QMainWindow* Gui)
{
    if (_findFloat == NULL)
    {
        _findFloat = new QAction(Gui);
        Gui->addAction(_findFloat);
        _findFloat->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_G));
    }
}

void GuiShortcuts::setDisplay(QMainWindow* Gui)
{
    if (_display == NULL)
    {
        _display = new QAction(Gui);
        Gui->addAction(_display);
        _display->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    }
}

void GuiShortcuts::setDelete(QMainWindow* Gui)
{
    if (_delete == NULL)
    {
        _delete = new QAction(Gui);
        Gui->addAction(_delete);
        _delete->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    }
}

void GuiShortcuts::setEdit(QMainWindow* Gui)
{
    if (_edit == NULL)
    {
        _edit = new QAction(Gui);
        Gui->addAction(_edit);
        _edit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));
    }
}

void GuiShortcuts::setClear(QMainWindow* Gui)
{
    if (_clear == NULL)
    {
        _clear = new QAction(Gui);
        Gui->addAction(_clear);
        _clear->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
    }
}

void GuiShortcuts::setPageUp(QMainWindow* Gui)
{
    if (_pageUp == NULL)
    {
        _pageUp = new QAction(Gui);
        Gui->addAction(_pageUp);
        _pageUp->setShortcut(QKeySequence(Qt::Key_PageUp));
    }
}

void GuiShortcuts::setPageDown(QMainWindow* Gui)
{
    if (_pageDown == NULL)
    {
        _pageDown = new QAction(Gui);
        Gui->addAction(_pageDown);
        _pageDown->setShortcut(QKeySequence(Qt::Key_PageDown));
    }
}

void GuiShortcuts::setChangeDisplay(QMainWindow* Gui)
{
    if (_changeDisplay == NULL)
    {
        _changeDisplay = new QAction(Gui);
        Gui->addAction(_changeDisplay);
        _changeDisplay->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Tab));
    }
}

void GuiShortcuts::setHelp(QMainWindow* Gui)
{
    if (_help == NULL)
    {
        _help = new QAction(Gui);
        Gui->addAction(_help);
        _help->setShortcut(QKeySequence(Qt::Key_F1));
    }
}

void GuiShortcuts::setChangeTableView(QMainWindow* Gui)
{
    if (_changeTableView == NULL)
    {
        _changeTableView = new QAction(Gui);
        Gui->addAction(_changeTableView);
        _changeTableView->setShortcut(QKeySequence(Qt::Key_Tab));
    }
}

void GuiShortcuts::setChangeScreenOneView(QMainWindow* Gui)
{
    if (_changeScreenOneView == NULL)
    {
        _changeScreenOneView = new QAction(Gui);
        Gui->addAction(_changeScreenOneView);
        _changeScreenOneView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_1));
    }
}

void GuiShortcuts::setChangeScreenTwoView(QMainWindow* Gui)
{
    if (_changeScreenTwoView == NULL)
    {
        _changeScreenTwoView = new QAction(Gui);
        Gui->addAction(_changeScreenTwoView);
        _changeScreenTwoView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_2));
    }
}

void GuiShortcuts::setChangeScreenThreeView(QMainWindow* Gui)
{
    if (_changeScreenThreeView == NULL)
    {
        _changeScreenThreeView = new QAction(Gui);
        Gui->addAction(_changeScreenThreeView);
        _changeScreenThreeView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_3));
    }
}

void GuiShortcuts::setMark(QMainWindow* Gui)
{
    if (_mark == NULL)
    {
        _mark = new QAction(Gui);
        Gui->addAction(_mark);
        _mark->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));
    }
}

void GuiShortcuts::setToday(QMainWindow* Gui)
{
    if (_today == NULL)
    {
        _today = new QAction(Gui);
        Gui->addAction(_today);
        _today->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    }
}

void GuiShortcuts::removeSwitchView()
{
    if (_switchView != NULL)
    {
        delete _switchView;
        _switchView = NULL;
    }
}

void GuiShortcuts::removeUndo()
{
    if (_undo != NULL)
    {
        delete _undo;
        _undo = NULL;
    }
}

void GuiShortcuts::removeRedo()
{
    if (_redo != NULL)
    {
        delete _redo;
        _redo = NULL;
    }
}

void GuiShortcuts::removeAdd()
{
    if (_add != NULL)
    {
        delete _add;
        _add = NULL;
    }
}

void GuiShortcuts::removeFind()
{
    if (_find != NULL)
    {
        delete _find;
        _find = NULL;
    }
}

void GuiShortcuts::removeFindFloat()
{
    if (_findFloat != NULL)
    {
        delete _findFloat;
        _findFloat = NULL;
    }
}

void GuiShortcuts::removeDisplay()
{
    if (_display != NULL)
    {
        delete _display;
        _display = NULL;
    }
}

void GuiShortcuts::removeDelete()
{
    if (_delete != NULL)
    {
        delete _delete;
        _delete = NULL;
    }
}

void GuiShortcuts::removeEdit()
{
    if (_edit != NULL)
    {
        delete _edit;
        _edit = NULL;
    }
}

void GuiShortcuts::removeClear()
{
    if (_clear != NULL)
    {
        delete _clear;
        _clear = NULL;
    }
}

void GuiShortcuts::removePageUp()
{
    if (_pageUp != NULL)
    {
        delete _pageUp;
        _pageUp = NULL;
    }
}

void GuiShortcuts::removePageDown()
{
    if (_pageDown != NULL)
    {
        delete _pageDown;
        _pageDown = NULL;
    }
}

void GuiShortcuts::removeChangeDisplay()
{
    if (_changeDisplay != NULL)
    {
        delete _changeDisplay;
        _changeDisplay = NULL;
    }
}

void GuiShortcuts::removeHelp()
{
    if (_help != NULL)
    {
        delete _help;
        _help = NULL;
    }
}

void GuiShortcuts::removeChangeTableView()
{
    if (_changeTableView != NULL)
    {
        delete _changeTableView;
        _changeTableView = NULL;
    }
}

void GuiShortcuts::removeChangeScreenOneView()
{
    if (_changeScreenOneView != NULL)
    {
        delete _changeScreenOneView;
        _changeScreenOneView = NULL;
    }
}

void GuiShortcuts::removeChangeScreenTwoView()
{
    if (_changeScreenTwoView != NULL)
    {
        delete _changeScreenTwoView;
        _changeScreenTwoView = NULL;
    }
}

void GuiShortcuts::removeChangeScreenThreeView()
{
    if (_changeScreenThreeView != NULL)
    {
        delete _changeScreenThreeView;
        _changeScreenThreeView = NULL;
    }
}

void GuiShortcuts::removeMark()
{
    if (_mark != NULL)
    {
        delete _mark;
        _mark = NULL;
    }
}

void GuiShortcuts::removeToday()
{
    if (_today != NULL)
    {
        delete _today;
        _today = NULL;
    }
}

//void GuiShortcuts::removeShowHideView()
//{
//    if (_showHideView != NULL)
//    {
//        delete _showHideView;
//        _showHideView = NULL;
//    }
//}
