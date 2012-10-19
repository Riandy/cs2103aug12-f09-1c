#include "GuiShortcuts.h"

GuiShortcuts::~GuiShortcuts()
{
    delete switchView;
    delete hideShowView;
}

void GuiShortcuts::setShortcutsTo(QMainWindow *Gui)
{
    switchView = new QAction(Gui);
    Gui->addAction(switchView);
    switchView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));

    hideShowView = new QAction(Gui);
    Gui->addAction(hideShowView);
    hideShowView->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S));
    hideShowView->setShortcutContext(Qt::ApplicationShortcut);
}
