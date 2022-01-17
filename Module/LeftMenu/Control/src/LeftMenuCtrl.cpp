#include "./Module/LeftMenu/Control/inc/LeftMenuCtrl.h"


/*------------------------------------------------------------
@作用：主槽类默认方法
@包含：LeftMenuCtrl()、~LeftMenuCtrl()
--------------------------------------------------------------*/

// 主槽类构造方法
LeftMenuCtrl::LeftMenuCtrl()
{
    this->eSlotFuncRegister();
}

// 主槽类析构方法
LeftMenuCtrl::~LeftMenuCtrl()
{
    // pass
}

/*

struct LeftMenu
{
    currentExpandContainerObject:  // 当前被选中的容器的指针
    currentSelectNodeObject:       // 当前被选中的节点的指针
    nodeList:                      // 总节点列表
}

struct LeftMenuNode
{
    nodeIconPath:       // 节点图标地址
    nodeIndex:          // 当前节点索引（0~N）
    nodeLevel:          // 当前节点级别（0~N）
    parentNodeIndex:    // 父节点索引（0~N）
    childNodeNumber:    // 子节点的个数（0~N）
    nodeStatus:         // 节点状态（禁用~启用）
    childNodefirstIndex: // 第一个子节点在该级节点的索引号（0~N），用于快速查找
}

struct LeftMenuContainer
{
    containerIconPath:// 容器图标路径
    containerLevel:   // 当前容器级别（0~N）
    containerStatus:  // 容器状态
}

节点位置 =

*/

/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/

// 槽注册方法
void LeftMenuCtrl::eSlotFuncRegister()
{
    connect(this->ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this,
            SLOT(eTreeItemCilckExpand(QTreeWidgetItem*, int)));

    connect(this->ui->pushButton, SIGNAL(clicked()), this,
            SLOT(eLeftMenuPageSwitch()));
}

// Tree单击展开事件
void LeftMenuCtrl::eTreeItemCilckExpand(QTreeWidgetItem* item, int arg)
{
    item->setExpanded(!item->isExpanded());
}

void LeftMenuCtrl::eLeftMenuPageSwitch()
{
    qint8 index = this->ui->stackedWidget->currentIndex();

    index = (index + 1) % 2;

    this->ui->stackedWidget->setCurrentIndex(index);
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
