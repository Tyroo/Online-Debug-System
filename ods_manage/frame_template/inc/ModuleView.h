#ifndef {$UPPER_MODULE_NAME}VIEW_H
#define {$UPPER_MODULE_NAME}VIEW_H

#include <QDialog>

#include "./Event/{$LOWER_MODULE_NAME}/inc/{$LOWER_MODULE_NAME}Slot.h"

/* #define {$LOWER_MODULE_NAME}View_ENABLE_DEBUGGER */
#define {$UPPER_MODULE_NAME}_QSS_FILEPATH   ((char*)":/QSS/{$LOWER_MODULE_NAME}/{$LOWER_MODULE_NAME}View.qss")   // QSS文件路径


class {$LOWER_MODULE_NAME}View : public QDialog
{
    Q_OBJECT

public:

    /*
    * @说明：主视图类构造函数
    * @参数：parent，父Qwidget对象，主视图默认为NULL
    * @返回值：无
    */
    {$LOWER_MODULE_NAME}View(QWidget *parent = nullptr);

    /*
    * @说明：主视图类析构函数
    * @参数：无
    * @返回值：无
    */
    ~{$LOWER_MODULE_NAME}View();

private:

    {$LOWER_MODULE_NAME}Slot* slot; // 声明一个槽对象

    /*
    * @说明：加载控件UI和QSS样式
    * @参数：qssPath，自定义样式表文件的路径（.qss）
    * @返回值：无
    */
    void fAddStyleAndUi(char qssPath[]);

};

#endif // LoginView_H
