#ifndef DAOCLOUDSMOCK_H
#define DAOCLOUDSMOCK_H

#include "src/bend/dao/clouds/daoclouds.h"
#include "src/middle/models/cloudmodels.h"
#include <QJsonValue>
#include <QList>

class DaoCloudsMock : public DaoClouds
{
public:
    DaoCloudsMock(const QString &path);

    QList<MyBucket> buckets() override;

private:
    QJsonValue m_mock;
};

#endif // DAOCLOUDSMOCK_H
