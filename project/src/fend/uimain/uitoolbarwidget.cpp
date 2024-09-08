#include "uitoolbarwidget.h"

#include <QSignalMapper>

#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uitoolbarwidget.h"

UiToolBarWidget::UiToolBarWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiToolBarWidget) {
    ui->setupUi(this);
    //    QSignalMapper* mapper = new QSignalMapper(this);
    //    QList<QPushButton*> buttonList = findChildren<QPushButton*>();
    //    for(auto btn: buttonList){
    //        connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
    //        mapper->setMapping(btn, btn->text());
    //    }
    //    connect(mapper, SIGNAL(mapped(QString)), this, SIGNAL(buttonClicked(QString)));
}

UiToolBarWidget::~UiToolBarWidget() { delete ui; }

void UiToolBarWidget::on_btnQuit_clicked() {
    emit MG->mSignal->unLogin();  // 发送退出登录信号
}
