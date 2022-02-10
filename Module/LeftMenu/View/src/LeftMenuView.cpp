#include "./Module/LeftMenu/View/inc/LeftMenuView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LeftMenuView()、~LeftMenuView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LeftMenuView::LeftMenuView(QWidget *parent) : QWidget(parent)
{
    LeftMenuContainerAttribute containerAttr;

    data = new LeftMenuData;                       // 新建槽对象
    ui = new Ui::LeftMenuView;                     // 新建主视图对象

    containerAttr.containerLevel = 0;
    containerAttr.parentItemIndex = -1;
    containerAttr.containerOrdinate = 0;
    containerAttr.parentItemListSize = this->data->nodeMenuList.front().size();

    this->fAddStyleAndUi(LEFTMENU_QSS_FILEPATH);   // 添加样式文件和UI文件

    this->setAttribute(Qt::WA_DeleteOnClose, true); // 关闭窗体后销毁窗体对象
    this->fLoadLeftMenuContainer(containerAttr);
}

// 主视图类析构方法，销毁主视图对象
LeftMenuView::~LeftMenuView()
{ 
    delete (this->ui);
    delete (this->data);
    this->fUnLoadLeftMenuContainer();
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

// 加载菜单容器
void LeftMenuView::fLoadLeftMenuContainer(LeftMenuContainerAttribute& containerAttr)
{
    qint16 cco;
    qint8 i, ccl, cpii, cpils;
    LeftMenuNodeType menuNode;

    ccl = containerAttr.containerLevel;
    cco = containerAttr.containerOrdinate;
    cpii = containerAttr.parentItemIndex;
    cpils = containerAttr.parentItemListSize;

    QWidget* container = new QWidget(this->ui->widget);
    container->setGeometry(ccl*100, cco, 100, 30*cpils);
    container->setStyleSheet("background:rgba(50,50,50,0.5)");
    container->setProperty("containerLevel", ccl);

    for (i=0; i<cpils; i++)
    {
        QPushButton* item = new QPushButton(container);

        item->setGeometry(0, 30*i , 100, 30);

        if (ccl)
        {
            menuNode = this->data->nodeMenuList[ccl]
                    [this->data->nodeMenuList[ccl-1][cpii]
                    .childNodeIndexList[i]];
        }
        else
        {
            menuNode = this->data->nodeMenuList[ccl][i];
        }

        item->setText(menuNode.nodeName);
        item->setProperty("menuNodeLevel", ccl);
        item->setProperty("menuNodeIndex", menuNode.nodeIndex);
        item->show();
        LeftMenuItemList.push_back(item);
    }

    container->show();
    this->LeftMenuContainerList.push_back(container);

}

// 设置TreeWidget的子项目的样式
void LeftMenuView::fUnLoadLeftMenuContainer()
{
    quint8 containerSize, itemSize, i;

    containerSize = LeftMenuContainerList.size();
    itemSize = LeftMenuItemList.size();

    for (i=0; i<itemSize; i++)
    {
        if (LeftMenuItemList[i] != nullptr)
        {
            delete LeftMenuItemList[i];
            LeftMenuItemList[i] = nullptr;
        }
    }

    for (i=0; i<containerSize; i++)
    {
        if (LeftMenuContainerList[i] != nullptr)
        {
            delete LeftMenuContainerList[i];
            LeftMenuContainerList[i] = nullptr;
        }
    }

    LeftMenuItemList.clear();
    LeftMenuContainerList.clear();
}
