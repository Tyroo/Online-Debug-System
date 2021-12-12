#include <QFile>

#include "./Frame/Login/inc/LoginView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LoginView()、~LoginView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LoginView::LoginView(QWidget *parent) : QDialog(parent)
{
    slot = new LoginSlot;                       // 新建槽对象

    this->fAddStyleAndUi(LOGIN_QSS_FILEPATH);   // 添加样式文件和UI文件
    slot->eSlotFuncRegister();                 // 事件注册
}

// 主视图类析构方法，销毁主视图对象
LoginView::~LoginView()
{
    delete (this->slot);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void LoginView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    slot->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}
