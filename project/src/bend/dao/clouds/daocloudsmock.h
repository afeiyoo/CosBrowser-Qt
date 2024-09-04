#ifndef DAOCLOUDSMOCK_H
#define DAOCLOUDSMOCK_H

#include <QJsonValue>
#include <QList>

#include "src/bend/dao/clouds/daoclouds.h"
#include "src/middle/models/cloudmodels.h"

class DaoCloudsMock : public DaoClouds {
public:
    DaoCloudsMock(const QString& path);

    QList<MyBucket> buckets() override;

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;

    bool isBucketExists(const QString& bucketName) override;

    virtual QString getBucketLocation(const QString& bucketName) override;

    void putBucket(const QString& bucketName, const QString& location) override;

    void deleteBucket(const QString& bucketName) override;

    QList<MyObject> getObjects(const QString& bucketName, const QString& dir) override;

    void putObject(const QString& bucketName, const QString& key, const QString& localPath,
                   const TransProgressCallback& callback) override;

    void getObject(const QString& bucketName, const QString& key, const QString& localPath,
                   const TransProgressCallback& callback) override;

private:
    QJsonValue m_mock;
};

#endif  // DAOCLOUDSMOCK_H
