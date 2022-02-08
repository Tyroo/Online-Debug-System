#include "./Module/LeftMenu/Data/inc/LeftMenuData.h"


/*------------------------------------------------------------
@作用：主数据类默认方法
@包含：LeftMenuData()、~LeftMenuData()
--------------------------------------------------------------*/

// 主数据类构造方法
LeftMenuData::LeftMenuData()
{
    // 初始化左侧栏数据
    this->mInitLeftMenuData();
}

// 主数据类析构方法
LeftMenuData::~LeftMenuData()
{
    // pass
}

/*------------------------------------------------------------
@作用：主数据类自定义方法
@包含：mInitLeftMenuData()
--------------------------------------------------------------*/

// 初始化主数据
void LeftMenuData::mInitLeftMenuData()
{
    quint8 rowNum, colNum;
    SqliteControl sqlCtrl;
    vector<QVariantList> rowArray;

    QVariantList rowData;
    LeftMenuNodeType LeftMenuNode;

    colNum = nodeBottom;

    // 查询数据库, 获取原始数据
    sqlCtrl.connect(QDir::currentPath() + "/release/DataBase/Online-Debug-System.db");
    sqlCtrl.query(QString(QUERY_LEFTMENU_NODELIST_CN_SQL), rowArray, colNum);
    sqlCtrl.disconnect();

    rowNum = rowArray.size();

    // 依据原始数据格式化成LeftMenuNodeType数据，并装入MenuNodeList中
    for (quint8 i=0; i<rowNum; i++)
    {
        rowData = rowArray[i];
        LeftMenuNode.nodeName = rowData[nodeName].toString();
        LeftMenuNode.nodeIcon = rowData[nodeIcon].toString();
        LeftMenuNode.nodeLevel = rowData[nodeLevel].toInt();
        LeftMenuNode.nodeIndex = rowData[nodeIndex].toInt();
        LeftMenuNode.nodeStatus = rowData[nodeStatus].toInt();
        LeftMenuNode.nodeParentIndex = rowData[nodeParentIndex].toInt();

        qDebug() << LeftMenuNode.nodeName << LeftMenuNode.nodeParentIndex;

        if (LeftMenuNode.nodeParentIndex >= 0)
        {
            nodeMenuList[LeftMenuNode.nodeParentIndex]
                .childNodeIndexList
                .push_back(i);
        }

        nodeMenuList.push_back(LeftMenuNode);
    }
}
