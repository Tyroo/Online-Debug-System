#include "./Module/Login/Data/inc/LoginData.h"

using namespace std;

/*------------------------------------------------------------
@作用：主数据类默认方法
@包含：LoginData()、~LoginData()
--------------------------------------------------------------*/

// 主数据类构造方法
LoginData::LoginData(QObject* parent)
{
    // HTTP请求管理对象
    this->httpx = new HttpxRequest(parent);

    // 登陆数据请求
    this->login_username = QString();
    this->login_password = QString();

    // 注册/找回密码数据请求
    this->sign_username = QString();
    this->sign_password = QString();
    this->sign_enterpwd = QString();
    this->sign_emailnum = QString();
    this->sign_authcode = QString();
}

// 主数据类析构方法
LoginData::~LoginData()
{
    if (this->httpx != nullptr)
    {
        delete (this->httpx);
        this->httpx = nullptr;
    }
}

/*------------------------------------------------------------
@作用：主数据类自定义方法
@包含：mInitLoginData()
--------------------------------------------------------------*/

// 初始化主数据
void LoginData::mInitLoginData()
{
    // pass
}

// 登录请求接口
void LoginData::mRequestLoginInterface(const QString usr, const QString pwd)
{
    // 请求登录接口
    QJsonObject json_data;

    json_data.insert("username", usr);
    json_data.insert("passwd", pwd);

    this->httpx->post(QString(LOGINDATA_LOGIN_INTERFACE), json_data);
}

// 注册请求接口
void LoginData::mRequestSignInterface(const QString usr, const QString pwd,
    const QString enpwd, QString email, QString authcode)
{
    // 请求注册接口
    QJsonObject json_data;

    json_data.insert("username", usr);
    json_data.insert("passwd", pwd);
    /*
    json_data.insert("enpwd", enpwd);
    json_data.insert("email", email);
    json_data.insert("authcode", authcode);
    */
    this->httpx->post(QString(LOGINDATA_SIGN_INTERFACE), json_data);
}

