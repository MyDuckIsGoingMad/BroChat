#include "coremediator.h"
#include <QNetworkAccessManager>

CoreMediator *CoreMediator::m_self = nullptr;

CoreMediator &CoreMediator::instance()
{
    if(m_self == nullptr) m_self = new CoreMediator();
    return *m_self;
}

void CoreMediator::release()
{
    delete m_self;
    m_self = nullptr;
}

void CoreMediator::init()
{
    m_qnam = new QNetworkAccessManager(this);
}

void CoreMediator::registerChatService(QSharedPointer<QChatService> service)
{
    m_services.push_back(service);
    connect(service.data(), SIGNAL(newMessage(QChatMessageShared)), this, SIGNAL(newMessage(QChatMessageShared)));
    connect(service.data(), SIGNAL(newMessage(QChatMessageShared)), &m_history, SLOT(addMessage(QChatMessageShared)));
    connect(service.data(), SIGNAL(newStatistic(QChatStatistic *)), this, SIGNAL(newStatistic(QChatStatistic *)));
    connect(this, SIGNAL(reconnect()), service.data(), SLOT(doReconnect()));
    connect(this, SIGNAL(setShowSystemMessages(bool)), service.data(), SLOT(setShowSystemMessages(bool)));
}

QNetworkAccessManager *CoreMediator::qnam()
{
    return m_qnam;
}

QList<QAction *> CoreMediator::getActions()
{
    QList<QAction *> actions;
    for(auto service: m_services)
    {
        actions.push_back(service->getReconnectAction());
    }
    return actions;
}

QChatHistoryListModel *CoreMediator::historyListModel()
{
    return &m_history;
}


void CoreMediator::onReconnect()
{
    emit reconnect();
}

CoreMediator::CoreMediator(QObject *parent)
    : QObject(parent)
    , m_qnam(nullptr)
{

}
