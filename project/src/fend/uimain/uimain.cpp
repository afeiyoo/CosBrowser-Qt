#include "uimain.h"

#include <QDebug>

#include "src/config/globals.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uimain.h"

UiMain::UiMain(QWidget *parent) : UiQosDialog(parent), ui(new Ui::UiMain) {
    ui->setupUi(body());
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);

    addMinButton(GLOBAL::PATH::MIN_PATH, GLOBAL::PATH::MIN_HOVER_PATH);
    addMaxButton(GLOBAL::PATH::MAX_PATH, GLOBAL::PATH::MAX_HOVER_PATH, GLOBAL::PATH::NORMAL_PATH,
                 GLOBAL::PATH::NORMAL_HOVER_PATH);
    setTitle(QString("Qos Browser"));
    resize(1080, 640);
    setKeyDisabled();  // 禁用esc或回车，导致窗口关闭

    // connect(ui->widgetToolBar, &ToolBarWidget::buttonClicked, this, &UiMain::onButtonClicked);
    connect(MG->mSignal, &ManSignals::loginSuccess, this, &UiMain::show);
    connect(MG->mSignal, &ManSignals::unLogin, this, &UiMain::onUnLogin);
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
