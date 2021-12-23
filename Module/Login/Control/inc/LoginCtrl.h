#ifndef LOGINCTRL_H
#define LOGINCTRL_H

#include <QMessageBox>

#include "./Module/Login/View/inc/LoginView.h"

/* #define LoginView_ENABLE_DEBUGGER */


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

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister();

private slots:

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSubmitUserInfo(void);
};


#endif
