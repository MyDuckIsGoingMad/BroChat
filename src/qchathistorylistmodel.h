#ifndef QCHATHISTORYLISTMODEL_H
#define QCHATHISTORYLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <qchatmessage.h>
#include "helpers.h"

class QChatHistoryListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum class Roles: int
    {
        Message = Qt::UserRole,
        Nickname,
        Service
    };
    QChatHistoryListModel(QObject *parent = 0);
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const override;

private:
    QList<QChatMessageShared> m_messages;
    QHash<int, QByteArray> m_roles;

public slots:
    void addMessage(QChatMessageShared message);

signals:
void messageChanged(QString message);
};

#endif // QCHATHISTORYLISTMODEL_H
