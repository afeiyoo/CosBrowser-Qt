#ifndef DAOLOGININFOSQLITE_H
#define DAOLOGININFOSQLITE_H

#include "daologininfo.h"

class DaoLoginInfoSqlite : public DaoLoginInfo {
public:
    DaoLoginInfoSqlite();

    void connect() override;

    void createTable() override;

    bool exists(const QString &secretId) override;

    void insert(const LoginInfo &info) override;

    void update(const LoginInfo &info) override;

    void remove(const QString &secretId) override;

    QList<LoginInfo> select() override;

private:
    DBSqlite m_db;
};

#endif  // DAOLOGININFOSQLITE_H
