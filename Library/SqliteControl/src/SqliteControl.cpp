#include "Library/SqliteControl/inc/SqliteControl.h"


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
