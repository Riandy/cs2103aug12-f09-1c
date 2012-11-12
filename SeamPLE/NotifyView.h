#ifndef NOTIFYVIEW_H
#define NOTIFYVIEW_H

#include <QSystemTrayIcon>

//@author: A0086030R

//NotifyView is a singleton class. To get an instance of this class, create a
//pointer and call getInstance to get the address of the instance. Delete by
//calling endInstance.
//This class provide a function called showMessage which displays a
//notification.

class NotifyView : public QObject
{
    Q_OBJECT

private:
    const static QString SYSTEM_ICON_LOCATION;
    const static QString SYSTEM_ICON_TOOLTIP;

    static NotifyView* _notificationInterface;
    QSystemTrayIcon* _popUp;

private:
    NotifyView();
    ~NotifyView();
    bool singleInstanceExists();

public:
    NotifyView* getInstance();
    void endInstance();
    void showMessage(QString title, QString message, QSystemTrayIcon::MessageIcon icon);

};

#endif // NOTIFYVIEW_H
