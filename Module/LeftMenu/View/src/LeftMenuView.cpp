#include "./Module/LeftMenu/View/inc/LeftMenuView.h"


/*------------------------------------------------------------
@作用：主视图类默认方法
@包含：LeftMenuView()、~LeftMenuView()
--------------------------------------------------------------*/

// 主视图类构造方法，初始化主视图对象
LeftMenuView::LeftMenuView(QWidget *parent) : QWidget(parent)
{
    ContainerAttribute containerAttr;

    data = new LeftMenuData;                       // 新建槽对象
    ui = new Ui::LeftMenuView;                     // 新建主视图对象

    containerAttr.containerLevel = 0;
    containerAttr.parentItemIndex = 0;
    containerAttr.containerOrdinate = 0;
    containerAttr.parentItemListSize = this->data->nodeMenuList.front().size();

    this->fAddStyleAndUi(LEFTMENU_QSS_FILEPATH);   // 添加样式文件和UI文件
    this->setAttribute(Qt::WA_DeleteOnClose, true); // 关闭窗体后销毁窗体对象
    this->fCreateLeftMenuContainer(containerAttr, this);
    this->setFocus();
}

// 主视图类析构方法，销毁主视图对象
LeftMenuView::~LeftMenuView()
{ 
    delete (this->ui);
    delete (this->data);
    this->fClearLeftMenuContainer();
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

void LeftMenuView::fSetLeftMenuStyle()
{
    this->setGeometry(200, 600, 0, 0);
//    this->ui->widget->setGeometry(200, 600, 0, 0);
    this->setStyleSheet("background-color:red;");
    this->setFocus();
}

// 加载菜单容器
void LeftMenuView::fCreateLeftMenuContainer(ContainerAttribute& containerAttr, QWidget* parent)
{
    qint16 cco;
    qint8 i, ccl, cpii, cpils, mpni;
    LeftMenuNodeType menuNode;

    ccl = containerAttr.containerLevel;
    cco = containerAttr.containerOrdinate;
    cpii = containerAttr.parentItemIndex;
    cpils = containerAttr.parentItemListSize;

    QWidget* container = new QWidget(parent);
    container->activateWindow();
    container->setGeometry(ccl*100, cco, 100, 30*cpils);
    container->setProperty("containerLevel", ccl);
    container->setProperty("parentItemIndex", cpii);

    if (ccl)
    {
        mpni = LeftMenuItemList[cpii]->property("menuNodeIndex").toInt();
    }

    for (i=0; i<cpils; i++)
    {
        QPushButton* item = new QPushButton(container);

        item->setGeometry(0, 30*i , 100, 30);

        if (ccl)
        {
            menuNode = this->data->nodeMenuList[ccl]
                    [this->data->nodeMenuList[ccl-1][mpni]
                    .childNodeIndexList[i]];
        }
        else
        {
            menuNode = this->data->nodeMenuList[ccl][i];
        }

        item->setText(menuNode.nodeName);
        item->setProperty("menuNodeLevel", ccl);
        item->setProperty("menuNodeIndex", menuNode.nodeIndex);
        item->setProperty("itemIndex", LeftMenuItemList.size());
        LeftMenuItemList.push_back(item);
    }

    this->LeftMenuContainerList.push_back(container);
}

bool LeftMenuView::eventFilter(QObject *watched, QEvent *event)
{
    bool hasEvent;

    switch (event->type())
    {
        case QEvent::MouseButtonPress:
            hasEvent = true;
            break;
//        case QEvent::FocusOut:
//            hasEvent = true;
//            break;
        default:
            hasEvent = false;
    }

    if (hasEvent && watched != this)
    {
        // 隐藏同级容器及其子容器
        fHideLeftMenuContainer(0);
        activecontainerLevel = -1;
    }

    return (QWidget::eventFilter(watched, event));
}


// 设置TreeWidget的子项目的样式
void LeftMenuView::fClearLeftMenuContainer()
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

// 显示子菜单容器
void LeftMenuView::fShowLeftMenuContainer(QWidget* container)
{
    QPropertyAnimation* animation = new QPropertyAnimation(
                    container, "size");
    animation->setDuration(200);

    animation->setStartValue(QSize(0,0));
    animation->setEndValue(container->size());
    container->show();
    animation->start();
}

void LeftMenuView::fHideLeftMenuContainer(qint8 startLevel)
{
    qint8 ContainerLevel, parentIndex, containerSize;

    containerSize = this->LeftMenuContainerList.size();

    for (char i = 0; i<containerSize; i++)
    {
        ContainerLevel = LeftMenuContainerList[i]->property("containerLevel").toInt();

        if (ContainerLevel > startLevel)
        {
            LeftMenuContainerList[i]->hide();
            parentIndex = LeftMenuContainerList[i]->property("parentItemIndex").toInt();
            // 设置节点收起时的样式
            this->LeftMenuItemList[parentIndex]->setStyleSheet("background-color:white");
        }
    }
}
