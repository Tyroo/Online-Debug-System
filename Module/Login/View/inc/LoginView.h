#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QFile>
#include <QWidget>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

#include "ui_LoginView.h"
#include "./Module/Login/Data/inc/LoginData.h"

#define LOGIN_QSS_FILEPATH   ((char*)":/QSS/Login/LoginView.qss")   // QSS文件路径


class LoginView : public QWidget
{
    Q_OBJECT

public:

    LoginData* data;
    Ui::LoginView* ui;

    /*
    * @说明：主视图类构造函数
    * @参数：parent，父Qwidget对象，主视图默认为NULL
    * @返回值：无
    */
    LoginView(QWidget *parent = nullptr);

    /*
    * @说明：主视图类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LoginView();

    /*
    * @说明：登录页到注册页的切换动画
    * @参数：无
    * @返回值：无
    */
    void fLoginGotoSignPageAnimation(void);

    /*
    * @说明：注册页到登录页的切换动画
    * @参数：无
    * @返回值：无
    */
    void fLoginSwitchSignAnimation(QPoint ls, QPoint le, QPoint ss, QPoint se);

private:

    /*
    * @说明：加载控件UI和QSS样式
    * @参数：qssPath，自定义样式表文件的路径（.qss）
    * @返回值：无
    */
    void fAddStyleAndUi(char qssPath[]);

    /*
    * @说明：设置窗口样式
    * @参数：无
    * @返回值：无
    */
    void fSetLoginWindowStyle(void);

    /*
    * @说明：设置显示有‘Login’的label控件的样式
    * @参数：qssPath，自定义样式表文件的路径（.qss）
    * @返回值：无
    */
    void fSetLoginLabelStyle(void);

};
#endif // LOGINVIEW_H
