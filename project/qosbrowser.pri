QT       += core gui sql concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# QtCreator用MinGw编译OK，切换成MSVC后报错如"常量中有换行符"等错误
# 引入该变量定义后解决
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

SOURCES += \
    $$PWD/src/bend/dao/clouds/daoclouds.cpp \
    $$PWD/src/bend/dao/clouds/daocloudscos.cpp \
    $$PWD/src/bend/dao/clouds/daocloudsmock.cpp \
    $$PWD/src/bend/dao/configs/version.cpp \
    $$PWD/src/bend/dao/configs/versioncmd.cpp \
    $$PWD/src/bend/dao/configs/versionjson.cpp \
    $$PWD/src/bend/dao/dbs/daologininfo.cpp \
    $$PWD/src/bend/dao/dbs/daologininfosqlite.cpp \
    $$PWD/src/bend/dao/logs/basiclogger.cpp \
    $$PWD/src/bend/dao/logs/loggerlog4qt.cpp \
    $$PWD/src/bend/dao/logs/loggerqdebug.cpp \
    $$PWD/src/bend/gateway/gateway.cpp \
    $$PWD/src/bend/man/mancloud.cpp \
    $$PWD/src/bend/man/mandb.cpp \
    $$PWD/src/config/exception.cpp \
    $$PWD/src/config/loggerproxy.cpp \
    $$PWD/src/fend/uicom/breadwidget.cpp \
    $$PWD/src/fend/uicom/mylineedit.cpp \
    $$PWD/src/fend/uicom/pagewidget.cpp \
    $$PWD/src/fend/uidelegate/bucketdelegate.cpp \
    $$PWD/src/fend/uilogin/logindialog.cpp \
    $$PWD/src/fend/uimain/bucketswidget.cpp \
    $$PWD/src/fend/uimain/objectswidget.cpp \
    $$PWD/src/fend/uimain/toolbarwidget.cpp \
    $$PWD/src/fend/uimain/uimain.cpp \
    $$PWD/src/helper/dbsqlite.cpp \
    $$PWD/src/helper/filehelper.cpp \
    $$PWD/src/middle/manglobal.cpp \
    $$PWD/src/middle/manmodels.cpp \
    $$PWD/src/middle/models/cloudmodels.cpp \
    $$PWD/src/middle/signals/mansignals.cpp \
    $$PWD/src/plugins/manplugin.cpp

HEADERS += \
    $$PWD/src/bend/dao/clouds/daoclouds.h \
    $$PWD/src/bend/dao/clouds/daocloudscos.h \
    $$PWD/src/bend/dao/clouds/daocloudsmock.h \
    $$PWD/src/bend/dao/configs/version.h \
    $$PWD/src/bend/dao/configs/versioncmd.h \
    $$PWD/src/bend/dao/configs/versionjson.h \
    $$PWD/src/bend/dao/dbs/daologininfo.h \
    $$PWD/src/bend/dao/dbs/daologininfosqlite.h \
    $$PWD/src/bend/dao/logs/basiclogger.h \
    $$PWD/src/bend/dao/logs/loggerlog4qt.h \
    $$PWD/src/bend/dao/logs/loggerqdebug.h \
    $$PWD/src/bend/gateway/gateway.h \
    $$PWD/src/bend/man/mancloud.h \
    $$PWD/src/bend/man/mandb.h \
    $$PWD/src/bend/models/dbmodels.h \
    $$PWD/src/config/apis.h \
    $$PWD/src/config/errorcode.h \
    $$PWD/src/config/exception.h \
    $$PWD/src/config/globals.h \
    $$PWD/src/config/loggerproxy.h \
    $$PWD/src/fend/uicom/breadwidget.h \
    $$PWD/src/fend/uicom/mylineedit.h \
    $$PWD/src/fend/uicom/pagewidget.h \
    $$PWD/src/fend/uidelegate/bucketdelegate.h \
    $$PWD/src/fend/uilogin/logindialog.h \
    $$PWD/src/fend/uimain/bucketswidget.h \
    $$PWD/src/fend/uimain/objectswidget.h \
    $$PWD/src/fend/uimain/toolbarwidget.h \
    $$PWD/src/fend/uimain/uimain.h \
    $$PWD/src/helper/dbsqlite.h \
    $$PWD/src/helper/filehelper.h \
    $$PWD/src/middle/manglobal.h \
    $$PWD/src/middle/manmodels.h \
    $$PWD/src/middle/models/cloudmodels.h \
    $$PWD/src/middle/models/dbmodels.h \
    $$PWD/src/middle/signals/mansignals.h \
    $$PWD/src/plugins/manplugin.h

FORMS += \
    $$PWD/src/fend/uicom/breadwidget.ui \
    $$PWD/src/fend/uicom/pagewidget.ui \
    $$PWD/src/fend/uilogin/logindialog.ui \
    $$PWD/src/fend/uimain/bucketswidget.ui \
    $$PWD/src/fend/uimain/objectswidget.ui \
    $$PWD/src/fend/uimain/toolbarwidget.ui \
    $$PWD/src/fend/uimain/uimain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 定义Log4Qt的源码根目录
# LOG4QT_ROOT_PATH = $$PWD/third/log4qt

# win32:CONFIG(release, debug|release): LIBS += -L$$LOG4QT_ROOT_PATH/bin/ -llog4qt
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$LOG4QT_ROOT_PATH/bin/ -llog4qtd
# else:unix: LIBS += -L$$LOG4QT_ROOT_PATH/bin/ -llog4qt

# INCLUDEPATH += $$LOG4QT_ROOT_PATH/src/ \
#                $$LOG4QT_ROOT_PATH/src/log4qt \
#                $$LOG4QT_ROOT_PATH/include/ \
#                $$LOG4QT_ROOT_PATH/include/log4qt

# DEPENDPATH += $$LOG4QT_ROOT_PATH/src/ \
#               $$LOG4QT_ROOT_PATH/src/log4qt \
#               $$LOG4QT_ROOT_PATH/include/ \
#               $$LOG4QT_ROOT_PATH/include/log4qt


# 导入COSSDK库及其依赖
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/third/cos/libs/x64/ -lcossdk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/third/cos/libs/x64/ -lcossdkd
else:unix: LIBS += -L$$PWD/third/cos/libs/x64/ -lcossdk

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/third/cos/third_party/lib/x64/poco/ -lPocoFoundation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/third/cos/third_party/lib/x64/poco/ -lPocoFoundation
else:unix: LIBS += -L$$PWD/third/cos/third_party/lib/x64/poco/ -lPocoFoundation

INCLUDEPATH += $$PWD/third/cos/include \
    $$PWD/third/cos/third_party/include
DEPENDPATH += $$PWD/third/cos/include \
    $$PWD/third/cos/third_party/include
