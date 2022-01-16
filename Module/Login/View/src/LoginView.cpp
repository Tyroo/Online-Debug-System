#include "./Module/Login/View/inc/LoginView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LoginView()、~LoginView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LoginView::LoginView(QWidget *parent) : QWidget(parent)
{
    data = new LoginData(this);                       // 新建槽对象
    ui = new Ui::LoginView;                     // 新建主视图对象

    this->fAddStyleAndUi(LOGIN_QSS_FILEPATH);   // 添加样式文件和UI文件
    this->setAttribute(Qt::WA_DeleteOnClose, true); // 关闭窗体后销毁窗体对象

    this->fSetLoginWindowStyle();
    this->fSetLoginLabelStyle();
    this->fSetLoginLabelStyle();
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

// 设置登录窗口样式
void LoginView::fSetLoginWindowStyle()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_ShowModal);
}

// 设置登录框Login Label控件样式
void LoginView::fSetLoginLabelStyle()
{
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(2, 2);
    shadow->setColor(QColor(120, 120, 120));
    shadow->setBlurRadius(10);

    ui->label_2->setGraphicsEffect(shadow);
}


// 登录页与注册页之间的切换动画
void LoginView::fLoginSwitchSignAnimation(
        QPoint ls, QPoint le, QPoint ss, QPoint se)
{
    QPropertyAnimation* login_animation = new QPropertyAnimation(
                this->ui->frame_2, "pos");
    QPropertyAnimation* sign_animation = new QPropertyAnimation(
                this->ui->frame_3, "pos");

    login_animation->setDuration(600);
    sign_animation->setDuration(600);

    login_animation->setStartValue(ls);
    login_animation->setEndValue(le);

    sign_animation->setStartValue(ss);
    sign_animation->setEndValue(se);

    login_animation->start();
    sign_animation->start();
}
