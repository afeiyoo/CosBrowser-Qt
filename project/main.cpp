#include "src/bend/man/manbuckets.h"
#include "src/bend/man/mandb.h"
#include "src/fend/uimain/uimain.h"
#include "src/helper/filehelper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");
    a.setStyleSheet(qssStr);

    MDB->init();

    UiMain w;
    w.showLoginDialog();

    MB->setBuckets();

    return a.exec();
}
