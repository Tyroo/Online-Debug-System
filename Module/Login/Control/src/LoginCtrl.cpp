#include "./Module/Login/Control/inc/LoginCtrl.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：LoginCtrl()、~LoginCtrl()
--------------------------------------------------------------*/

// 主槽类构造方法
LoginCtrl::LoginCtrl()
{
    // pass
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
                     this, SLOT(eSignSendEmailRequest()));

}

// 登录按钮点击事件回调函数（发送异步登录请求）
void LoginCtrl::eSubmitUserLoginInfo()
{
    QString username;
    QString password;
    QPushButton* push_button = qobject_cast<QPushButton*>(sender());

    username = this->ui->lineEdit->text();
    password = this->ui->lineEdit_2->text();

    auto login_handler = [this, push_button](QString usr, QString pwd) -> bool
    {
        unsigned long count = 0;
        bool login_status = this->data->
            mRequestLoginInterface(usr, pwd);

        if (login_status)
        {
            push_button->setText("登录成功");
            push_button->setStyleSheet("color:rgb(220,0,20)");
            while((count++)<pow(10,8));
            this->close();
        }
        else
        {
            this->ui->label_6->setText("账号或密码错误");
            push_button->setText("登录");
        }

        push_button->setDisabled(false);
        this->ui->pushButton_2->setDisabled(false);

        return true;
    };

    this->result = std::async(std::launch::async, login_handler, username, password);

    push_button->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);
    push_button->setText("登录中...");
    this->ui->label_6->setText("");
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

    if (username.isEmpty() || password.isEmpty() ||
        enterpwd.isEmpty() || emailnum.isEmpty() ||
        authcode.isEmpty())
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

    username = this->ui->lineEdit->text();
    password = this->ui->lineEdit_2->text();

    auto sign_handler = [this, push_button](QString usr, QString pwd,
            QString enpwd, QString email, QString authcode) -> bool
    {
        unsigned long count = 0;
        bool sign_status = this->data->
            mRequestSignInterface(usr, pwd, enpwd, email, authcode);

        if (sign_status)
        {
            push_button->setText("注册成功");
            while((count++)<pow(10,8));
            this->close();
        }
        else
        {
            this->ui->label_7->setText("验证码错误");
            push_button->setText("确认注册");
        }

        push_button->setDisabled(false);
        this->ui->pushButton_2->setDisabled(false); // 使能关闭按钮

        return true;
    };

    this->result = std::async(std::launch::async, sign_handler, username,
                              password, enterpwd, emailnum, authcode);

    push_button->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);      // 禁用关闭按钮
    push_button->setText("登录中...");
    this->ui->label_7->setText("");
}

// 注册验证码请求按钮回调函数
void LoginCtrl::eSignSendEmailRequest()
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
