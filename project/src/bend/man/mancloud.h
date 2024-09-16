#ifndef MANCLOUD_H
#define MANCLOUD_H

#include <QObject>
#include <QStandardItemModel>

#include "src/middle/models/cloudmodels.h"

class ManCloud : public QObject {
    Q_OBJECT
public:
    // 对于使用Qt宏创建单例
    // 不要使用ManBuckets构造函数创建对象，直接使用instance来使用对象即可
    explicit ManCloud(QObject* parent = nullptr);

    ~ManCloud();

    void login(QString secretId, QString secretKey);

    // 桶操作接口
    void getBuckets();

    void putBucket(const QString& bucketName, const QString& location);

    void deleteBucket(const QString& bucketName);

    // 对象操作接口
    void getObjects(const QString& bucketName, const QString& dir = "");

    void getObject(const QString& jobId, const QString& bucketName, const QString& key, const QString& localPath);

    void putObjcet(const QString& jobId, const QString& bucketName, const QString& key, const QString& localPath);

    QString currentBucketName() const;

    QString currentDir() const;

private:
    void bucketsAlready(const QList<MyBucket>& buckets);

private:
    QString m_currentBucketName;  // 记录当前对象所在存储桶名称
    QString m_currentDir;         // 记录当前对象所在目录
};

#endif  // MANCLOUD_H
