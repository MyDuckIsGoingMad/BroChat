#ifndef QCHATSTATISTIC
#define QCHATSTATISTIC

#include <QString>

class QChatStatistic
{
public:
    explicit QChatStatistic( const QString &service, const QString &statistic);
    virtual ~QChatStatistic();
public:
    QString service() const;
    void setService( const QString &service );

    QString statistic() const;
    void setStatistic( const QString &statistic );
private:
    QString service_;
    QString statistic_;
};

#endif // QCHATSTATISTIC

