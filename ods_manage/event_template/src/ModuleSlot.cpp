#include "./Event/{$LOWER_MODULE_NAME}/inc/{$LOWER_MODULE_NAME}Slot.h"
#include <QMessageBox>

/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：{$LOWER_MODULE_NAME}Slot()、~{$LOWER_MODULE_NAME}Slot()
--------------------------------------------------------------*/

// 主槽类构造方法
{$LOWER_MODULE_NAME}Slot::{$LOWER_MODULE_NAME}Slot(QObject* parent) : QObject(parent)
{
    // pass
}

// 主槽类析构方法
{$LOWER_MODULE_NAME}Slot::~{$LOWER_MODULE_NAME}Slot()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/
// 槽注册方法
void {$LOWER_MODULE_NAME}Slot::eSlotFuncRegister()
{

}

