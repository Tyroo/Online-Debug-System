#ifndef LOGINDATA_H
#define LOGINDATA_H

#include <QString>
#include <iostream>
#include <QThread>

#define LOGINDATA_LOGIN_INTERFACE       ("https://www.baidu.com/Login")
#define LOGINDATA_SIGN_INTERFACE        ("https://www.baidu.com/Login")
#define LOGINDATA_RESETPWD_INTERFACE    ("https://www.baidu.com/Login")


class LoginData
{

public:

    /*
    * @说明：主数据类构造函数
    * @参数：无
    * @返回值：无
    */
    LoginData();

    /*
    * @说明：主数据类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LoginData();

    /*
    * @说明：发送登录请求
    * @参数：无
    * @返回值：无
    */
    bool mRequestLoginInterface(const QString& usr, const QString& pwd);

    /*
    * @说明：发送注册请求
    * @参数：无
    * @返回值：无
    */
    bool mRequestSignInterface(const QString& usr, const QString& pwd,
        const QString& enpwd, QString& email, QString& authcode);

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
