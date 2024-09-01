QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# 导入COSSDK库及其依赖
THIRD_DIR = $$PWD/../../project/third

win32:CONFIG(release, debug|release): LIBS += -L$$THIRD_DIR/cos/libs/x64/ -lcossdk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$THIRD_DIR/cos/libs/x64/ -lcossdkd
else:unix: LIBS += -L$$THIRD_DIR/cos/libs/x64/ -lcossdk

win32:CONFIG(release, debug|release): LIBS += -L$$THIRD_DIR/cos/third_party/lib/x64/poco/ -lPocoFoundation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$THIRD_DIR/cos/third_party/lib/x64/poco/ -lPocoFoundation
else:unix: LIBS += -L$$THIRD_DIR/cos/third_party/lib/x64/poco/ -lPocoFoundation

INCLUDEPATH += $$THIRD_DIR/cos/include \
    $$THIRD_DIR/cos/third_party/include
DEPENDPATH += $$THIRD_DIR/cos/include \
    $$THIRD_DIR/cos/third_party/include

SOURCES +=  tst_testcos.cpp \
    ../../project/src/bend/dao/clouds/daoclouds.cpp \
    ../../project/src/bend/dao/clouds/daocloudscos.cpp \
    ../../project/src/config/exception.cpp \
    ../../project/src/helper/filehelper.cpp \
    ../../project/src/middle/models/cloudmodels.cpp

INCLUDEPATH += \
    ../../project

HEADERS += \
    ../../project/src/bend/dao/clouds/daoclouds.h \
    ../../project/src/bend/dao/clouds/daocloudscos.h \
    ../../project/src/config/errorcode.h \
    ../../project/src/config/exception.h \
    ../../project/src/helper/filehelper.h \
    ../../project/src/middle/models/cloudmodels.h
