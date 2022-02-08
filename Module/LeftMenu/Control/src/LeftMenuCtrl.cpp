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
    quint8 itemIndex = 0;

    connect(this->ui->pushButton, SIGNAL(clicked()), this,
            SLOT(eLeftMenuPageSwitch()));

    while (itemIndex < 5)
    {
        QObject::connect(this->LeftMenuItemList[itemIndex], SIGNAL(clicked()),
                this, SLOT(eLeftMenuItemClicked()));
        itemIndex++;
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

    QPushButton* thisItem = qobject_cast<QPushButton*>(sender());
    QVariant containerIndex = thisItem->property("menuContainerIndex");
    QVariant NodeIndex = thisItem->property("menuNodeIndex");

    quint8 childNum = this->data->nodeMenuList[NodeIndex.toInt()].childNodeIndexList.size();
    quint8 itemLengthOld, itemLengthNew;

    if (!childNum)
    {
        return;
    }

    if (!containerIndex.isValid())
    {
        thisItem->setProperty("menuContainerIndex", this->LeftMenuContainerList.size());
        containerAttr.containerIndex = -1;
    }
    else
    {
        containerAttr.containerIndex = containerIndex.toInt();
    }

    itemLengthOld = this->LeftMenuItemList.size();

    containerAttr.parentItemIndex = NodeIndex.toInt();
    containerAttr.itemLength = childNum;


    LeftMenuView::fLoadLeftMenuContainer(containerAttr);

    itemLengthNew = this->LeftMenuItemList.size();

    while (itemLengthOld < itemLengthNew)
    {
        QObject::connect(this->LeftMenuItemList[itemLengthOld], SIGNAL(clicked()),
                this, SLOT(eLeftMenuItemClicked()));
        itemLengthOld++;
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
