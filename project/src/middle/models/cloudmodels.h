#ifndef CLOUDMODELS_H
#define CLOUDMODELS_H

#include <QMetaType>
#include <QString>

struct BaseObject {
    bool isValid() const { return !isInvalid(); }
    bool isInvalid() const { return name.isNull() || name.isEmpty(); }

    QString name;
};
// 自定义参数在信号中的传递
// 1. Q_DECLARE_METATYPE，进行声明
// 2. 使用qRegisterMetaType进行注册
Q_DECLARE_METATYPE(BaseObject);

struct MyBucket : public BaseObject {
    MyBucket();
    QString location;
    QString createDate;
};
Q_DECLARE_METATYPE(MyBucket);

struct MyObject : public BaseObject {
    QString    lastmodified;
    qulonglong size = 0;
    QString    dir;
};
Q_DECLARE_METATYPE(MyObject);

#endif  // CLOUDMODELS_H
