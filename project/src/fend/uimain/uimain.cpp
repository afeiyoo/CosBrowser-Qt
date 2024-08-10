#include "uimain.h"

#include <QDebug>

#include "src/fend/uilogin/logindialog.h"
#include "ui_uimain.h"

UiMain::UiMain(QWidget *parent) : QWidget(parent), ui(new Ui::UiMain) {
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);

    connect(ui->widgetToolBar, &ToolBarWidget::buttonClicked, this, &UiMain::onButtonClicked);
}

UiMain::~UiMain() {
    delete ui;
    if (m_loginDialog) delete m_loginDialog;
}

void UiMain::showLoginDialog() {
    if (m_loginDialog == nullptr) {
        m_loginDialog = new LoginDialog();
        m_loginDialog->updateLoginInfo();  // 更新缓存
        connect(m_loginDialog, &LoginDialog::accepted, this, &UiMain::show);
    }
    m_loginDialog->show();
    this->setVisible(false);  // 主界面隐藏
}

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

void UiMain::onUnLogin() { showLoginDialog(); }
