#ifndef LOGINSLOT_H
#define LOGINSLOT_H

#include <QObject>

#include "./Model/Login/inc/LoginData.h"


class LoginSlot: public QObject, public LoginData
{
    Q_OBJECT

public:

    /*
    * @说明：主槽类构造函数
    * @参数：无
    * @返回值：无
    */
    LoginSlot(QObject* parent = nullptr);

    /*
    * @说明：主槽类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LoginSlot();

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSlotFuncRegister(void);

private slots:

    /*
    * @说明：槽注册方法
    * @参数：无
    * @返回值：无
    */
    void eSubmitUserInfo(void);

};


#endif
