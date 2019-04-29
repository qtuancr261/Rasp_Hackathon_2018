#include "hackathoncommunityapi.h"

HackathonCommunityAPI::HackathonCommunityAPI(QString hostname)
    : hostName{QString("http://%1").arg(hostname)},
      userName{"manager"},
      password{"smb2017"},
      networkManager{new QNetworkAccessManager(this)},
      networkRepliesHashMap{new QHash<QString, QNetworkReply*>()},
      networkRepliesMapper{new QSignalMapper(this)},
      repliesCount{},
      apiUpdateBusLatLong{"/api/v1/updateBusPosition"}
{
    QObject::connect(networkRepliesMapper, SIGNAL(mapped(QString)), this, SLOT(handleReply(QString)));
}

void HackathonCommunityAPI::updateLatLongRasp(QString location)
{
    qDebug() << "send update";
    QByteArray postData;
    postData.append(QString("location=%1").arg(location));
    QNetworkRequest requset((QUrl(hostName)));
    requset.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkReply* reply{networkManager->post(requset, postData)};
    QString replyID{QString::number(++repliesCount)};
    networkRepliesHashMap->insert(replyID, reply);
    networkRepliesMapper->setMapping(reply, replyID);
    QObject::connect(reply, SIGNAL(finished()), networkRepliesMapper, SLOT(map()));
    //QObject::connect(reply, SIGNAL(finished()), this, SLOT(donothing()));
}

void HackathonCommunityAPI::handleReply(QString replyID)
{
    QNetworkReply* reply{networkRepliesHashMap->value(replyID)};
    if (reply->error())
    {
        qDebug() << "ERROR";
        cout << reply->errorString().toStdString() << endl;
    }
    else
        //cout << reply->readAll().toStdString() << endl;
        qDebug() << ":3 received";
    reply->deleteLater();
}

void HackathonCommunityAPI::updateByLocation(int id)
{
    qDebug() << "Let's start";
    switch (id) {
    case 1:
        updateLatLongRasp(QString("10.8076523|106.6624106"));
        break;
    case 2:
        updateLatLongRasp(QString("10.8477678|106.7721297"));
        break;
    case 3:
        updateLatLongRasp(QString("10.801043|106.658754"));
        break;
    case 4:
        updateLatLongRasp(QString("10.792292|106.704957"));
        break;
    default:
        break;
    }
}
