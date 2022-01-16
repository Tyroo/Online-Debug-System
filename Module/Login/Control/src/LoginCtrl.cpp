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
    QObject::connect(this->ui->pushButton_5, SIGNAL(clicked()),  // 点击注册按钮事件
                     this, SLOT(eSignGotoLoginPage()));
    QObject::connect(this->ui->pushButton_6, SIGNAL(clicked()),  // 点击确认注册按钮事件
                     this, SLOT(eSubmitUserSignInfo()));
    QObject::connect(this->ui->pushButton_7, SIGNAL(clicked()),  // 点击获取验证码按钮事件
                     this, SLOT(eSignSendEmailInfo()));

}

// 登录按钮点击事件回调函数（发送异步登录请求）
void LoginCtrl::eSubmitUserLoginInfo()
{
    QString username;
    QString password;
    QPushButton* push_button = qobject_cast<QPushButton*>(sender());

    username = this->ui->lineEdit->text();
    password = this->ui->lineEdit_2->text();

    push_button->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);

    this->data->mRequestLoginInterface(username, password);

    QObject::connect(this->data->httpx->respone, SIGNAL(finished()),
            this, SLOT(eSubmitUserLoginInfoRespone()));

    push_button->setText("登录中...");
    this->ui->label_6->setText("");
}

// 登录请求响应成功回调函数
void LoginCtrl::eSubmitUserLoginInfoRespone()
{
    qint32 id;
    QString msg;
    HttpxRequest* httpx = this->data->httpx;

    QJsonObject jd = httpx->toJsonRespone(httpx->respone);

    msg = httpx->getQStrValue(jd, "msg");

    this->ui->label_6->setText(msg);
    this->ui->pushButton->setDisabled(false);
    this->ui->pushButton_2->setDisabled(false);

    // 登录完成关闭登录窗口
    if (msg == "SUCCESS")
    {
        id = httpx->getNumValue(jd, "info>user>id");
        this->close();
    }
}

// 确认注册按钮点击事件回调函数（发送异步注册请求）
void LoginCtrl::eSubmitUserSignInfo()
{
    QString username;
    QString password;
    QString enterpwd;
    QString emailnum;
    QString authcode;

    username = this->ui->lineEdit_3->text();
    password = this->ui->lineEdit_4->text();
    enterpwd = this->ui->lineEdit_5->text();
    emailnum = this->ui->lineEdit_6->text();
    authcode = this->ui->lineEdit_7->text();

    if (username.isEmpty() || password.isEmpty() || enterpwd.isEmpty() ||
        emailnum.isEmpty() || authcode.isEmpty())
    {
        this->ui->label_7->setText("请填写对应空缺项");
        return;
    }

    if (password != enterpwd)
    {
        this->ui->label_7->setText("两次输入密码不一致");
        return;
    }

    QPushButton* push_button = qobject_cast<QPushButton*>(sender());

    this->data->mRequestSignInterface(username, password, enterpwd, emailnum, authcode);

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
    QJsonObject jd = httpx->toJsonRespone(httpx->respone);

    msg = httpx->getQStrValue(jd, "msg");

    // 登录完成关闭登录窗口
    if (msg == "注册成功")
    {
        id = httpx->getNumValue(jd, "info>user>id");
        this->close();
    }

    this->ui->pushButton_6->setDisabled(false);      // 禁用确认注册按钮
    this->ui->pushButton_2->setDisabled(false);      // 禁用关闭按钮
    this->ui->label_7->setText(msg);
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
    LoginView::fLoginSwitchSignAnimation(QPoint(0, 140), QPoint(440, 140),
        QPoint(-440, 140), QPoint(0, 140));
}

// 点击返回登录按钮，开启动画滚动至登录页面
void LoginCtrl::eSignGotoLoginPage()
{
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
