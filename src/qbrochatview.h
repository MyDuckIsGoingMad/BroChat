#ifndef QBROCHATVIEW
#define QBROCHATVIEW

#include <QSettings>

#include <QWebView>
#include "coremediator.h"

class QChatMessage;
class QChatStatistic;

class QChatUpdateServer;

class QBroChatView: public QWebView
{
    Q_OBJECT
public:
    explicit QBroChatView( QWidget *parent = 0 );
    virtual ~QBroChatView();

    void addMessage( const QString &service, const QString &nickName, const QString &message, const QString &type );
protected:
    virtual void mousePressEvent( QMouseEvent *event );
    virtual void mouseMoveEvent( QMouseEvent *event );
    virtual void mouseReleaseEvent( QMouseEvent *event );

    //virtual void keyPressEvent( QKeyEvent *event );

    virtual void closeEvent( QCloseEvent *event );

    virtual void timerEvent( QTimerEvent *event );
private:
    CoreMediator &m_core;
    void loadSettings();
    bool isLink( const QString& str );
public slots:
    void slotNewMessage( QChatMessage *message );
    void onNewStatistic( QChatStatistic *statistic );
    void saveSettings();
    void showSettings();

    void loadFlagsAndAttributes();

    void changeStyle( const QString& styleName );

    void changeShowSystemMessagesState();
    void changeShowImagesState();
    void changeUseServerState();
    void changeSaveToFileState();

private slots:
    void changeStyle();
    void changeOpacity();
    void onLinkClicked( const QUrl &url );
signals:
    void closeWindow();
private:
    QChatUpdateServer *chatUpdateServer_;

    QSettings settings_;

    bool moveState_;
    QPoint mouseStartPos_;

    int updatePictureId_;
    int updatePictureInterval_;


    bool showSystemMessages_;
    bool showImages_;
    bool saveToFile_;
};

#endif // QBROCHATVIEW

