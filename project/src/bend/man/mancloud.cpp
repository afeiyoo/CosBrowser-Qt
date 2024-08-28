#include "mancloud.h"

#include <QDebug>

#include "src/bend/dao/clouds/daoclouds.h"
#include "src/middle/manglobal.h"
#include "src/middle/models/cloudmodels.h"
#include "src/plugins/manplugin.h"

ManCloud::ManCloud(QObject *parent) : QObject{parent} { m_model = new QStandardItemModel(this); }

ManCloud::~ManCloud() { qDebug("delete ManCloud "); }

void ManCloud::setBuckets() {
    DaoClouds      *dao     = MG->mPlugin->clouds();
    QList<MyBucket> buckets = dao->buckets();
    m_model->setRowCount(buckets.size());
    for (int i = 0; i < buckets.size(); ++i) {
        const MyBucket &bucket = buckets[i];
        QModelIndex     index0 = m_model->index(i, 0);
        m_model->setData(index0, bucket.name);
        m_model->setData(index0, QString("存储桶名称: %1").arg(bucket.name), Qt::ToolTipRole);

        QModelIndex index1 = m_model->index(i, 1);
        m_model->setData(index1, bucket.location);

        QModelIndex index2 = m_model->index(i, 2);
        m_model->setData(index2, bucket.createDate);
    }
    // 按第3列降序排序
    m_model->sort(2, Qt::DescendingOrder);
}

QStandardItemModel *ManCloud::model() const { return m_model; }

void ManCloud::login(QString secretId, QString secretKey) {
    QList<MyBucket> buckets = MG->mPlugin->clouds()->login(secretId, secretKey);
}
