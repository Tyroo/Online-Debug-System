#include "./Model/{$LOWER_MODULE_NAME}/inc/{$LOWER_MODULE_NAME}Data.h"


/*------------------------------------------------------------
@作用：主数据类默认方法
@包含：{$LOWER_MODULE_NAME}Data()、~{$LOWER_MODULE_NAME}Data()
--------------------------------------------------------------*/

// 主数据类构造方法
{$LOWER_MODULE_NAME}Data::{$LOWER_MODULE_NAME}Data()
{
    this->ui = new Ui::{$LOWER_MODULE_NAME}View;    // 创建主视图UI对象
}

// 主数据类析构方法
{$LOWER_MODULE_NAME}Data::~{$LOWER_MODULE_NAME}Data()
{
    // pass
}

/*------------------------------------------------------------
@作用：主数据类自定义方法
@包含：mInit{$LOWER_MODULE_NAME}Data()
--------------------------------------------------------------*/

// 初始化主数据
void {$LOWER_MODULE_NAME}Data::mInitData()
{
    // pass
}

