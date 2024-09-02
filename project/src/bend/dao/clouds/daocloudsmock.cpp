#include "daocloudsmock.h"

#include <QDebug>
#include <QJsonArray>
#include <QThread>

#include "src/config/errorcode.h"
#include "src/config/exception.h"
#include "src/helper/filehelper.h"
#include "src/middle/manglobal.h"

DaoCloudsMock::DaoCloudsMock(const QString &path) { m_mock = FileHelper::readAllJson(path).toJsonValue(); }

QList<MyBucket> DaoCloudsMock::buckets() {
    QList<MyBucket> res;
    QJsonArray      arr = m_mock["buckets"].toArray();

    for (int i = 0; i < arr.count(); ++i) {
        QJsonValue v = arr[i];
        MyBucket   bucket;
        bucket.name       = v["name"].toString();
        bucket.location   = v["location"].toString();
        bucket.createDate = v["create_date"].toString();

        res.append(bucket);
        mInfo(QString("name[%1], location[%2], date[%3]").arg(bucket.name, bucket.location, bucket.createDate));
    }

    return res;
}

QList<MyBucket> DaoCloudsMock::login(const QString &secretId, const QString &secretKey) {
    QThread::sleep(3);
    QJsonArray arr = m_mock["users"].toArray();
    for (int i = 0; i < arr.count(); ++i) {
        QJsonValue v = arr[i];
        if (secretId == v["secretId"].toString() && secretKey == v["secretKey"].toString()) {
            return buckets();
        }
    }

    throw BaseException(EC_211000, QString("请检查您的secretId或secretKey是否正确"));
}

bool DaoCloudsMock::isBucketExists(const QString &bucketName) { return false; }

QString DaoCloudsMock::getBucketLocation(const QString &bucketName) { return ""; }

void DaoCloudsMock::putBucket(const QString &bucketName, const QString &location) {}

void DaoCloudsMock::deleteBucket(const QString &bucketName) {}
