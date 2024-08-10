#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QVariant>

typedef QMap<QString, QVariant> RECORD;

class DBSqlite {
public:
    DBSqlite();

    ~DBSqlite();

    void connect(const QString &dbPath);

    QSqlQuery exec(const QString &sql);

    QSqlQuery exec(const QString &sql, const QVariantList &variantList);

    bool exists(const QString &sql);

    QList<RECORD> select(const QString &sql);

private:
    QSqlDatabase m_db;
};

#endif  // DBSQLITE_H
