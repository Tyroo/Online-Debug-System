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


/*------------------------------------------------------------
@作用：主槽类自定义方法
@包含：eSlotFuncRegister()
--------------------------------------------------------------*/

// 槽注册方法
void LeftMenuCtrl::eSlotFuncRegister()
{
    qint8 firstLevelNodeSize = this->data->nodeMenuList.front().size();;

    connect(this->ui->pushButton, SIGNAL(clicked()), this,
            SLOT(eLeftMenuPageSwitch()));

    while (firstLevelNodeSize)
    {
        QObject::connect(this->LeftMenuItemList[firstLevelNodeSize - 1], SIGNAL(clicked()),
                this, SLOT(eLeftMenuItemClicked()));
        firstLevelNodeSize --;
    }

}


void LeftMenuCtrl::eLeftMenuPageSwitch()
{
    qint8 index = this->ui->stackedWidget->currentIndex();

    index = (index + 1) % 2;

    this->ui->stackedWidget->setCurrentIndex(index);
}

// 菜单项单击响应事件
void LeftMenuCtrl::eLeftMenuItemClicked()
{
    LeftMenuContainerAttribute containerAttr;
    qint8 cl, cs, mni, mci, itemLengthOld, itemLengthNew, childNodeSize, containerSize;
    QPushButton* item = qobject_cast<QPushButton*>(sender());
    QVariant containerLevel = item->property("menuNodeLevel");
    QVariant menuNodeIndex = item->property("menuNodeIndex");
    QVariant menuContainerIndex  = item->property("menuContainerIndex");

    cl = containerLevel.toInt();
    mni = menuNodeIndex.toInt();
    containerSize = this->LeftMenuContainerList.size();
    childNodeSize = this->data->nodeMenuList[cl][mni].childNodeIndexList.size();

    // 隐藏同级容器及其子容器
    for (char i=0; i<containerSize; i++)
    {
        cs = LeftMenuContainerList[i]->property("containerLevel").toInt();
        if (cs > cl) { LeftMenuContainerList[i]->hide(); }
    }

    // 如果该节点无子节点，则不再往下执行
    if (!childNodeSize) return;

    // 如果该节点已经生成过容器，则不再重新生成，直接显示
    if (menuContainerIndex.isValid())
    {
        mci = menuContainerIndex.toInt();
        this->LeftMenuContainerList[mci]->show();
        return;
    }

    /* 如果该节点未生成过子节点容器则生成，并绑定子节点的点击事件 */
    item->setProperty("menuContainerIndex", containerSize);

    containerAttr.containerLevel = cl + 1;
    containerAttr.parentItemIndex = mni;
    containerAttr.parentItemListSize = childNodeSize;
    // 获取当前要生成的子节点容器的纵坐标（纵坐标 =父节点的相对纵坐标 + 父容器的纵坐标）
    containerAttr.containerOrdinate = item->y() + item->parent()->property("y").toInt();

    itemLengthOld = this->LeftMenuItemList.size();
    LeftMenuView::fLoadLeftMenuContainer(containerAttr);
    itemLengthNew = this->LeftMenuItemList.size();

    // 绑定子节点的点击事件
    while (itemLengthOld < itemLengthNew)
    {
        QObject::connect(this->LeftMenuItemList[itemLengthOld], SIGNAL(clicked()),
                this, SLOT(eLeftMenuItemClicked()));
        itemLengthOld ++;
    }

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
