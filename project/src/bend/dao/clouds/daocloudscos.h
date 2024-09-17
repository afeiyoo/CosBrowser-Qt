#ifndef DAOCLOUDSCOS_H
#define DAOCLOUDSCOS_H

#include "daoclouds.h"

class DaoCloudsCos : public DaoClouds {
public:
    DaoCloudsCos();

    QList<MyBucket> buckets() override;

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;
};

#endif  // DAOCLOUDSCOS_H
