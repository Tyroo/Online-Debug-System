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
    quint8 rowsNum, levelNum;
    DataBaseConfig dbConfig;
    SqliteControl sqlCtrl;

    vector<QVariantList> levelNumArray, menuNodeArray;
    vector<LeftMenuNodeType> levelMenuNodeList;

    QVariantList rowData;
    LeftMenuNodeType LeftMenuNode;

//    dbConfig.dataBaseName = QDir::currentPath() + "/release/DataBase/Online-Debug-System.accdb";
//    dbConfig.dataBaseUsername = "ZJL";
//    dbConfig.dataBasePassword = "123456";

    // 查询数据库, 获取原始数据
//    sqlCtrl.connect(dbConfig);
    sqlCtrl.connect(QDir::currentPath() + "/release/DataBase/Online-Debug-System.db");
    sqlCtrl.query(QString(QUERY_LEFTMENU_LEVELNUM_CN_SQL), levelNumArray, 1);
    sqlCtrl.query(QString(QUERY_LEFTMENU_NODELIST_CN_SQL), menuNodeArray, nodeBottom);
    sqlCtrl.disconnect();

    levelNum = levelNumArray.back().back().toInt();
    rowsNum = menuNodeArray.size();

    nodeMenuList.insert(nodeMenuList.begin(), levelNum, levelMenuNodeList);

    // 依据原始数据格式化成LeftMenuNodeType数据，并装入MenuNodeList中
    for (quint8 i=0; i<rowsNum; i++)
    {
        rowData = menuNodeArray[i];
        LeftMenuNode.nodeName = rowData[nodeName].toString();
        LeftMenuNode.nodeIcon = rowData[nodeIcon].toString();
        LeftMenuNode.nodeLevel = rowData[nodeLevel].toInt();
        LeftMenuNode.nodeIndex = rowData[nodeIndex].toInt();
        LeftMenuNode.nodeStatus = rowData[nodeStatus].toInt();
        LeftMenuNode.nodeParentIndex = rowData[nodeParentIndex].toInt();

        nodeMenuList[LeftMenuNode.nodeLevel].push_back(LeftMenuNode);

        if (LeftMenuNode.nodeLevel)
        {
            nodeMenuList[LeftMenuNode.nodeLevel - 1][LeftMenuNode.nodeParentIndex]
                .childNodeIndexList
                .push_back(LeftMenuNode.nodeIndex);
        }
    }
}
