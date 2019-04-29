#ifndef HACKATHONCOMMUNITYAPI_H
#define HACKATHONCOMMUNITYAPI_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QHash>
#include <QSignalMapper>
#include <QUrl>
#include <QByteArray>
#include <QUrlQuery>
#include <iostream>
using std::cout;
using std::endl;
class HackathonCommunityAPI : public QObject
{
    Q_OBJECT
private:
    QString hostName;
    QString userName;
    QString password;
    QNetworkAccessManager* networkManager;
    QHash<QString, QNetworkReply*>* networkRepliesHashMap;
    QSignalMapper* networkRepliesMapper;
    int repliesCount;
    QString apiUpdateBusLatLong;
public:
    HackathonCommunityAPI(QString hostname = "localhost");
    void updateLatLongRasp(QString location);

public slots:
    void handleReply(QString replyID);
    void updateByLocation(int id);
};
#endif // HACKATHONCOMMUNITYAPI_H
