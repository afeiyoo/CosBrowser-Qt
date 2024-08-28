#include "uimain.h"

#include <QDebug>

#include "src/middle/signals/mansignals.h"
#include "ui_uimain.h"

UiMain::UiMain(QWidget *parent) : QWidget(parent), ui(new Ui::UiMain) {
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);

    // connect(ui->widgetToolBar, &ToolBarWidget::buttonClicked, this, &UiMain::onButtonClicked);
    connect(MS, &ManSignals::loginSuccess, this, &UiMain::show);
    connect(MS, &ManSignals::unLogin, this, &UiMain::onUnLogin);
}

UiMain::~UiMain() { delete ui; }

void UiMain::onButtonClicked(const QString &text) {
    qDebug() << text;
    if (text == QString("上传")) {
        onUpload();
    } else if (text == QString("退出登录")) {
        onUnLogin();
    }
}

void UiMain::onUpload() { qDebug() << "onUpload"; }

void UiMain::onDownload() { qDebug() << "onDownload"; }

void UiMain::onRefresh() { qDebug() << "onRefresh"; }

void UiMain::onUnLogin() { hide(); }
