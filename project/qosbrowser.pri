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
    $$PWD/src/fend/uicom/mylineedit.cpp \
    $$PWD/src/fend/uicom/uibasedialog.cpp \
    $$PWD/src/fend/uicom/uibreadwidget.cpp \
    $$PWD/src/fend/uicom/uicomboline.cpp \
    $$PWD/src/fend/uicom/uimessagebox.cpp \
    $$PWD/src/fend/uicom/uipagewidget.cpp \
    $$PWD/src/fend/uicom/uiprogresswidget.cpp \
    $$PWD/src/fend/uicom/uipushbutton.cpp \
    $$PWD/src/fend/uicom/uiqosdialog.cpp \
    $$PWD/src/fend/uidelegate/uibucketdelegate.cpp \
    $$PWD/src/fend/uilogin/uilogindialog.cpp \
    $$PWD/src/fend/uimain/uibucketslistwidget.cpp \
    $$PWD/src/fend/uimain/uicreatebucketdialog.cpp \
    $$PWD/src/fend/uimain/uimain.cpp \
    $$PWD/src/fend/uimain/uiobjectstablewidget.cpp \
    $$PWD/src/fend/uimain/uitoolbarwidget.cpp \
    $$PWD/src/fend/uitransfer/uidownload.cpp \
    $$PWD/src/fend/uitransfer/uitransfer.cpp \
    $$PWD/src/fend/uitransfer/uiupload.cpp \
    $$PWD/src/helper/bytehelper.cpp \
    $$PWD/src/helper/dbsqlite.cpp \
    $$PWD/src/helper/filehelper.cpp \
    $$PWD/src/middle/manglobal.cpp \
    $$PWD/src/middle/manmodels.cpp \
    $$PWD/src/middle/models/cloudmodels.cpp \
    $$PWD/src/middle/signals/mansignals.cpp \
    $$PWD/src/plugins/manplugin.cpp \
    $$PWD/src/fend/uimain/uibucketstablewidget.cpp

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
    $$PWD/src/fend/uicom/mylineedit.h \
    $$PWD/src/fend/uicom/uibasedialog.h \
    $$PWD/src/fend/uicom/uibreadwidget.h \
    $$PWD/src/fend/uicom/uicomboline.h \
    $$PWD/src/fend/uicom/uimessagebox.h \
    $$PWD/src/fend/uicom/uipagewidget.h \
    $$PWD/src/fend/uicom/uiprogresswidget.h \
    $$PWD/src/fend/uicom/uipushbutton.h \
    $$PWD/src/fend/uicom/uiqosdialog.h \
    $$PWD/src/fend/uidelegate/uibucketdelegate.h \
    $$PWD/src/fend/uilogin/uilogindialog.h \
    $$PWD/src/fend/uimain/uibucketslistwidget.h \
    $$PWD/src/fend/uimain/uicreatebucketdialog.h \
    $$PWD/src/fend/uimain/uimain.h \
    $$PWD/src/fend/uimain/uiobjectstablewidget.h \
    $$PWD/src/fend/uimain/uitoolbarwidget.h \
    $$PWD/src/fend/uitransfer/uidownload.h \
    $$PWD/src/fend/uitransfer/uitransfer.h \
    $$PWD/src/fend/uitransfer/uiupload.h \
    $$PWD/src/helper/bytehelper.h \
    $$PWD/src/helper/dbsqlite.h \
    $$PWD/src/helper/filehelper.h \
    $$PWD/src/middle/manglobal.h \
    $$PWD/src/middle/manmodels.h \
    $$PWD/src/middle/models/cloudmodels.h \
    $$PWD/src/middle/models/dbmodels.h \
    $$PWD/src/middle/signals/mansignals.h \
    $$PWD/src/plugins/manplugin.h \
    $$PWD/src/fend/uimain/uibucketstablewidget.h


FORMS += \
    $$PWD/src/fend/uicom/uibasedialog.ui \
    $$PWD/src/fend/uicom/uibreadwidget.ui \
    $$PWD/src/fend/uicom/uimessagebox.ui \
    $$PWD/src/fend/uicom/uipagewidget.ui \
    $$PWD/src/fend/uicom/uiprogresswidget.ui \
    $$PWD/src/fend/uicom/uiqosdialog.ui \
    $$PWD/src/fend/uilogin/uilogindialog.ui \
    $$PWD/src/fend/uimain/uibucketslistwidget.ui \
    $$PWD/src/fend/uimain/uicreatebucketdialog.ui \
    $$PWD/src/fend/uimain/uimain.ui \
    $$PWD/src/fend/uimain/uiobjectstablewidget.ui \
    $$PWD/src/fend/uimain/uitoolbarwidget.ui \
    $$PWD/src/fend/uimain/uibucketstablewidget.ui \
    $$PWD/src/fend/uitransfer/uidownload.ui \
    $$PWD/src/fend/uitransfer/uitransfer.ui \
    $$PWD/src/fend/uitransfer/uiupload.ui

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
