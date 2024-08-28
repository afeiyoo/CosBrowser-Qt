#ifndef MANCLOUD_H
#define MANCLOUD_H

#include <QObject>
#include <QStandardItemModel>

class ManCloud : public QObject {
    Q_OBJECT
public:
    // 对于使用Qt宏创建单例
    // 不要使用ManBuckets构造函数创建对象，直接使用instance来使用对象即可
    explicit ManCloud(QObject *parent = nullptr);

    ~ManCloud();

    void login(QString secretId, QString secretKey);

signals:
};

#endif  // MANCLOUD_H
