#ifndef DAOLOGININFO_H
#define DAOLOGININFO_H

#include "src/middle/models/dbmodels.h"
#include "src/helper/dbsqlite.h"

class DaoLoginInfo {
public:
    DaoLoginInfo();

    void connect();

    void createTable();

    bool exists(const QString &secretId);

    void insert(const LoginInfo &info);

    void update(const LoginInfo &info);

    void remove(const QString &secretId);

    QList<LoginInfo> select();

private:
    DBSqlite m_db;
};

#endif // DAOLOGININFO_H
