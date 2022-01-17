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
void LoginData::mRequestLoginInterface()
{
    // 请求登录接口
    QJsonObject json_data;

    json_data.insert("username", this->login_username);
    json_data.insert("passwd", this->login_password);

    this->httpx->post(QString(LOGINDATA_LOGIN_INTERFACE), json_data);
}

// 注册请求接口
void LoginData::mRequestSignInterface()
{
    // 请求注册接口
    QJsonObject json_data;

    json_data.insert("username", this->sign_username);
    json_data.insert("passwd", this->sign_password);
    /*
    json_data.insert("enpwd", this->sign_enterpwd);
    json_data.insert("email", this->sign_emailnum);
    json_data.insert("authcode", this->sign_authcode);
    */
    this->httpx->post(QString(LOGINDATA_SIGN_INTERFACE), json_data);
}

