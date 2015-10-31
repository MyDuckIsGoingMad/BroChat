#include "qchathistorylistmodel.h"

#include <QDebug>

namespace {
    QmlHelpers::QmlTypeRegistrator<QChatHistoryListModel> r("BroChat.Models", 1, 0, "QChatHistoryListModel");
}

QChatHistoryListModel::QChatHistoryListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_roles[(int)Roles::Message] = "message";
    m_roles[(int)Roles::Nickname] = "nickname";
    m_roles[(int)Roles::Service] = "service";
}

QHash<int, QByteArray> QChatHistoryListModel::roleNames() const
{
    return m_roles;
}

int QChatHistoryListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_messages.count();
}

QVariant QChatHistoryListModel::data(const QModelIndex &index, int role) const
{
    switch((Roles)role)
    {
        case Roles::Message:
            return m_messages.at(index.row())->message();
            break;
        case Roles::Nickname:
            return m_messages.at(index.row())->nickName();
            break;
        case Roles::Service:
            return m_messages.at(index.row())->service();
            break;
    }
    return QVariant();
}

void QChatHistoryListModel::addMessage(QChatMessageShared message)
{
    qDebug() << message->message();
    beginInsertRows(QModelIndex(), m_messages.size(), m_messages.size());
    m_messages.push_back(message);
    endInsertRows();
}
