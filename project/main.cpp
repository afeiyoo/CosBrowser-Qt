#include "src/fend/uimain/uimain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiMain w;
    w.showLoginDialog();


    return a.exec();
}
