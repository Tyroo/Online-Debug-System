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
        bool login_status = this->data->
                mRequestLoginInterface(usr, pwd);

        if (login_status)
        {
            QWidget::close();
        }
        else
        {
            this->ui->label_6->setText("账号或密码错误");
        }

        push_button->setDisabled(false);

        return true;
    };

    this->result = std::async(std::launch::async, login_handler, username, password);

    push_button->setDisabled(true);
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
