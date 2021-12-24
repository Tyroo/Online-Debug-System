#ifndef LOGINDATA_H
#define LOGINDATA_H

#include <QString>

class LoginCtrl;
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
    * @说明：获取登录用户名
    * @参数：无
    * @返回值：无
    */
    QString& mGetUsername(void);

    /*
    * @说明：获取登录密码
    * @参数：无
    * @返回值：无
    */
    QString& mGetPassword(void);

private:

    QString username;
    QString password;
    /*
    * @说明：初始化主数据
    * @参数：无
    * @返回值：无
    */
    void mInitLoginData(void);
};

#endif
