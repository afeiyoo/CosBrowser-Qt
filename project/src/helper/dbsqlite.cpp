#include "dbsqlite.h"

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
