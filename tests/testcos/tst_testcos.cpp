
#include "tst_testcos.h"

TestCos::TestCos() {}

TestCos::~TestCos() {}

void TestCos::initTestCase() {
    // 登录
    m_cos.login("xxxxx", "xxxxx");
}

void TestCos::cleanupTestCase() {}

void TestCos::test_buckets() {
    QList<MyBucket> bs = m_cos.buckets();
    // QCOMPARE(bs.size(), 1);  // QCOMPARE 进行恒等比较
    QVERIFY(bs.size() > 0);  // QVERIFY 进行Bool表达式的判断，如果为真，则表示通过。否则，表示失败。
}
