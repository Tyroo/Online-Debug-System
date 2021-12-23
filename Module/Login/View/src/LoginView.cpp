#include "./Module/Login/View/inc/LoginView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LoginView()、~LoginView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LoginView::LoginView(QWidget *parent) : QWidget(parent)
{
    data = new LoginData;                       // 新建槽对象
    ui = new Ui::LoginView;                     // 新建主视图对象

    this->fAddStyleAndUi(LOGIN_QSS_FILEPATH);   // 添加样式文件和UI文件

    this->fSetLoginLabelStyle();
    this->fSetLoginCodeImage();
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

// 主视图类析构方法，销毁主视图对象
LoginView::~LoginView()
{
    delete (this->ui);
    delete (this->data);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void LoginView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    this->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}

// 设置登录框Login Label控件样式
void LoginView::fSetLoginLabelStyle()
{
}


// 设置登录页二维码框样式
void LoginView::fSetLoginCodeImage()
{
//    QString login_code_img = ":/IMG/Login/login_code.jpg";
//    int width = 100;//最大宽度
//    int height = 100;//最大高度
//    slot->ui->label_2->setPixmap(QPixmap::fromImage(QImage(login_code_img).scaled(width,height,Qt::KeepAspectRatio)));
}
