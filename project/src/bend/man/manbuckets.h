#ifndef MANBUCKETS_H
#define MANBUCKETS_H

#include <QObject>
#include <QStandardItemModel>

#define MB ManBuckets::instance()

class ManBuckets : public QObject {
    Q_OBJECT
public:
    // 对于使用Qt宏创建单例
    // 不要使用ManBuckets构造函数创建对象，直接使用instance来使用对象即可
    explicit ManBuckets(QObject *parent = nullptr);

    static ManBuckets *instance();

    void setBuckets();

    QStandardItemModel *model() const;

signals:

private:
    // 由于1个模型对应多个视图，所以对该模型使用单例模式
    QStandardItemModel* m_model = nullptr;
};

#endif // MANBUCKETS_H
