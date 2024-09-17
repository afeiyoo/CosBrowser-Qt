#ifndef TESTCOS_H
#define TESTCOS_H

#include <QtTest>

#include "src/bend/dao/clouds/daocloudscos.h"

class TestCos : public QObject {
    Q_OBJECT

public:
    TestCos();
    ~TestCos();

private slots:
    // 调用所有测试用例之前，会先调用一次该函数
    void initTestCase();
    // 调用所有测试用例之后，会调用一次该函数
    void cleanupTestCase();
    void test_buckets();
    void test_isBucketExists();
    void test_getBucketLocation();
    void test_putBucket();
    void test_deleteBucket();
    void test_getObjects();
    void test_getObjects2_data();
    void test_getObjects2();
    void test_getObjectError();

private:
    DaoCloudsCos m_cos;
    QString      m_secretId   = "xxxx";            // 自己的id
    QString      m_secretKey  = "xxxx";            // 自己的Key
    QString      m_bucketName = "qos-1303210295";  // 自己的测试桶名称
};

#endif  // TESTCOS_H
