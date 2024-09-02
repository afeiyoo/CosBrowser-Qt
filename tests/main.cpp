#include "testcos/tst_testcos.h"
#include "testexception/tst_testexception.h"
#include "testfilehelper/tst_testfilehelper.h"

int main(int argc, char *argv[]) {
    int status = 0;
    {
        TestFileHelper tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestException tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestCos tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
}
