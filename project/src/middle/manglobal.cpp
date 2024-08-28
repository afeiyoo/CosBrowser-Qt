#include "manglobal.h"

#include <QApplication>

#include "manmodels.h"
#include "src/bend/gateway/gateway.h"
#include "src/bend/man/mancloud.h"
#include "src/bend/man/mandb.h"
#include "src/middle/signals/mansignals.h"
#include "src/plugins/manplugin.h"

Q_GLOBAL_STATIC(ManGlobal, ins)

ManGlobal::ManGlobal(QObject *parent) : QObject{parent} {
    mLog    = new LoggerProxy(this);
    mCloud  = new ManCloud(this);
    mDb     = new ManDB(this);
    mSignal = new ManSignals(this);
    mPlugin = new ManPlugin(this);
    mGate   = new GateWay(this);
}

ManGlobal::~ManGlobal() { qDebug("delete ManGlobal "); }

ManGlobal *ManGlobal::instance() { return ins(); }

void ManGlobal::init(int argc, char *argv[]) {
    mModels = new ManModels(this);

    FileHelper::mkPath(GLOBAL::PATH::TMP);
    FileHelper::mkPath(GLOBAL::PATH::LOG_DIR);

    mPlugin->installPlugins(argc, argv);

    // 1. 读取文件中的qss
    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");

    // 2. QApplication加载qss内容
    qApp->setStyleSheet(qssStr);

    mDb->init();
}
