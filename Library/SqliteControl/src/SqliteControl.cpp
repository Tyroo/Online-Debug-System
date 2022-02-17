#include "Library/SqliteControl/inc/SqliteControl.h"

#ifdef USE_ACCESSDB
void SqliteControl::connect(DataBaseConfig& dbConfig)
{
    this->_dataBase = QSqlDatabase::addDatabase("QODBC");
    QString dataBase(QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DBQ=%1;Uid=%2;Pwd=%3;")
                              .arg(dbConfig.dataBaseName)
                              .arg(dbConfig.dataBaseUsername)
                              .arg(dbConfig.dataBasePassword));
    this->_dataBase.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3");
    this->_dataBase.setDatabaseName(dataBase);
    this->_query = QSqlQuery(this->_dataBase);

    if (!this->_dataBase.isValid())
    {
        qDebug() << "fail to connect MS Access:" << this->_dataBase.lastError().text();
        this->_status =  false;
        return;
    }

    if (!this->_dataBase.open())
    {
        qDebug() << "fail to connect MS Access:" << this->_dataBase.lastError().text();
        this->_status =  false;
        return;
    }

    this->_status = true;
}
#endif

#ifdef USE_SQLITEDB
void SqliteControl::connect(QString dataBase)
{

    this->_dataBase = QSqlDatabase::addDatabase("QSQLITE");
    this->_dataBase.setDatabaseName(dataBase);
    this->_query = QSqlQuery(this->_dataBase);

    if (!this->_dataBase.open())
    {
        qDebug() << "fail to connect sqlite:" << this->_dataBase.lastError().text();
        this->_status =  false;
        return;
    }

    this->_status = true;
}
#endif

void SqliteControl::query(QString sqlstr, vector<QVariantList>& rowArray, quint8 keyNum)
{
    if (!this->_status) return;

    this->_query.exec(sqlstr);

    while(this->_query.next())
    {
        QVariantList colArray;

        for (quint8 i=0; i<keyNum; i++)
        {
            colArray.append(this->_query.value(i));
        }

        rowArray.push_back(colArray);
    }
}


void SqliteControl::disconnect()
{
    this->_dataBase.close();
}
