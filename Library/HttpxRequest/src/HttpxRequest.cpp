#include "./Library/HttpxRequest/inc/HttpxRequest.h"


HttpxRequest::HttpxRequest(QObject* parent)
{
    Q_ASSERT(parent != nullptr);

    this->_this = parent;
    this->_manager = new _HttpManager(this->_this);
    this->_separator = ">";
}


HttpxRequest::~HttpxRequest()
{
    if (this->_manager != nullptr)
    {
        delete (this->_manager);
        this->_manager = nullptr;
    }
}


/*------------------------------------------------------------
@作用：请求类封装
@包含：get()、post()
--------------------------------------------------------------*/

// GET请求封装
void HttpxRequest::get(QString url)
{
    Q_ASSERT(url.size());

    this->_request.setUrl(QUrl(url));
    this->_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    this->respone = this->_manager->get(this->_request);
}

// POST请求封装
void HttpxRequest::post(QString url, QJsonObject json)
{
    Q_ASSERT(url.size());
    Q_ASSERT(!json.isEmpty());

    QJsonDocument document;

    document.setObject(json);

    this->_request.setUrl(QUrl(url));
    this->_request.setHeader(_HttpRequest::ContentTypeHeader, "application/json");
    this->respone = this->_manager->post(this->_request, document.toJson());
}


/*------------------------------------------------------------
@作用：响应类封装
@包含：toJsonRespone()、toQStrRespone()
--------------------------------------------------------------*/

// 返回QJsonObject类型的响应数据
QJsonObject HttpxRequest::toJsonRespone(_HttpRespone *reply)
{
    QByteArray byte = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byte);
    QJsonObject jsonObj = jsonDoc.object();

    reply->deleteLater();

    return (jsonObj);
}

// 返回QString类型的响应数据
QString HttpxRequest::toQStrRespone(_HttpRespone *reply)
{
    QByteArray byte = reply->readAll();
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QString data = codec->toUnicode(byte);

    reply->deleteLater();

    return (data);
}


/*------------------------------------------------------------
@作用：响应类封装
@包含：toJsonRespone()、toQStrRespone()
--------------------------------------------------------------*/

// 获取Json中的数值型数据
int HttpxRequest::getNumValue(const QJsonObject& json, const QString& keys)
{
    QJsonValue jsonValue = this->_recursionFindJsonValue(json, keys);

    Q_ASSERT((!jsonValue.isUndefined()) && (!jsonValue.isNull()));

    return (jsonValue.toInteger());
}

// 获取Json中的字符串型数据
QString HttpxRequest::getQStrValue(const QJsonObject& json, const QString& keys)
{
    QJsonValue jsonValue = this->_recursionFindJsonValue(json, keys);

    Q_ASSERT((!jsonValue.isUndefined()) && (!jsonValue.isNull()));

    return (jsonValue.toString());
}

// 获取Json中的BOOL型数据
bool HttpxRequest::getBoolValue(const QJsonObject& json, const QString& keys)
{
    QJsonValue jsonValue = this->_recursionFindJsonValue(json, keys);

    Q_ASSERT((!jsonValue.isUndefined()) && (!jsonValue.isNull()));

    return (jsonValue.toBool());
}

// 设置递归查找分隔符
void HttpxRequest::setSeparator(QString str)
{
    Q_ASSERT(str.size());

    this->_separator = str;
}

// 递归查找QJsonValue
QJsonValue HttpxRequest::_recursionFindJsonValue(const QJsonObject& json, const QString& strarr)
{
    quint8 strListLen;
    QStringList strList;
    QJsonValue jsonValue;
    QJsonObject jsonv;

    jsonv = json;
    strList = strarr.split(this->_separator);
    strListLen = strList.size();

    Q_ASSERT(strListLen > 0);

    for (int i = 0; i < strListLen; i++)
    {
        jsonValue = jsonv.value(strList[i]);

        if (!jsonValue.isObject()) { break; }

        jsonv = jsonValue.toObject();
    }

    return (jsonValue);
}
