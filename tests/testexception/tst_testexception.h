#ifndef TESTEXCEPTION_H
#define TESTEXCEPTION_H

#include <QtTest>

class TestException : public QObject {
    Q_OBJECT

public:
    TestException();
    ~TestException();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_generateErrorCodeHFile();
};

#endif  // TESTEXCEPTION_H
