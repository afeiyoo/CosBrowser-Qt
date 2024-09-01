#include <QtTest>

// add necessary includes here
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

private:
    DaoCloudsCos m_cos;
};

TestCos::TestCos() {}

TestCos::~TestCos() {}

void TestCos::initTestCase() {
    // 登录
    m_cos.login("xxxxx", "xxxxx");
}

void TestCos::cleanupTestCase() {}

void TestCos::test_buckets() {
    QList<MyBucket> bs = m_cos.buckets();
    QCOMPARE(bs.size(), 1);  // QCOMPARE 进行恒等比较
    QVERIFY(bs.size() > 0);  // QVERIFY 进行Bool表达式的判断，如果为真，则表示通过。否则，表示失败。
}

QTEST_APPLESS_MAIN(TestCos)

#include "tst_testcos.moc"
