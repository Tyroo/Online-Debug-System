#ifndef SQLITECONTROL_H
#define SQLITECONTROL_H

#include <QSqlDatabase>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlError>
#include <QSqlQuery>
#include <vector>

using namespace std;


class SqliteControl
{

public:

    /*
    * @说明：连接SQLite数据库
    * @参数：dataBase，SQLite的.db文件的路径
    * @返回值：无
    */
    void connect(QString dataBase);

    /*
    * @说明：查询SQLite数据库中的数据，此为模板函数，调用时需要根据返回数据设置类型
    * @参数：sqlstr，SQL语句字符串；data，获得的数据
    * @返回值：无
    * @提示：data类型应始终为vector<T>类型，不可为其他简单类型
    */
    void query(QString sqlstr, vector<QVariantList>& data, quint8 keyNum);

    /*
    * @说明：断开当前所连接的SQLite
    * @参数：无
    * @返回值：无
    */
    void disconnect(void);

private:

    bool _status;

    QSqlDatabase _dataBase;

    QSqlQuery _query;
};


#endif
