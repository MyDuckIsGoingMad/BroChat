#ifndef QCHATMESSAGE_H
#define QCHATMESSAGE_H

#include <QString>
#include <QSharedPointer>

class QChatMessage
{
public:
    explicit QChatMessage();
    explicit QChatMessage( const QString &service, const QString &nickName, const QString &message, const QString &type);
    virtual ~QChatMessage();

    QString service() const;
    QString nickName() const;
    QString message() const;
    QString type() const;

    void setService( const QString &service );
    void setNickName( const QString &nickName );
    void setMessage( const QString &message );
    void setType( const QString &type );

    static QString deleteTags( const QString& message );
    static QString replaceEscapeCharecters( const QString &message );
    static bool isLink( const QString& link );
    static QString insertLinks( const QString &message, bool convertImageLinks = false );

private:
    QString service_;
    QString nickName_;
    QString message_;
    QString type_;
};

typedef QSharedPointer<QChatMessage> QChatMessageShared;

#endif // QCHATMESSAGE_H
