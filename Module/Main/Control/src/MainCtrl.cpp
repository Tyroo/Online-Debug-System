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
    QObject::connect(ui->radioButton_4, SIGNAL(clicked(bool)),  // 连接红色单选框按钮槽
                     this, SLOT(eSelectRedColor(bool)));
    QObject::connect(ui->radioButton, SIGNAL(clicked(bool)),    // 连接蓝色单选框按钮槽
                     this, SLOT(eSelectBlueColor(bool)));
    QObject::connect(ui->radioButton_3, SIGNAL(clicked(bool)),  // 连接绿色单选框按钮槽
                     this, SLOT(eSelectGreenColor(bool)));
    QObject::connect(ui->pushButton, SIGNAL(clicked()),         // 连接登录按钮槽
                     this, SLOT(eClickUserLogin()));
}

// 红色单选框选中事件函数
void MainCtrl::eSelectRedColor(bool checked)
{
    if (checked)
    {
        ui->textEdit->setText(ui->radioButton_4->text());
    }
}

// 绿色单选框选中事件函数
void MainCtrl::eSelectGreenColor(bool checked)
{

    if (checked)
    {
        ui->textEdit->setText(ui->radioButton_3->text());
    }
}

// 蓝色单选框选中事件函数
void MainCtrl::eSelectBlueColor(bool checked)
{
    if (checked)
    {
        ui->textEdit->setText(ui->radioButton->text());
    }
}

// 登录按钮点击事件
void MainCtrl::eClickUserLogin()
{
    this->login_ui->show();
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
