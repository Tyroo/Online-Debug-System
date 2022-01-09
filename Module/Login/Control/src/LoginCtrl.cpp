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
                     this, SLOT(eSubmitUserInfo()));
    QObject::connect(this->ui->pushButton_3, SIGNAL(clicked()),  // 点击登录按钮事件
                     this, SLOT(eLoginGotoSignPage()));
    QObject::connect(this->ui->pushButton_5, SIGNAL(clicked()),  // 点击登录按钮事件
                     this, SLOT(eSignGotoLoginPage()));

}

// 登录按钮点击事件回调函数（发送异步登录请求）
void LoginCtrl::eSubmitUserInfo()
{
    QString username;
    QString password;
    QPushButton* push_button = qobject_cast<QPushButton*>(sender());

    username = this->ui->lineEdit->text();
    password = this->ui->lineEdit_2->text();

    auto login_handler = [this, push_button](QString usr, QString pwd) -> bool
    {
        QThread t;
        bool login_status = this->data->
                mRequestLoginInterface(usr, pwd);


        if (login_status)
        {
            push_button->setText("登录成功");
            push_button->setStyleSheet("color:rgb(220,0,20)");
            t.sleep(2);
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


void LoginCtrl::eLoginGotoSignPage()
{
    QPropertyAnimation* login_animation = new QPropertyAnimation(
                this->ui->frame_2, "pos");
    QPropertyAnimation* sign_animation = new QPropertyAnimation(
                this->ui->frame_3, "pos");

    login_animation->setDuration(1000);
    sign_animation->setDuration(1000);

    login_animation->setStartValue(QPoint(0, 140));
    login_animation->setEndValue(QPoint(440, 140));

    sign_animation->setStartValue(QPoint(-440, 140));
    sign_animation->setEndValue(QPoint(0, 140));

    login_animation->setEasingCurve(QEasingCurve::InOutQuad);   // 设置动画曲线
    sign_animation->setEasingCurve(QEasingCurve::InOutQuad);    // 设置动画曲线

    login_animation->start();
    sign_animation->start();
}


void LoginCtrl::eSignGotoLoginPage()
{
    QPropertyAnimation* login_animation = new QPropertyAnimation(
                this->ui->frame_2, "pos");
    QPropertyAnimation* sign_animation = new QPropertyAnimation(
                this->ui->frame_3, "pos");

    login_animation->setDuration(1000);
    sign_animation->setDuration(1000);

    login_animation->setEndValue(QPoint(0, 140));
    login_animation->setStartValue(QPoint(440, 140));

    sign_animation->setEndValue(QPoint(-440, 140));
    sign_animation->setStartValue(QPoint(0, 140));

    login_animation->setEasingCurve(QEasingCurve::InOutQuad);   // 设置动画曲线
    sign_animation->setEasingCurve(QEasingCurve::InOutQuad);    // 设置动画曲线

    login_animation->start();
    sign_animation->start();
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
