#ifndef LOGINCTRL_H
#define LOGINCTRL_H


#include <future>
#include "./Module/Login/View/inc/LoginView.h"

#define LoginView_ENABLE_DEBUGGER

using namespace std;

class LoginCtrl: public LoginView
{
    Q_OBJECT

public:

    future<bool> result;

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

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister();



private slots:

    /*
    * @说明：登录按钮点击事件回调函数（发送异步登录请求）
    * @参数：无
    * @返回值：无
    */
    void eSubmitUserInfo(void);
};


#endif
