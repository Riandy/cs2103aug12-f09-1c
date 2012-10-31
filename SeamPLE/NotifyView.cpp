#include "NotifyView.h"

NotifyView* NotifyView::_notificationInterface = NULL;

NotifyView::NotifyView()
{
    _popUp = new QSystemTrayIcon();
    _popUp->setIcon(QIcon(QPixmap(":/bg/pin icon.gif")));
    _popUp->show();
}

NotifyView::~NotifyView()
{
    delete _popUp;
}

bool NotifyView::singleInstanceExists()
{
    bool result;

    if (_notificationInterface == NULL)
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
        _notificationInterface = new NotifyView();
    }

    return _notificationInterface;
}

void NotifyView::endInstance()
{
    if (singleInstanceExists())
    {
        delete _notificationInterface;
        _notificationInterface = NULL;
    }
}

void NotifyView::showMessage(QString title, QString message, QSystemTrayIcon::MessageIcon icon)
{
    if (singleInstanceExists())
    {
        _popUp->showMessage(title, message, icon, 10000);
    }
}
