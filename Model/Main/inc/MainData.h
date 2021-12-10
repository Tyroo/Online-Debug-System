#ifndef MAINDATA_H
#define MAINDATA_H

#include "ui_MainView.h"


class MainData
{

public:

    Ui::MainView *ui;   // 声明一个主视图UI对象指针

    /*
    * @说明：主数据类构造函数
    * @参数：无
    * @返回值：无
    */
    MainData();

    /*
    * @说明：主数据类析构函数
    * @参数：无
    * @返回值：无
    */
    ~MainData();

private:

    /*
    * @说明：初始化主数据
    * @参数：无
    * @返回值：无
    */
    void mInitMainData(void);
};

namespace MainModel { class MainData; }

#endif
