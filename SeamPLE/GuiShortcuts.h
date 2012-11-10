#ifndef GUISHORTCUTS_H
#define GUISHORTCUTS_H

#include <QAction>
#include <QMainWindow>
//#include <QxtGlobalShortcut>
#include <QApplication>

//@WEIYUAN A0086030R

//This class holds all the configurations for setting up shortcuts in
//the application. By calling the setShortcutTo or setStandardShortcuts
//to functions
class GuiShortcuts
{
public:
    GuiShortcuts();

    ~GuiShortcuts();

    //Generic methods to set the shortcuts into the interfaces
    void setShortcutsTo(QMainWindow* Gui);
    void setStandardShortcutsTo(QMainWindow* Gui);
    //void setGlobalShortcuts();

    //Methods to obtain the key for the shortcut
    QAction* getSwitchViewKey();
    QAction* getUndoKey();
    QAction* getRedoKey();
    QAction* getAddKey();
    QAction* getFindKey();
    QAction* getFindFloatKey();
    QAction* getDisplayKey();
    QAction* getDeleteKey();
    QAction* getEditKey();
    QAction* getClearKey();
    QAction* getPageUpKey();
    QAction* getPageDownKey();
    QAction* getChangeDisplayKey();
    QAction* getHelpKey();
    QAction* getChangeTableViewKey();
    QAction* getChangeScreenOneViewKey();
    QAction* getChangeScreenTwoViewKey();
    QAction* getChangeScreenThreeViewKey();
    QAction* getMarkKey();
    QAction* getTodayKey();
    //QxtGlobalShortcut* getShowHideViewKey();

private:
    //Methods to create the different shortcuts and integrate
    //them into the subject Gui
    void setSwitchView(QMainWindow* Gui);
    void setUndo(QMainWindow* Gui);
    void setRedo(QMainWindow* Gui);
    void setAdd(QMainWindow* Gui);
    void setFind(QMainWindow* Gui);
    void setFindFloat(QMainWindow* Gui);
    void setDisplay(QMainWindow* Gui);
    void setDelete(QMainWindow* Gui);
    void setEdit(QMainWindow* Gui);
    void setClear(QMainWindow* Gui);
    void setPageUp(QMainWindow* Gui);
    void setPageDown(QMainWindow* Gui);
    void setChangeDisplay(QMainWindow* Gui);
    void setHelp(QMainWindow* Gui);
    void setChangeTableView(QMainWindow* Gui);
    void setChangeScreenOneView(QMainWindow* Gui);
    void setChangeScreenTwoView(QMainWindow* Gui);
    void setChangeScreenThreeView(QMainWindow* Gui);
    void setMark(QMainWindow* Gui);
    void setToday(QMainWindow* Gui);

    //Methods to remove the dynamically allocated shortcuts
    void removeSwitchView();
    void removeUndo();
    void removeRedo();
    void removeAdd();
    void removeFind();
    void removeFindFloat();
    void removeDisplay();
    void removeDelete();
    void removeEdit();
    void removeClear();
    void removePageUp();
    void removePageDown();
    void removeChangeDisplay();
    void removeHelp();
    void removeChangeTableView();
    void removeChangeScreenOneView();
    void removeChangeScreenTwoView();
    void removeChangeScreenThreeView();
    void removeMark();
    void removeToday();
    //void removeShowHideView();

private:
    //Pointers to the shortcuts
    QAction* _switchView;
    QAction* _undo;
    QAction* _redo;
    QAction* _add;
    QAction* _find;
    QAction* _findFloat;
    QAction* _display;
    QAction* _delete;
    QAction* _edit;
    QAction* _clear;
    QAction* _pageUp;
    QAction* _pageDown;
    QAction* _changeDisplay;
    QAction* _help;
    QAction* _changeTableView;
    QAction* _changeScreenOneView;
    QAction* _changeScreenTwoView;
    QAction* _changeScreenThreeView;
    QAction* _mark;
    QAction* _today;
    //QxtGlobalShortcut * _showHideView;
};

#endif // GUISHORTCUTS_H
