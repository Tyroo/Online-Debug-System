#include "./Event/Main/inc/MainSlot.h"
#include "qnamespace.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：MainSlot()、~MainSlot()
--------------------------------------------------------------*/

// 主槽类构造方法
MainSlot::MainSlot(QObject* parent) : QObject(parent)
{
    // pass
}

// 主槽类析构方法
MainSlot::~MainSlot()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()、eSelectRedColor()、eSelectGreenColor()、
eSelectBlueColor()
--------------------------------------------------------------*/

// 槽注册方法
void MainSlot::eSlotFuncRegister()
{
    QObject::connect(ui->radioButton_4, SIGNAL(clicked(bool)),  // 连接红色单选框按钮槽
                     this, SLOT(eSelectRedColor(bool)));
    QObject::connect(ui->radioButton, SIGNAL(clicked(bool)),    // 连接蓝色单选框按钮槽
                     this, SLOT(eSelectBlueColor(bool)));
    QObject::connect(ui->radioButton_3, SIGNAL(clicked(bool)),  // 连接绿色单选框按钮槽
                     this, SLOT(eSelectGreenColor(bool)));
}

// 红色单选框选中事件函数
void MainSlot::eSelectRedColor(bool checked)
{
    if (checked)
    {
        ui->textEdit->setText(ui->radioButton_4->text());
    }
}

// 绿色单选框选中事件函数
void MainSlot::eSelectGreenColor(bool checked)
{

    if (checked)
    {
        ui->textEdit->setText(ui->radioButton_3->text());
    }
}

// 蓝色单选框选中事件函数
void MainSlot::eSelectBlueColor(bool checked)
{
    if (checked)
    {
        ui->textEdit->setText(ui->radioButton->text());
    }
}
