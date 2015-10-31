#ifndef COREMEDIATOR_H
#define COREMEDIATOR_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "qchatservice.h"

class QNetworkAccessManager;
class QAction;

class CoreMediator : public QObject
{
    Q_OBJECT
public:
    static CoreMediator &instance();
    static void release();
    void init();
    void registerChatService(QSharedPointer<QChatService> service);
    QNetworkAccessManager *qnam();
    QList<QAction *> getActions();

protected:
    explicit CoreMediator(QObject *parent = 0);
    QList<QSharedPointer<QChatService>> m_services;

private:
    static CoreMediator *m_self;
    QNetworkAccessManager *m_qnam;

signals:
    void newMessage(QChatMessage *message);
    void newStatistic(QChatStatistic *statistic);
    void reconnect();
    void setShowSystemMessages(bool showSystemMessages);

public slots:
    void onReconnect();
};

template<class T> class ChatServiceRegistrator
{
public:
    ChatServiceRegistrator() {
        CoreMediator::instance().registerChatService(QSharedPointer<T>(new T()));
    }
};

#endif // COREMEDIATOR_H
