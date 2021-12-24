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

// 登录按钮点击事件回调函数
void LoginCtrl::eSubmitUserInfo()
{
    QString& username = data->mGetUsername();
    QString& password = data->mGetPassword();

    if (this->ui->lineEdit->text() != username ||
       this->ui->lineEdit_2->text() != password)
    {
        ui->label_6->setText("账号或密码错误");
    }
    else
    {
        QWidget::close();
    }
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
