#ifndef NOTIFYVIEW_H
#define NOTIFYVIEW_H

#include <QSystemTrayIcon>

class NotifyView : public QObject
{
    Q_OBJECT

private:
    static NotifyView* notificationInterface;
    QSystemTrayIcon* popUp;

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
