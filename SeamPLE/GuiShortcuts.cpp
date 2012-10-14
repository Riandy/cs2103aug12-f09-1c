#include "GuiShortcuts.h"

GuiShortcuts::~GuiShortcuts()
{
    delete switchView;
}

void GuiShortcuts::setShortcutsTo(QMainWindow *Gui)
{
    switchView = new QAction(Gui);
    Gui->addAction(switchView);
    switchView->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
}
