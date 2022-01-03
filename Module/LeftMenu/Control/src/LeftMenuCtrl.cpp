#include "./Module/LeftMenu/Control/inc/LeftMenuCtrl.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：LeftMenuCtrl()、~LeftMenuCtrl()
--------------------------------------------------------------*/

// 主槽类构造方法
LeftMenuCtrl::LeftMenuCtrl()
{
    // pass
    this->eSlotFuncRegister();
}

// 主槽类析构方法
LeftMenuCtrl::~LeftMenuCtrl()
{
    // pass
}

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/

// 槽注册方法
void LeftMenuCtrl::eSlotFuncRegister()
{

}


#ifdef LeftMenuView_ENABLE_DEBUGGER

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
    LeftMenuCtrl w;
    w.show();
    return a.exec();
}

#endif
