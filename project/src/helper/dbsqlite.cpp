#include "dbsqlite.h"

#include <QSqlRecord>
#include <QDebug>


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

QSqlQuery DBSqlite::exec(const QString &sql)
{
    QSqlQuery query;
    if(!query.exec(sql)){
        throw QString("执行失败: %1 %2").arg(sql, query.lastError().text());
    }

    return query;
}

QSqlQuery DBSqlite::exec(const QString &sql, const QVariantList &variantList)
{
    QSqlQuery query;
    if(!query.prepare(sql)){
        throw QString("预编译sql失败: %1 %2").arg(sql, query.lastError().text());
    }

    for(const auto& var : variantList){
        query.addBindValue(var);
    }

    if(!query.exec()){
        throw QString("执行sql bindvalue失败: %1 %2").arg(sql, query.lastError().text());
    }

    return query;
}

bool DBSqlite::exists(const QString &sql)
{
    QSqlQuery query = exec(sql);
    return query.next();
}

QList<RECORD> DBSqlite::select(const QString& sql)
{
    QList<RECORD> retList;
    QSqlQuery query = exec(sql);

    while(query.next()){
        RECORD ret;

        QSqlRecord record = query.record(); // 数据库中的一行记录
        for(int i = 0; i < record.count(); ++i){
            QString name = record.fieldName(i);
            QVariant value = record.value(i);
            ret[name] = value;
        }
        qDebug() << QString("查询出结果") << ret;
        retList.append(ret);
    }

    return retList;
}
