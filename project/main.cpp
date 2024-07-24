#include "src/bend/dao/daobuckets.h"
#include "src/fend/uimain/uimain.h"
#include "src/helper/filehelper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DaoBuckets buckets;
    buckets.bucketsFromMock(":/static/testing/buckets2.json");

    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");
    a.setStyleSheet(qssStr);

    UiMain w;
    w.showLoginDialog();


    return a.exec();
}
