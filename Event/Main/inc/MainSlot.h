#ifndef MAINSLOT_H
#define MAINSLOT_H

#include "./Model/Main/inc/MainData.h"

namespace MainModel { class MainData; }


class MainSlot: public MainData
{

public:

    /*
    * @说明：主视图槽构造函数
    * @参数：无
    * @返回值：无
    */
    MainSlot();

    /*
    * @说明：主视图槽析构函数
    * @参数：无
    * @返回值：无
    */
    ~MainSlot();

private:

    /*
    * @说明：颜色选择块复选框单击触发事件（当前未绑定）
    * @参数：无
    * @返回值：无
    */
    void eSelectColor(void);

};


#endif
