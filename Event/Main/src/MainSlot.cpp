#include "./Event/Main/inc/MainSlot.h"


/*------------------------------------------------------------
@：作用：主视图类默认方法
@：包含：MainSlot()、~MainSlot()
--------------------------------------------------------------*/

// 主槽构造方法
MainSlot::MainSlot()
{
    // pass
}

// 主槽析构方法
MainSlot::~MainSlot()
{
    // pass
}

/*------------------------------------------------------------
@：作用：主槽自定义方法
@：包含：eSelectColor()
--------------------------------------------------------------*/

// 选择颜色复选框选中触发事件函数
void MainSlot::eSelectColor()
{
    /* 红色复选框事件 */

    if (ui->checkBox->checkState())
    {
        ui->textEdit->setText("红色");
    }
    else
    {
        ui->textEdit->setText("请选择颜色");
    }
}
