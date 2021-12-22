#ifndef {$UPPER_MODULE_NAME}DATA_H
#define {$UPPER_MODULE_NAME}DATA_H

#include "ui_{$LOWER_MODULE_NAME}View.h"


class {$LOWER_MODULE_NAME}Data
{

public:

    Ui::{$LOWER_MODULE_NAME}View* ui;   // 声明一个主视图UI对象指针

    /*
    * @说明：主数据类构造函数
    * @参数：无
    * @返回值：无
    */
    {$LOWER_MODULE_NAME}Data();

    /*
    * @说明：主数据类析构函数
    * @参数：无
    * @返回值：无
    */
    ~{$LOWER_MODULE_NAME}Data();

private:

    /*
    * @说明：初始化数据
    * @参数：无
    * @返回值：无
    */
    void mInitData();

};

#endif

