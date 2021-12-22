#ifndef {$UPPER_MODULE_NAME}SLOT_H
#define {$UPPER_MODULE_NAME}SLOT_H

#include <QObject>

#include "./Model/{$LOWER_MODULE_NAME}/inc/{$LOWER_MODULE_NAME}Data.h"


class {$LOWER_MODULE_NAME}Slot: public QObject, public {$LOWER_MODULE_NAME}Data
{
    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    {$LOWER_MODULE_NAME}Slot(QObject* parent = nullptr);

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~{$LOWER_MODULE_NAME}Slot();

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister(void);

private slots:


};


#endif
