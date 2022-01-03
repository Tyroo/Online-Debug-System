#include "./Module/LeftMenu/View/inc/LeftMenuView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LeftMenuView()、~LeftMenuView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LeftMenuView::LeftMenuView(QWidget *parent) : QWidget(parent)
{
    data = new LeftMenuData;                       // 新建槽对象
    ui = new Ui::LeftMenuView;                     // 新建主视图对象

    this->fAddStyleAndUi(LEFTMENU_QSS_FILEPATH);   // 添加样式文件和UI文件

    this->fSetItemStyle();
}

// 主视图类析构方法，销毁主视图对象
LeftMenuView::~LeftMenuView()
{
    delete (this->ui);
    delete (this->data);
}

/*------------------------------------------------------------
@作用：主视图类自定义方法
@包含：fAddStyleAndUi()
--------------------------------------------------------------*/

// 主视图类加载Qss样式文件和控件UI方法
void LeftMenuView::fAddStyleAndUi(char* qssPath)
{
    /* UI渲染 */
    this->ui->setupUi(this);

    /* 加载Qss样式表 */
    QFile file(qssPath);            // 引入自定义的QSS文件，在资源目录下
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());  // 设置QSS样式
}

// 设置TreeWidget的子项目的样式
void LeftMenuView::fSetItemStyle()
{

   this->ui->treeWidget->header()->hide();
}
