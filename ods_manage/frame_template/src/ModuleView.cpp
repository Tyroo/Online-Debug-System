#include <QFile>

#include "./Frame/{$LOWER_MODULE_NAME}/inc/{$LOWER_MODULE_NAME}View.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：{$LOWER_MODULE_NAME}View()、~{$LOWER_MODULE_NAME}View()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
{$LOWER_MODULE_NAME}View::{$LOWER_MODULE_NAME}View(QWidget *parent) : QDialog(parent)
{
    slot = new {$LOWER_MODULE_NAME}Slot;                       // 新建槽对象

    this->fAddStyleAndUi({$UPPER_MODULE_NAME}_QSS_FILEPATH);   // 添加样式文件和UI文件
    slot->eSlotFuncRegister();                 // 事件注册
}

// 主视图类析构方法，销毁主视图对象
{$LOWER_MODULE_NAME}View::~{$LOWER_MODULE_NAME}View()
{
    delete (this->slot);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void {$LOWER_MODULE_NAME}View::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    slot->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}


/*------------------------------------------------------------
@作用：主视图类调试main函数
@包含：main()
--------------------------------------------------------------*/

#ifdef {$LOWER_MODULE_NAME}View_ENABLE_DEBUGGER

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
    {$LOWER_MODULE_NAME}View w;
    w.show();
    return a.exec();
}

#endif