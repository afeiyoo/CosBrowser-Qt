#include "manplugin.h"

#include "src/bend/dao/clouds/daocloudsmock.h"
#include "src/bend/dao/configs/versioncmd.h"
#include "src/bend/dao/configs/versionjson.h"
#include "src/bend/dao/logs/loggerqdebug.h"
#include "src/config/globals.h"
#include "src/config/loggerproxy.h"
#include "src/middle/manglobal.h"

ManPlugin::ManPlugin(QObject *parent) : QObject{parent} {}

ManPlugin::~ManPlugin() {
    delete m_clouds;
    delete m_version;
    qDebug("delete ManPlugin ");
}

void ManPlugin::installPlugins(int argc, char *argv[]) {
    // 如果输入命令行，则命令行参数优先级最高，否则直接加载配置文件中的配置信息
    VersionCmd version(argc, argv);
    if (version.isValid()) {
        m_version = new VersionCmd(argc, argv);
    } else {
        m_version = new VersionJson(GLOBAL::VERSION::JSON_PATH);
    }
    m_version->setVersion();

    MG->mLog->setLogger(new LoggerQDebug());

    if (m_version->major() == GLOBAL::VERSION::MAJOR_BUSINESS) {
        m_clouds = new DaoCloudsMock(":/static/testing/business.json");
    } else {
        m_clouds = new DaoCloudsMock(":/static/testing/custom.json");
    }
}

DaoClouds *ManPlugin::clouds() const { return m_clouds; }
