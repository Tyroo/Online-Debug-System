#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

using namespace std;

typedef QNetworkAccessManager _HttpManager;
typedef QNetworkRequest _HttpRequest;


class HttpxRequest
{

public:

    QNetworkReply* respone;

public:

    explicit HttpxRequest(QObject* parent = nullptr);

    ~HttpxRequest();

public:

    void get(QString url);

    void post(QString url, QJsonObject json);

    // ...

public:

    QJsonObject toJsonRespone(QNetworkReply *reply);

    QString toQStrRespone(QNetworkReply *reply);

public:

    int getNumValue(const QJsonObject& json, const QString& keys);

    QString getQStrValue(const QJsonObject& json, const QString& keys);

    bool getBoolValue(const QJsonObject& json, const QString& keys);

    void setSeparator(QString str);

    // ...

private:

    _HttpManager* _manager;

    _HttpRequest _request;

    QObject* _this;

    QString _separator;

private:

    QJsonValue _recursionFindJsonValue(const QJsonObject& json, const QString& strarr);

};


#endif
