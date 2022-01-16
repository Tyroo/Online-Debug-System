#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

typedef QNetworkAccessManager _HttpManager;
typedef QNetworkRequest _HttpRequest;
typedef QNetworkReply _HttpRespone;

class HttpxRequest
{

public:

    _HttpRespone* respone;

public:

    explicit HttpxRequest(QObject* parent = nullptr);

    ~HttpxRequest();

public:

    void get(QString url);

    void post(QString url, QJsonObject json);

    // ...

public:

    QJsonObject toJsonRespone(_HttpRespone *reply);

    QString toQStrRespone(_HttpRespone *reply);

public:

    int getNumValue(const QJsonObject& json, const QString& keys);

    QString getQStrValue(const QJsonObject& json, const QString& keys);

    bool getBoolValue(const QJsonObject& json, const QString& keys);

    void setSeparator(QString str);

    // ...

private:

    QObject* _this;

    QString _separator;

    _HttpManager* _manager;

    _HttpRequest _request;

private:

    QJsonValue _recursionFindJsonValue(const QJsonObject& json, const QString& strarr);

};


#endif
