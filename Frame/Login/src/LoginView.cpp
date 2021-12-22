#include <QFile>

#include "./Frame/Login/inc/LoginView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LoginView()、~LoginView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LoginView::LoginView(QWidget *parent) : QDialog(parent)
{
    slot = new LoginSlot;                       // 新建槽对象

    this->fAddStyleAndUi(LOGIN_QSS_FILEPATH);   // 添加样式文件和UI文件
    this->fSetLoginLabelStyle();
    this->fSetLoginCodeImage();
    slot->eSlotFuncRegister();                 // 事件注册
}

// 主视图类析构方法，销毁主视图对象
LoginView::~LoginView()
{
    delete (this->slot);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void LoginView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    slot->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}

// 设置登录框Login Label控件样式
void LoginView::fSetLoginLabelStyle()
{
    QPalette palette;

    palette.setColor(QPalette::WindowText, QColor(255,255,255));
    palette.setColor(QPalette::Window, QColor(28,134,238));
    slot->ui->label->setAutoFillBackground(true);
    slot->ui->label->setPalette(palette);
}


// 设置登录页二维码框样式
void LoginView::fSetLoginCodeImage()
{
    QString login_code_img = ":/IMG/Login/login_code.jpg";
    int width = 160;//最大宽度
    int height = 160;//最大高度
    slot->ui->label_2->setPixmap(QPixmap::fromImage(QImage(login_code_img).scaled(width,height,Qt::KeepAspectRatio)));
    slot->ui->label_2->setStyleSheet("border: 2px solid rgb(28,134,238)");
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
    LoginView w;
    w.show();
    return a.exec();
}

#endif
