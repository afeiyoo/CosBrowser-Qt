#include "mandb.h"

#include <QDateTime>

Q_GLOBAL_STATIC(ManDB, ins)

ManDB::ManDB(QObject *parent) : QObject{parent} {}

ManDB *ManDB::instance() { return ins(); }

void ManDB::init() {
    m_daoLoginInfo.connect();
    m_daoLoginInfo.createTable();               // 创建登录表
    m_loginInfoList = m_daoLoginInfo.select();  // 读取登录信息到缓存
}

void ManDB::saveLoginInfo(const QString &name, const QString &id, const QString &key, const QString &remark) {
    LoginInfo info;
    info.name       = (name == "" ? id : name);
    info.secret_id  = id.trimmed();
    info.secret_key = key.trimmed();
    info.remark     = remark.trimmed();
    info.timestamp  = QDateTime::currentDateTimeUtc().toTime_t();

    if (m_daoLoginInfo.exists(info.secret_id)) {
        m_daoLoginInfo.update(info);
        m_loginInfoList[indexOfLoginInfo(info.secret_id)] = info;  // 缓存更新
    } else {
        m_daoLoginInfo.insert(info);
        m_loginInfoList.append(info);  // 缓存更新
    }
}

void ManDB::removeLoginInfo(const QString &id) {
    if (m_daoLoginInfo.exists(id)) {
        m_daoLoginInfo.remove(id);
        m_loginInfoList.removeAt(indexOfLoginInfo(id));  // 缓存更新
    }
}

int ManDB::indexOfLoginInfo(const QString &secretId) {
    for (int i = 0; i < m_loginInfoList.size(); ++i) {
        if (m_loginInfoList[i].secret_id == secretId) return i;
    }
    throw QString("获取登录信息索引失败 %1").arg(secretId);
}

QStringList ManDB::loginNameList() {
    QStringList words;
    for (int i = 0; i < m_loginInfoList.size(); ++i) {
        words.append(m_loginInfoList[i].name);
    }
    return words;
}

LoginInfo ManDB::loginInfoByName(const QString &name) {
    for (int i = 0; i < m_loginInfoList.size(); ++i) {
        if (m_loginInfoList[i].name == name) {
            return m_loginInfoList[i];
        }
    }
    throw QString("通过名称查找登录信息失败 %1").arg(name);
}
