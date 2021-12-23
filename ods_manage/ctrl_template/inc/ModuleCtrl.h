#ifndef {$UPPER_MODULE_NAME}CTRL_H
#define {$UPPER_MODULE_NAME}CTRL_H


#include "./Module/{$LOWER_MODULE_NAME}/View/inc/{$LOWER_MODULE_NAME}View.h"

/* #define {$LOWER_MODULE_NAME}View_ENABLE_DEBUGGER */


class {$LOWER_MODULE_NAME}Ctrl: public {$LOWER_MODULE_NAME}View
{
    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    {$LOWER_MODULE_NAME}Ctrl();

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~{$LOWER_MODULE_NAME}Ctrl();

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister();

private slots:

};


#endif
