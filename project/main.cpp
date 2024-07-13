#include "src/fend/uimain/uimain.h"
#include "src/helper/filehelper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString qssStr = FileHelper::readAllTxt("F:/300_Study/303_Qt/01_CosBrowser/Code/COSBrowser/project/static/qss/default.qss");
    a.setStyleSheet(qssStr);

    UiMain w;
    w.showLoginDialog();


    return a.exec();
}
