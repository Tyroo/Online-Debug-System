#include "./Module/LeftMenu/View/inc/LeftMenuView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LeftMenuView()、~LeftMenuView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LeftMenuView::LeftMenuView(QWidget *parent) : QWidget(parent)
{
    LeftMenuContainerAttribute containerAttr;

    containerAttr.containerIndex = -1;
    containerAttr.parentItemIndex = -1;
    containerAttr.itemLength = 5;

    data = new LeftMenuData;                       // 新建槽对象
    ui = new Ui::LeftMenuView;                     // 新建主视图对象

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
    bool isNewItem = false;

    if (containerAttr.containerIndex < 0)
    {
        isNewItem = true;
        QWidget* container = new QWidget(this->ui->widget);

        containerAttr.containerIndex = LeftMenuContainerList.size();

        container->setGeometry(containerAttr.containerIndex*200, 100, 200, 500);
        container->setStyleSheet("background-color:red;");

        LeftMenuContainerList.push_back(container);
    }

    for (quint8 i=0; i<containerAttr.itemLength; i++)
    {
        if (isNewItem)
        {

            QPushButton* item = new QPushButton(LeftMenuContainerList[containerAttr.containerIndex]);

            item->setGeometry(50, 30*(i+1) , 100, 30);

            if (containerAttr.parentItemIndex >= 0)
            {
                item->setText(this->data->nodeMenuList[ \
                              this->data->nodeMenuList[containerAttr.parentItemIndex] \
                        .childNodeIndexList[i]].nodeName);
            }
            else
            {
                item->setText(this->data->nodeMenuList[i].nodeName);
            }

            item->setProperty("menuNodeIndex", i);

            LeftMenuItemList.push_back(item);
        }

        LeftMenuItemList[i]->show();
    }

    LeftMenuContainerList[containerAttr.containerIndex]->show();
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
