#ifndef MAINSLOT_H
#define MAINSLOT_H

#include <QObject>
#include <QMainWindow>
#include "./Model/Main/inc/MainData.h"

namespace MainModel { class MainData; }


class MainSlot: public QObject, public MainData
{
    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    MainSlot(QObject* parent = nullptr);

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~MainSlot();

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
};


#endif
