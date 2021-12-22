#ifndef LOGINDATA_H
#define LOGINDATA_H

#include "ui_LoginView.h"


class LoginData
{

public:

    Ui::LoginView* ui;   // 声明一个主视图UI对象指针

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

private:

    /*
    * @说明：初始化数据
    * @参数：无
    * @返回值：无
    */
    void mInitData();

};

#endif

