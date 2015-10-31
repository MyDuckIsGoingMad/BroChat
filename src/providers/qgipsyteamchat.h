#ifndef QGIPSYTEAMCHAT
#define QGIPSYTEAMCHAT

#include "qchatservice.h"

class QGipsyTeamChat: public QChatService
{
    Q_OBJECT
public:
    explicit QGipsyTeamChat( QObject *parent = 0 );
    virtual ~QGipsyTeamChat();
protected:
    virtual void timerEvent( QTimerEvent *event );
    void createReconnectAction() override;
private:
    void loadSettings();

    void getChannelInfo();

    void loadMessages();
public slots:
    virtual void connect();
    virtual void disconnect();
    virtual void reconnect();
private slots:
    void onChannelInfoLoaded();
    void onChannelInfoLoadError();

    void onMessagesLoaded();
    void onMessagesLoadError();
private:
    QString channelName_;
    QString channelLink_;
    QString lastMessageId_;

    int updateMessagesTimerId_;
    int updateMessagesInterval_;

    int reconnectTimerId_;
    int reconnectInterval_;
};

#endif // QGIPSYTEAMCHAT

