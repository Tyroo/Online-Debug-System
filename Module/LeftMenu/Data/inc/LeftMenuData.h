#ifndef LEFTMENUDATA_H
#define LEFTMENUDATA_H

#include <QString>
#include <vector>
#include <QDir>
#include "Library/SqliteControl/inc/SqliteControl.h"

using namespace std;

#define QUERY_LEFTMENU_LEVELNUM_CN_SQL (\
    "SELECT COUNT(*) AS LevelCount FROM (SELECT NodeLevel FROM LeftMenuNodeList_CN GROUP BY NodeLevel)")

#define QUERY_LEFTMENU_NODELIST_CN_SQL   (\
    "SELECT * FROM (SELECT * FROM LeftMenuNodeList_CN ORDER BY NodeIndex) ORDER BY NodeLevel")


// 菜单树形结构体
typedef struct _LeftMenuNodeType
{
    QString nodeIcon;       // 节点图标地址
    QString nodeName;           // 节点名称
    qint8 nodeStatus:2;         // 节点状态（0禁用~1启用）
    qint8 nodeLevel:4;          // 当前节点级别（0~N）S
    qint8 nodeIndex:5;          // 当前节点索引（0~N）
    qint8 nodeParentIndex:5;    // 父节点索引（-1~N）
    vector<qint8> childNodeIndexList;    // 子节点索引列表[1,2,3,...,N]
} LeftMenuNodeType;

enum _LeftMenuNodeEnum
{
    id,
    nodeName,
    nodeIcon,
    nodeStatus,
    nodeLevel,
    nodeIndex,
    nodeParentIndex,
    nodeBottom,
};


class LeftMenuData
{

public:

   vector<vector<LeftMenuNodeType>> nodeMenuList;

public:

    /*
    * @说明：主数据类构造函数
    * @参数：无
    * @返回值：无
    */
    LeftMenuData();

    /*
    * @说明：主数据类析构函数
    * @参数：无
    * @返回值：无
    */
    ~LeftMenuData();

private:

    /*
    * @说明：初始化主数据
    * @参数：无
    * @返回值：无
    */
    void mInitLeftMenuData(void);

};

#endif
