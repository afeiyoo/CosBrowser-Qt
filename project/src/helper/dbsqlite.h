#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>

class DBSqlite
{
public:
    DBSqlite();

    ~DBSqlite();

    void connect(const QString &dbPath);

private:
    QSqlDatabase m_db;
};

#endif // DBSQLITE_H
