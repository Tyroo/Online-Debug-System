#include "./Module/{$LOWER_MODULE_NAME}/Control/inc/{$LOWER_MODULE_NAME}Ctrl.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：{$LOWER_MODULE_NAME}Ctrl()、~{$LOWER_MODULE_NAME}Ctrl()
--------------------------------------------------------------*/

// 主槽类构造方法
{$LOWER_MODULE_NAME}Ctrl::{$LOWER_MODULE_NAME}Ctrl()
{
    // pass
    this->eSlotFuncRegister();
}

// 主槽类析构方法
{$LOWER_MODULE_NAME}Ctrl::~{$LOWER_MODULE_NAME}Ctrl()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/

// 槽注册方法
void {$LOWER_MODULE_NAME}Ctrl::eSlotFuncRegister()
{

}


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
    {$LOWER_MODULE_NAME}Ctrl w;
    w.show();
    return a.exec();
}

#endif
