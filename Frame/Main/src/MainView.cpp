#include <QFile>

#include "./Frame/Main/inc/MainView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：MainView()、~MainView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
MainView::MainView(QWidget *parent) : QMainWindow(parent)
{
    slot = new MainSlot;                       // 新建槽对象

    this->fAddStyleAndUi(MAIN_QSS_FILEPATH);   // 添加样式文件和UI文件
    slot->eSlotFuncRegister();                 // 事件注册
}

// 主视图类析构方法，销毁主视图对象
MainView::~MainView()
{
    delete (this->slot);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void MainView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    slot->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
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
    MainView w;
    w.show();
    return a.exec();
}

#endif
