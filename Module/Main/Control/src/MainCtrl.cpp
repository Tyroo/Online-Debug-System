#include "./Module/Main/Control/inc/MainCtrl.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：MainCtrl()、~MainCtrl()
--------------------------------------------------------------*/

// 主槽类构造方法
MainCtrl::MainCtrl()
{
    // pass
    this->eSlotFuncRegister();
}

// 主槽类析构方法
MainCtrl::~MainCtrl()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/

// 槽注册方法
void MainCtrl::eSlotFuncRegister()
{
    QObject::connect(ui->radioButton_4, SIGNAL(clicked()),  // 连接红色单选框按钮槽
                     this, SLOT(eSelectColor()));
    QObject::connect(ui->radioButton, SIGNAL(clicked()),    // 连接蓝色单选框按钮槽
                     this, SLOT(eSelectColor()));
    QObject::connect(ui->radioButton_3, SIGNAL(clicked()),  // 连接绿色单选框按钮槽
                     this, SLOT(eSelectColor()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()),     // 连接登录按钮槽
                     this, SLOT(eClickUserLogin()));
}

// 颜色选择单选按钮触发事件函数
void MainCtrl::eSelectColor()
{
    QRadioButton* radio_button = qobject_cast<QRadioButton*>(sender());
    QString object_text = radio_button->text();

    ui->textEdit->setText(object_text);
}

// 登录按钮点击事件
void MainCtrl::eClickUserLogin()
{
    this->login_ctrl = new LoginCtrl; // 新建Login控制对象
    // 连接登录页发送过来的登陆完成信号到eLoginFinish槽
    QObject::connect(this->login_ctrl, SIGNAL(sLoginFinish(qint32, LoginCtrl*)),
                     this, SLOT(eLoginFinish(qint32, LoginCtrl*)));
    this->login_ctrl->show();
}

// 登陆完成信号主界面响应槽函数
void MainCtrl::eLoginFinish(qint32 id,  LoginCtrl* login_ctrl)
{
    ui->textEdit->setText(QString("登陆成功，ID：") + QString::number(id));
    // 解除登录页发送过来的登陆完成信号到eLoginFinish槽
    QObject::disconnect(this->login_ctrl,
                     SIGNAL(sLoginFinish(qint32, LoginCtrl*)),
                     this,
                     SLOT(eLoginFinish(qint32, LoginCtrl*)));
    login_ctrl->close();
}


#ifdef MainView_ENABLE_DEBUGGER

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
    MainCtrl w;
    w.show();
    return a.exec();
}

#endif
