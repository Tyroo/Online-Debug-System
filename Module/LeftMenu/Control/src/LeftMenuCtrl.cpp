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
    qint8 cl, mni, mci, itemLengthOld, itemLengthNew, childNodeSize;
    QPushButton* item = qobject_cast<QPushButton*>(sender());
    QVariant containerLevel = item->property("menuNodeLevel");
    QVariant menuNodeIndex = item->property("menuNodeIndex");
    QVariant menuContainerIndex  = item->property("menuContainerIndex");

    cl = containerLevel.toInt();
    mni = menuNodeIndex.toInt();
    mci = menuContainerIndex.toInt();
    childNodeSize = this->data->nodeMenuList[cl][mni].childNodeIndexList.size();

    if (!childNodeSize) return;

    if (menuContainerIndex.isValid())
    {
        /*
        在此处隐藏同级菜单容器及其子容器，pass
        */

        this->LeftMenuContainerList[mci]->show();
        return;
    }

    item->setProperty("menuContainerIndex", this->LeftMenuContainerList.size());

    containerAttr.containerLevel = cl + 1;
    containerAttr.parentItemIndex = mni;
    containerAttr.parentItemListSize = childNodeSize;

    itemLengthOld = this->LeftMenuItemList.size();
    LeftMenuView::fLoadLeftMenuContainer(containerAttr);
    itemLengthNew = this->LeftMenuItemList.size();

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
