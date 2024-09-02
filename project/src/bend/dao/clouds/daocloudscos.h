#ifndef DAOCLOUDSCOS_H
#define DAOCLOUDSCOS_H

#include "daoclouds.h"

namespace qcloud_cos {
class CosResult;
class CosConfig;
}  // namespace qcloud_cos

class DaoCloudsCos : public DaoClouds {
public:
    DaoCloudsCos();

    ~DaoCloudsCos();

    QList<MyBucket> buckets() override;

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;

    bool isBucketExists(const QString& bucketName) override;

    virtual QString getBucketLocation(const QString& bucketName) override;

    void putBucket(const QString& bucketName, const QString& location) override;

    void deleteBucket(const QString& bucketName) override;

private:
    void throwError(const QString& code, qcloud_cos::CosResult& result);

private:
    qcloud_cos::CosConfig* m_config = nullptr;
};

#endif  // DAOCLOUDSCOS_H
