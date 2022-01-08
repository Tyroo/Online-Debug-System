#include "./Module/Login/Data/inc/LoginData.h"

using namespace std;

/*------------------------------------------------------------
@作用：主数据类默认方法
@包含：LoginData()、~LoginData()
--------------------------------------------------------------*/

// 主数据类构造方法
LoginData::LoginData()
{
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
    // pass
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

// 发送登录请求
bool LoginData::mRequestLoginInterface(const QString& usr, const QString& pwd)
{
    // 请求登录接口
    // LOGINDATA_LOGIN_INTERFACE
    QThread t;
    t.sleep(5);
    return false;
}

