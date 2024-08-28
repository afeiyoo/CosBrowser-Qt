#ifndef MANMODELS_H
#define MANMODELS_H

#include <QObject>
#include <QStandardItemModel>

#include "src/middle/models/cloudmodels.h"

class ManModels : public QObject {
    Q_OBJECT
public:
    explicit ManModels(QObject* parent = nullptr);

    void setBuckets(const QList<MyBucket>& buckets);

    QStandardItemModel* model() const;

signals:

private:
    // 由于1个模型对应多个视图，所以对该模型使用单例模式
    QStandardItemModel* m_model = nullptr;
};

#endif  // MANMODELS_H
