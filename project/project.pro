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
    main.cpp \
    src/bend/dao/clouds/daoclouds.cpp \
    src/bend/dao/clouds/daocloudscos.cpp \
    src/bend/dao/clouds/daocloudsmock.cpp \
    src/bend/dao/configs/version.cpp \
    src/bend/dao/configs/versioncmd.cpp \
    src/bend/dao/configs/versionjson.cpp \
    src/bend/dao/dbs/daologininfo.cpp \
    src/bend/dao/dbs/daologininfosqlite.cpp \
    src/bend/dao/logs/basiclogger.cpp \
    src/bend/dao/logs/loggerlog4qt.cpp \
    src/bend/dao/logs/loggerqdebug.cpp \
    src/bend/gateway/gateway.cpp \
    src/bend/man/mancloud.cpp \
    src/bend/man/mandb.cpp \
    src/config/exception.cpp \
    src/config/loggerproxy.cpp \
    src/fend/uicom/breadwidget.cpp \
    src/fend/uicom/mylineedit.cpp \
    src/fend/uicom/pagewidget.cpp \
    src/fend/uidelegate/bucketdelegate.cpp \
    src/fend/uilogin/logindialog.cpp \
    src/fend/uimain/bucketswidget.cpp \
    src/fend/uimain/objectswidget.cpp \
    src/fend/uimain/toolbarwidget.cpp \
    src/fend/uimain/uimain.cpp \
    src/helper/dbsqlite.cpp \
    src/helper/filehelper.cpp \
    src/middle/manglobal.cpp \
    src/middle/manmodels.cpp \
    src/middle/models/cloudmodels.cpp \
    src/middle/signals/mansignals.cpp \
    src/plugins/manplugin.cpp

HEADERS += \
    src/bend/dao/clouds/daoclouds.h \
    src/bend/dao/clouds/daocloudscos.h \
    src/bend/dao/clouds/daocloudsmock.h \
    src/bend/dao/configs/version.h \
    src/bend/dao/configs/versioncmd.h \
    src/bend/dao/configs/versionjson.h \
    src/bend/dao/dbs/daologininfo.h \
    src/bend/dao/dbs/daologininfosqlite.h \
    src/bend/dao/logs/basiclogger.h \
    src/bend/dao/logs/loggerlog4qt.h \
    src/bend/dao/logs/loggerqdebug.h \
    src/bend/gateway/gateway.h \
    src/bend/man/mancloud.h \
    src/bend/man/mandb.h \
    src/bend/models/dbmodels.h \
    src/config/apis.h \
    src/config/errorcode.h \
    src/config/exception.h \
    src/config/globals.h \
    src/config/loggerproxy.h \
    src/fend/uicom/breadwidget.h \
    src/fend/uicom/mylineedit.h \
    src/fend/uicom/pagewidget.h \
    src/fend/uidelegate/bucketdelegate.h \
    src/fend/uilogin/logindialog.h \
    src/fend/uimain/bucketswidget.h \
    src/fend/uimain/objectswidget.h \
    src/fend/uimain/toolbarwidget.h \
    src/fend/uimain/uimain.h \
    src/helper/dbsqlite.h \
    src/helper/filehelper.h \
    src/middle/manglobal.h \
    src/middle/manmodels.h \
    src/middle/models/cloudmodels.h \
    src/middle/models/dbmodels.h \
    src/middle/signals/mansignals.h \
    src/plugins/manplugin.h

FORMS += \
    src/fend/uicom/breadwidget.ui \
    src/fend/uicom/pagewidget.ui \
    src/fend/uilogin/logindialog.ui \
    src/fend/uimain/bucketswidget.ui \
    src/fend/uimain/objectswidget.ui \
    src/fend/uimain/toolbarwidget.ui \
    src/fend/uimain/uimain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

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
