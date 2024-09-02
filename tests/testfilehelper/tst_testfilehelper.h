#ifndef TESTFILEHELPER_H
#define TESTFILEHELPER_H

#include <QtTest>

class TestFileHelper : public QObject {
    Q_OBJECT

public:
    TestFileHelper();
    ~TestFileHelper();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_readAllTxt();  // 测试用例需要以test_开头
    void test_joinPath();
};

#endif  // TESTFILEHELPER_H
