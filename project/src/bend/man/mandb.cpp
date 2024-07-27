#include "mandb.h"
#include "src/config/config.h"

Q_GLOBAL_STATIC(ManDB, ins)

ManDB::ManDB(QObject *parent)
    : QObject{parent}
{}

ManDB *ManDB::instance()
{
    return ins();
}

void ManDB::init()
{
    connect();
    createLoginInfoTable(); // 创建登录表
}

void ManDB::connect()
{
    m_db.connect(CONF::SQLITE::NAME);
}

void ManDB::createLoginInfoTable()
{
    QString sql = FileHelper::readAllTxt(CONF::SQL::LOGIN_INFO_TABLE);
    m_db.exec(sql);
}
