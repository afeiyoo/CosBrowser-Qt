#include <QtTest>

// add necessary includes here
#include "../../project/src/config/exception.h"

class testexception : public QObject {
    Q_OBJECT

public:
    testexception();
    ~testexception();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_generateErrorCodeHFile();
};

testexception::testexception() {}

testexception::~testexception() {}

void testexception::initTestCase() {}

void testexception::cleanupTestCase() {}

void testexception::test_generateErrorCodeHFile() {
    BaseException::generateErrorCodeHFile("../../../CosBrowser/project/static/docs/errorcode.csv",
                                          "../../../CosBrowser/project/src/config/errorcode.h");
}

QTEST_APPLESS_MAIN(testexception)

#include "tst_testexception.moc"
