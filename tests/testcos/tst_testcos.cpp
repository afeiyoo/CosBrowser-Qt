
#include "tst_testcos.h"

#include "src/config/exception.h"

TestCos::TestCos() {}

TestCos::~TestCos() {}

void TestCos::initTestCase() {
    // 登录
    m_cos.login(m_secretId, m_secretKey);
}

void TestCos::cleanupTestCase() {}

void TestCos::test_buckets() {
    QList<MyBucket> bs = m_cos.buckets();
    // QCOMPARE(bs.size(), 1);  // QCOMPARE 进行恒等比较
    QVERIFY(bs.size() > 0);  // QVERIFY 进行Bool表达式的判断，如果为真，则表示通过。否则，表示失败。
}

void TestCos::test_isBucketExists() {
    bool exists = m_cos.isBucketExists(m_bucketName);
    QVERIFY(exists);
}

void TestCos::test_getBucketLocation() {
    QString location = m_cos.getBucketLocation(m_bucketName);
    QCOMPARE(location, "ap-nanjing");
}

void TestCos::test_putBucket() {
    // 当创建存储桶时，必须以appid结尾
    QSKIP("Skip test_putBucket");
    QString bucketName = "test3-1303210295";
    m_cos.putBucket(bucketName, "ap-nanjing");

    bool exists = m_cos.isBucketExists(bucketName);
    QVERIFY(exists);
}

void TestCos::test_deleteBucket() {
    QSKIP("Skip test_deleteBucket");
    QString bucketName = "test-1303210295";
    m_cos.deleteBucket(bucketName);

    bool notExists = m_cos.isBucketExists(bucketName);
    QVERIFY(!notExists);
}

void TestCos::test_getObjects() {
    QSKIP("SKIP test getObjects");
    QList<MyObject> objList = m_cos.getObjects(m_bucketName, "");
    QCOMPARE(objList.size(), 3);
}

void TestCos::test_getObjects2_data() {
    // 数据驱动：第一阶段，准备测试数据，函数名称需要_data结尾
    QTest::addColumn<QString>("dir");
    QTest::addColumn<int>("expected");

    QTest::newRow("root") << "" << 3;
    QTest::newRow("subdir") << "test/" << 2;
}

void TestCos::test_getObjects2() {
    // 数据驱动：第二阶段，从数据表读取数据，并执行比较
    QFETCH(QString, dir);
    QFETCH(int, expected);

    QList<MyObject> objList = m_cos.getObjects(m_bucketName, dir);
    QCOMPARE(objList.size(), expected);
}

void TestCos::test_getObjectError() {
    // QVERIFY_EXCEPTION_THROWN 捕获预期异常
    QVERIFY_EXCEPTION_THROWN(m_cos.getObjects("file", ""), BaseException);
}
