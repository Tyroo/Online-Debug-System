#ifndef LOGINCTRL_H
#define LOGINCTRL_H

#include "./Module/Login/View/inc/LoginView.h"
#include <QMessageBox>

/* #define LoginView_ENABLE_DEBUGGER */

using namespace std;

class LoginCtrl: public LoginView
{

    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    LoginCtrl();

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LoginCtrl();

private:

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister();

/* 非请求类槽函数 */
private slots:

    /*
    * @说明：点击注册按钮，开启动画滚动至注册页面
    * @参数：无
    * @返回值：无
    */
    void eLoginGotoSignPage(void);

    /*
    * @说明：点击返回登录按钮，开启动画滚动至登录页面
    * @参数：无
    * @返回值：无
    */
    void eSignGotoLoginPage(void);

/* 请求发送类槽函数 */
private slots:

    /*
    * @说明：登录按钮点击事件回调函数（发送异步登录请求）
    * @参数：无
    * @返回值：无
    */
    void eSubmitUserLoginInfo(void);

    /*
    * @说明：登录按钮点击事件回调函数（发送异步登录请求）
    * @参数：无
    * @返回值：无
    */
    void eSubmitUserSignInfo(void);

    /*
    * @说明：注册验证码请求按钮回调函数
    * @参数：无
    * @返回值：无
    */
    void eSignSendEmailInfo(void);

/* 请求响应类槽函数 */
private slots:

    /*
    * @说明：登录请求完成回调函数
    * @参数：reply，响应对象
    * @返回值：无
    */
    void eSubmitUserLoginInfoRespone(void);

    /*
    * @说明：注册请求完成回调函数
    * @参数：无
    * @返回值：无
    */
    void eSubmitUserSignInfoRespone(void);

};


#endif
