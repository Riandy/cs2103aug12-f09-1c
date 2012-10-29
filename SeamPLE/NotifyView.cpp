#include "NotifyView.h"

NotifyView* NotifyView::notificationInterface = NULL;

NotifyView::NotifyView()
{
    popUp = new QSystemTrayIcon();
    popUp->setIcon(QIcon(QPixmap(":/bg/pin icon.gif")));
    popUp->show();
}

NotifyView::~NotifyView()
{
    delete popUp;
}

bool NotifyView::singleInstanceExists()
{
    bool result;

    if (notificationInterface == NULL)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

NotifyView* NotifyView::getInstance()
{
    if (!singleInstanceExists())
    {
        notificationInterface = new NotifyView();
    }

    return notificationInterface;
}

void NotifyView::endInstance()
{
    if (singleInstanceExists())
    {
        delete notificationInterface;
        notificationInterface = NULL;
    }
}

void NotifyView::showMessage(QString title, QString message, QSystemTrayIcon::MessageIcon icon)
{
    if (singleInstanceExists())
    {
        popUp->showMessage(title, message, icon, 10000);
    }
}
