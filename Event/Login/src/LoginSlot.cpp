#include "./Event/Login/inc/LoginSlot.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：LoginSlot()、~LoginSlot()
--------------------------------------------------------------*/

// 主槽类构造方法
LoginSlot::LoginSlot(QObject* parent) : QObject(parent)
{
    // pass
}

// 主槽类析构方法
LoginSlot::~LoginSlot()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()、eSelectRedColor()、eSelectGreenColor()、
eSelectBlueColor()
--------------------------------------------------------------*/

// 槽注册方法
void LoginSlot::eSlotFuncRegister()
{
//    QObject::connect(ui->radioButton_4, SIGNAL(clicked(bool)),  // 连接红色单选框按钮槽
//                     this, SLOT(eSelectRedColor(bool)));
//    QObject::connect(ui->radioButton, SIGNAL(clicked(bool)),    // 连接蓝色单选框按钮槽
//                     this, SLOT(eSelectBlueColor(bool)));
//    QObject::connect(ui->radioButton_3, SIGNAL(clicked(bool)),  // 连接绿色单选框按钮槽
//                     this, SLOT(eSelectGreenColor(bool)));
}
