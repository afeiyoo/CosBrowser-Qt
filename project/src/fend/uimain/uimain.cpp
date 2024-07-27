#include "uimain.h"
#include "src/fend/uilogin/logindialog.h"
#include "ui_uimain.h"

UiMain::UiMain(QWidget *parent) : QWidget(parent), ui(new Ui::UiMain) {
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);
}

UiMain::~UiMain() {
    delete ui;
    if (m_loginDialog)
        delete m_loginDialog;
}

void UiMain::showLoginDialog() {
    if (m_loginDialog == nullptr) {
        m_loginDialog = new LoginDialog();
        m_loginDialog->updateLoginInfo();   // 更新缓存
        connect(m_loginDialog, &LoginDialog::accepted, this, &UiMain::show);
        connect(ui->widgetToolBar, &ToolBarWidget::quitLogin, this, &UiMain::showLoginDialog);
    }
    m_loginDialog->show();
    this->setVisible(false); // 主界面隐藏
}
