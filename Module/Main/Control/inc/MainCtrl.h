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
    * @说明：红色单选按钮触发事件
    * @参数：无
    * @返回值：无
    */
    void eSelectRedColor(bool checked);

    /*
    * @说明：绿色单选按钮触发事件
    * @参数：无
    * @返回值：无
    */
    void eSelectGreenColor(bool checked);

    /*
    * @说明：蓝色单选按钮触发事件
    * @参数：无
    * @返回值：无
    */
    void eSelectBlueColor(bool checked);

    /*
    * @说明：点击用户登录
    * @参数：无
    * @返回值：无
    */
    void eClickUserLogin();
};


#endif
