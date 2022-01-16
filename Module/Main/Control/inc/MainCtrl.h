#ifndef MAINCTRL_H
#define MAINCTRL_H

#include "./Module/Main/View/inc/MainView.h"

#define MainView_ENABLE_DEBUGGER


class MainCtrl: public MainView
{
    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    MainCtrl();

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~MainCtrl();

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister();

private slots:

    /*
    * @说明：颜色选择单选按钮触发事件函数
    * @参数：无
    * @返回值：无
    */
    void eSelectColor(void);

    /*
    * @说明：点击用户登录
    * @参数：无
    * @返回值：无
    */
    void eClickUserLogin();

};


#endif
