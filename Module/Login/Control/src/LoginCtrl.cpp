#include "./Module/Login/Control/inc/LoginCtrl.h"

/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：LoginCtrl()、~LoginCtrl()
--------------------------------------------------------------*/

// 主槽类构造方法

LoginCtrl::LoginCtrl()
{
    this->eSlotFuncRegister();
}

// 主槽类析构方法
LoginCtrl::~LoginCtrl()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/

// 槽注册方法
void LoginCtrl::eSlotFuncRegister()
{
    QObject::connect(this->ui->pushButton, SIGNAL(clicked()),  // 点击登录按钮事件
                     this, SLOT(eSubmitUserLoginInfo()));
    QObject::connect(this->ui->pushButton_3, SIGNAL(clicked()),  // 点击登录按钮事件
                     this, SLOT(eLoginGotoSignPage()));
    QObject::connect(this->ui->pushButton_5, SIGNAL(clicked()),  // 点击返回登录按钮事件
                     this, SLOT(eSignGotoLoginPage()));
    QObject::connect(this->ui->pushButton_6, SIGNAL(clicked()),  // 点击确认注册按钮事件
                     this, SLOT(eSubmitUserSignInfo()));
    QObject::connect(this->ui->pushButton_7, SIGNAL(clicked()),  // 点击获取验证码按钮事件
                     this, SLOT(eSignSendEmailInfo()));
}

// 登录按钮点击事件回调函数（发送异步登录请求）
void LoginCtrl::eSubmitUserLoginInfo()
{
    QPushButton* push_button = qobject_cast<QPushButton*>(sender());

    this->ui->label_6->setText("");
    this->data->login_username = this->ui->lineEdit->text();
    this->data->login_password = this->ui->lineEdit_2->text();

    if (this->data->login_username.isEmpty() ||
        this->data->login_password.isEmpty())
    {
        this->ui->label_6->setText("请填写账号或密码");
        return;
    }

    push_button->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);

    this->data->mRequestLoginInterface();

    // 连接槽
    QObject::connect(this->data->httpx->respone, SIGNAL(finished()),
            this, SLOT(eSubmitUserLoginInfoRespone()));

    push_button->setText("登录中...");
}

// 登录请求响应成功回调函数
void LoginCtrl::eSubmitUserLoginInfoRespone()
{
    qint32 id;
    QString msg;
    HttpxRequest* httpx = this->data->httpx;
    QJsonObject data = httpx->toJsonRespone(httpx->respone);

    // 解除槽连接
    QObject::disconnect(this->data->httpx->respone, SIGNAL(finished()),
            this, SLOT(eSubmitUserLoginInfoRespone()));

    msg = httpx->getQStrValue(data, "msg");

    this->ui->label_6->setText(msg);
    this->ui->pushButton->setText("登录");
    this->ui->pushButton->setDisabled(false);
    this->ui->pushButton_2->setDisabled(false);

    // 登录完成关闭登录窗口
    if (msg == "SUCCESS")
    {
        id = httpx->getNumValue(data, "info>user>id");
        this->close();
        emit (this->sLoginFinish(id, this));    // 发送信号给主界面
    }
}

// 确认注册按钮点击事件回调函数（发送异步注册请求）
void LoginCtrl::eSubmitUserSignInfo()
{
    this->data->sign_username = this->ui->lineEdit_3->text();
    this->data->sign_password = this->ui->lineEdit_4->text();
    this->data->sign_enterpwd = this->ui->lineEdit_5->text();
    this->data->sign_emailnum = this->ui->lineEdit_6->text();
    this->data->sign_authcode = this->ui->lineEdit_7->text();

    if (this->data->sign_username.isEmpty() ||
        this->data->sign_password.isEmpty() ||
        this->data->sign_enterpwd.isEmpty() ||
        this->data->sign_emailnum.isEmpty() ||
        this->data->sign_authcode.isEmpty())
    {
        this->ui->label_7->setText("请填写对应空缺项");
        return;
    }

    if (this->data->sign_password != this->data->sign_enterpwd)
    {
        this->ui->label_7->setText("两次输入密码不一致");
        return;
    }

    QPushButton* push_button = qobject_cast<QPushButton*>(sender());

    this->data->mRequestSignInterface();

    QObject::connect(this->data->httpx->respone, SIGNAL(finished()),
            this, SLOT(eSubmitUserSignInfoRespone()));

    push_button->setDisabled(true);                 // 禁用确认注册按钮
    this->ui->pushButton_2->setDisabled(true);      // 禁用关闭按钮
    push_button->setText("注册中...");
    this->ui->label_7->setText("");
}

// 确认注册响应成功回调函数
void LoginCtrl::eSubmitUserSignInfoRespone()
{
    qint32 id;
    QString msg;
    HttpxRequest* httpx = this->data->httpx;
    QJsonObject data = httpx->toJsonRespone(httpx->respone);

    // 解除槽连接
    QObject::disconnect(this->data->httpx->respone, SIGNAL(finished()),
            this, SLOT(eSubmitUserSignInfoRespone()));

    msg = httpx->getQStrValue(data, "msg");

    this->ui->pushButton_6->setText("确认注册");
    this->ui->pushButton_6->setDisabled(false);      // 禁用确认注册按钮
    this->ui->pushButton_2->setDisabled(false);      // 禁用关闭按钮
    this->ui->label_7->setText(msg);

    // 登录完成关闭登录窗口
    if (msg == "注册成功")
    {
        id = httpx->getNumValue(data, "info>user>id");
        this->close();
        // pass
    }
}

// 注册验证码请求按钮回调函数
void LoginCtrl::eSignSendEmailInfo()
{
    QString emailnum = this->ui->lineEdit_6->text();

    if (emailnum.isEmpty())
    {
        this->ui->label_7->setText("请填写正确的邮箱");
        return;
    }

    this->ui->label_7->setText("功能暂未开通，敬请期待！");
}

// 点击注册按钮，开启动画滚动至注册页面
void LoginCtrl::eLoginGotoSignPage()
{
    this->ui->label_6->setText("");
    LoginView::fLoginSwitchSignAnimation(QPoint(0, 140), QPoint(440, 140),
        QPoint(-440, 140), QPoint(0, 140));
}

// 点击返回登录按钮，开启动画滚动至登录页面
void LoginCtrl::eSignGotoLoginPage()
{
    this->ui->label_7->setText("");
    LoginView::fLoginSwitchSignAnimation(QPoint(440, 140), QPoint(0, 140),
        QPoint(0, 140), QPoint(-440, 140));
}


#ifdef LoginView_ENABLE_DEBUGGER

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Online-Debug-System_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    LoginCtrl w;
    w.show();
    return a.exec();
}

#endif
