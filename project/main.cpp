#include <QApplication>

#include "src/fend/uilogin/logindialog.h"
#include "src/fend/uimain/uimain.h"
#include "src/middle/manglobal.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MG->init(argc, argv);

    UiMain      w;
    LoginDialog login;

    login.show();

    return a.exec();
}
