#include "./Module/{$LOWER_MODULE_NAME}/View/inc/{$LOWER_MODULE_NAME}View.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：{$LOWER_MODULE_NAME}View()、~{$LOWER_MODULE_NAME}View()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
{$LOWER_MODULE_NAME}View::{$LOWER_MODULE_NAME}View(QWidget *parent) : QWidget(parent)
{
    data = new {$LOWER_MODULE_NAME}Data;                       // 新建槽对象
    ui = new Ui::{$LOWER_MODULE_NAME}View;                     // 新建主视图对象

    this->fAddStyleAndUi({$UPPER_MODULE_NAME}_QSS_FILEPATH);   // 添加样式文件和UI文件
}

// 主视图类析构方法，销毁主视图对象
{$LOWER_MODULE_NAME}View::~{$LOWER_MODULE_NAME}View()
{
    delete (this->ui);
    delete (this->data);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void {$LOWER_MODULE_NAME}View::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    this->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}
