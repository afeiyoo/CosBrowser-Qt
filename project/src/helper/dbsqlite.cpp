#include "dbsqlite.h"

#include <QSqlQuery>

DBSqlite::DBSqlite() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

DBSqlite::~DBSqlite()
{
    if(m_db.isOpen()){
        m_db.close();
    }
}

void DBSqlite::connect(const QString &dbPath)
{
    m_db.setDatabaseName(dbPath);
    if(!m_db.open()){
        throw QString("打开数据库失败: %1 %2").arg(dbPath, m_db.lastError().text());
    }
}

void DBSqlite::exec(const QString &sql)
{
    QSqlQuery query;
    if(!query.exec(sql)){
        throw QString::fromLocal8Bit("执行失败: %1 %2").arg(sql, query.lastError().text());
    }
}
