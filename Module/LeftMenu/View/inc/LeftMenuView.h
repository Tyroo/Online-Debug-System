#ifndef LEFTMENUVIEW_H
#define LEFTMENUVIEW_H

#include <QFile>
#include <QWidget>

#include "ui_LeftMenuView.h"
#include "./Module/LeftMenu/Data/inc/LeftMenuData.h"

#define LEFTMENU_QSS_FILEPATH   ((char*)":/QSS/LeftMenu/LeftMenuView.qss")   // QSS文件路径


class LeftMenuView : public QWidget
{
    Q_OBJECT

public:

    LeftMenuData* data;
    Ui::LeftMenuView* ui;

    /*
    * @说明：主视图类构造函数
    * @参数：parent，父Qwidget对象，主视图默认为NULL
    * @返回值：无
    */
    LeftMenuView(QWidget *parent = nullptr);

    /*
    * @说明：主视图类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LeftMenuView();

private:

    /*
    * @说明：加载控件UI和QSS样式
    * @参数：qssPath，自定义样式表文件的路径（.qss）
    * @返回值：无
    */
    void fAddStyleAndUi(char qssPath[]);

    /*
    * @说明：设置TreeWidget的子项目的样式
    * @参数：qssPath，自定义样式表文件的路径（.qss）
    * @返回值：无
    */
    void fSetItemStyle(void);

};
#endif // LEFTMENUVIEW_H
