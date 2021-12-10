#include <QFile>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/qglobal.h>

#include "./Frame/Main/inc/MainView.h"



/*------------------------------------------------------------
@：作用：主视图类默认方法
@：包含：MainView()、~MainView()
--------------------------------------------------------------*/

// 主视图构造方法，初始化主视图对象
MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
{
    this->fAddStyleAndUi(MAIN_QSS_FILEPATH);    // 添加样式文件和UI文件
}

// 主视图析构方法，销毁主视图对象
MainView::~MainView()
{
    delete (MainData::ui);
}

/*------------------------------------------------------------
@：作用：主视图自定义方法
@：包含：fAddStyleAndUi()、fAddSelectColorBox()
--------------------------------------------------------------*/

// 主视图加载Qss样式文件和控件UI方法
void MainView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    MainData::ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}
