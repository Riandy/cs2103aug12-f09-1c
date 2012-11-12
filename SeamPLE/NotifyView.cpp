#include "NotifyView.h"

//@LIU WEIYUAN: A0086030R

const QString NotifyView:: SYSTEM_ICON_LOCATION = ":/bg/pin icon.gif";
const QString NotifyView:: SYSTEM_ICON_TOOLTIP = "SeamPLE";

NotifyView* NotifyView::_notificationInterface = NULL;

NotifyView::NotifyView()
{
    _popUp = new QSystemTrayIcon();
    _popUp->setIcon(QIcon(QPixmap(SYSTEM_ICON_LOCATION)));
    _popUp->setToolTip(SYSTEM_ICON_TOOLTIP);
    _popUp->show();
}

NotifyView::~NotifyView()
{
    delete _popUp;
}

//NotifyView is another singleton class. In this function, a bool value is
//returned based on whether the instance exists or not
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

//This function gets the address of the singleton instance that exists
//for this class
NotifyView* NotifyView::getInstance()
{
    if (!singleInstanceExists())
    {
        _notificationInterface = new NotifyView();
    }

    return _notificationInterface;
}

//This function deletes the singleton instance if it still exists
void NotifyView::endInstance()
{
    if (singleInstanceExists())
    {
        delete _notificationInterface;
        _notificationInterface = NULL;
    }
}

//Show message reveals the contents to users in the form of a taskbar
//notification window
void NotifyView::showMessage(QString title, QString message,
                             QSystemTrayIcon::MessageIcon icon)
{
    if (singleInstanceExists())
    {
        int timeOut = 10000;
        _popUp->show();
        _popUp->showMessage(title, message, icon, timeOut);
    }
}
