#ifndef MANSIGNALS_H
#define MANSIGNALS_H

#include <QObject>

#include "src/middle/models/cloudmodels.h"

class ManSignals : public QObject {
    Q_OBJECT
public:
    explicit ManSignals(QObject* parent = nullptr);

    ~ManSignals();

signals:
    void loginSuccess();

    void error(int api, const QString& msg, const QJsonValue& req);

    void unLogin();

    // 获取存储桶列表成功
    void bucketsSuccess(const QList<MyBucket>& buckets);

    // 获取对象列表成功
    void objectsSuccess(const QList<MyObject>& objects);

    // 下载对象进度
    void downloadProcess(const QString& jobId, qulonglong transferred, qulonglong total);

    // 下载对象成功
    void downloadSuccess(const QString& jobId);

    // 上传对象进度
    void uploadProcess(const QString& jobId, qulonglong transferred, qulonglong total);

    // 上传对象成功
    void uploadSuccess(const QString& jobId);

    // 开始上传
    void startUpload(const QString& jobId, const QString& key, const QString& localPath);

    // 开始下载
    void startDownload(const QString& jobId, const QString& key, const QString& localPath, qulonglong total);
};

#endif  // MANSIGNALS_H
