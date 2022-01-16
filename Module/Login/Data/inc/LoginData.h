#ifndef LOGINDATA_H
#define LOGINDATA_H


#include "./Library/HttpxRequest/inc/HttpxRequest.h"


#define LOGINDATA_LOGIN_INTERFACE       ("http://159.75.110.166/login/")
#define LOGINDATA_SIGN_INTERFACE        ("http://159.75.110.166/login/register/")
#define LOGINDATA_RESETPWD_INTERFACE    ("https://www.baidu.com/Login")


class LoginData
{

public:

    HttpxRequest* httpx;

    /*
    * @说明：主数据类构造函数
    * @参数：无
    * @返回值：无
    */
    LoginData(QObject* parent = nullptr);

    /*
    * @说明：主数据类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LoginData();

    /*
    * @说明：登录请求接口
    * @参数：登录账号和密码
    * @返回值：无
    */
    void mRequestLoginInterface(const QString usr, const QString pwd);

    /*
    * @说明：注册请求接口
    * @参数：注册信息
    * @返回值：无
    */
    void mRequestSignInterface(const QString usr, const QString pwd,
        const QString enpwd, QString email, QString authcode);

private:

    QString login_username;
    QString login_password;

    QString sign_username;
    QString sign_password;
    QString sign_enterpwd;
    QString sign_emailnum;
    QString sign_authcode;

    /*
    * @说明：初始化主数据
    * @参数：无
    * @返回值：无
    */
    void mInitLoginData();

};

#endif
