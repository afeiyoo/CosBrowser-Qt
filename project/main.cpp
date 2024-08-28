#include <QApplication>

#include "src/bend/man/mancloud.h"
#include "src/bend/man/mandb.h"
#include "src/config/loggerproxy.h"
#include "src/fend/uilogin/logindialog.h"
#include "src/fend/uimain/uimain.h"
#include "src/helper/filehelper.h"
#include "src/plugins/manplugin.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MP->installPlugins(argc, argv);

    // 1. 读取文件中的qss
    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");
    // 2. QApplication加载qss内容
    a.setStyleSheet(qssStr);

    MDB->init();
    MC->setBuckets();

    mInfo(GLOBAL::PATH::LOG_DIR);
    mInfo(QString("主界面程序启动"));

    UiMain      w;
    LoginDialog login;

    login.show();

    return a.exec();
}
