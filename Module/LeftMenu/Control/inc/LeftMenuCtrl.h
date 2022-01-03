#ifndef LEFTMENUCTRL_H
#define LEFTMENUCTRL_H


#include "./Module/LeftMenu/View/inc/LeftMenuView.h"

#define LeftMenuView_ENABLE_DEBUGGER


class LeftMenuCtrl: public LeftMenuView
{
    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    LeftMenuCtrl();

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LeftMenuCtrl();

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister();

private slots:

    void eTreeItemCilckExpand(QTreeWidgetItem* item, int arg);


};


#endif
