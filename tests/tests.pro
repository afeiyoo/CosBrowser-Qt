QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../project/qosbrowser.pri)

SOURCES +=  \
    main.cpp \
    testcos/tst_testcos.cpp \
    testexception/tst_testexception.cpp \
    testfilehelper/tst_testfilehelper.cpp

INCLUDEPATH += \
    ../project

HEADERS += \
    testcos/tst_testcos.h \
    testexception/tst_testexception.h \
    testfilehelper/tst_testfilehelper.h

RESOURCES += \
    resource.qrc
