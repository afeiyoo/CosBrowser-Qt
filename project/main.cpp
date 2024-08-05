#include "src/bend/man/mancloud.h"
#include "src/bend/man/mandb.h"
#include "src/fend/uimain/uimain.h"
#include "src/helper/filehelper.h"
#include "src/plugins/manplugin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MP->installPlugins(argc, argv);
    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");
    a.setStyleSheet(qssStr);

    MDB->init();

    UiMain w;
    w.showLoginDialog();

    MC->setBuckets();

    return a.exec();
}
