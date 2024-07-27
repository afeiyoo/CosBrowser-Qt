#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DBSqlite
{
public:
    DBSqlite();

    ~DBSqlite();

    void connect(const QString &dbPath);

    QSqlQuery exec(const QString &sql);

    bool exists(const QString &sql);

private:
    QSqlDatabase m_db;
};

#endif // DBSQLITE_H
