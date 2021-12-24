#include "./Module/Main/View/inc/MainView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：MainView()、~MainView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    data = new MainData;                       // 新建主数据对象
    ui = new Ui::MainView;                     // 新建主视图对象

    login_ui = new LoginCtrl;                  // 新建Login控制对象

    this->fAddStyleAndUi(MAIN_QSS_FILEPATH);   // 添加样式文件和UI文件
}

// 主视图类析构方法，销毁主视图对象
MainView::~MainView()
{
    delete (this->ui);
    delete (this->data);
    delete (this->login_ui);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void MainView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    this->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}
