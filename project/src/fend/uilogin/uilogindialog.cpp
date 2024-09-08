#include "uilogindialog.h"

#include <qjsonobject.h>

#include <QCompleter>
#include <QKeyEvent>
#include <QMessageBox>

#include "src/bend/gateway/gateway.h"
#include "src/bend/man/mandb.h"
#include "src/config/apis.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uilogindialog.h"

UiLoginDialog::UiLoginDialog(QWidget *parent) : UiQosDialog(parent), ui(new Ui::UiLoginDialog) {
    ui->setupUi(body());

    setTitle(QString("登录"));

    ui->lineSecretKey->installEventFilter(this);  // 对lineSecretKey安装事件过滤器

    ui->labelSecretId->setProperty("style", "h5");
    ui->labelLoginName->setProperty("style", "h5");
    ui->labelSecretKey->setProperty("style", "h5");
    ui->labelRemark->setProperty("style", "h5");
    ui->btnLogin->setProperty("style", "h5");

    connect(MG->mSignal, &ManSignals::loginSuccess, this, &UiLoginDialog::onLoginSucceed);
    connect(MG->mSignal, &ManSignals::unLogin, this, &UiLoginDialog::show);
    connect(MG->mSignal, &ManSignals::error, this, &UiLoginDialog::onLoginError);
    connect(ui->btnLogin, &QPushButton::clicked, this, &UiLoginDialog::onBtnLoginClicked);
    updateLoginInfo();
}

UiLoginDialog::~UiLoginDialog() { delete ui; }

void UiLoginDialog::updateLoginInfo() {
    QStringList words     = MG->mDb->loginNameList();
    QCompleter *completer = new QCompleter(words);
    ui->lineLoginName->setCompleter(completer);

    connect(completer, static_cast<void (QCompleter::*)(const QString &)>(&QCompleter::activated),
            [&](const QString &name) {
                LoginInfo info = MG->mDb->loginInfoByName(name);
                ui->lineSecretId->setText(info.secret_id);
                ui->lineSecretKey->setText(info.secret_key);
                ui->lineRemark->setText(info.remark);
                ui->checkSaveSection->setChecked(true);
            });
}

bool UiLoginDialog::eventFilter(QObject *watched, QEvent *event) {
    // watched表示需要关注的控件对象 event表示传递给事件对象的事件
    if (watched == ui->lineSecretKey) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->modifiers() == Qt::ControlModifier) {
                if (keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
                    return true;  // true表示事件已被处理，不再往下传递，false表示继续传递到子控件
            }
        }
    }
    return QDialog::eventFilter(watched, event);
}

void UiLoginDialog::onBtnLoginClicked() {
    // 登录信息验证
    // if (ui->lineSecretId->text().trimmed() == "zhangsan" && ui->lineSecretKey->text().trimmed() == "123") {
    //     accept();
    //     if (ui->checkSaveSection->isChecked()) {
    //         // 保存登录信息
    //         MDB->saveLoginInfo(ui->lineLoginName->text(), ui->lineSecretId->text(), ui->lineSecretKey->text(),
    //                            ui->lineRemark->text());
    //     } else {
    //         // 删除登录信息
    //         MDB->removeLoginInfo(ui->lineSecretId->text());
    //     }
    //     updateLoginInfo();  // 更新缓存
    // } else {
    //     QMessageBox::warning(this, QString::fromUtf8("登录失败"),
    //                          QString::fromUtf8("请检查SecretId或SecretKey是否正确"));
    // }
    QJsonObject params;
    params["secretId"]  = ui->lineSecretId->text().trimmed();
    params["secretKey"] = ui->lineSecretKey->text().trimmed();
    MG->mGate->send(API::LOGIN::NORMAL, params);
}

void UiLoginDialog::onLoginSucceed() {
    accept();
    if (ui->checkSaveSection->isChecked()) {
        // 保存登录信息
        MG->mDb->saveLoginInfo(ui->lineLoginName->text(), ui->lineSecretId->text(), ui->lineSecretKey->text(),
                               ui->lineRemark->text());
        updateLoginInfo();
    } else {
        // 删除登录信息
        MG->mDb->removeLoginInfo(ui->lineSecretId->text());
    }
}

void UiLoginDialog::onLoginError(int api, const QString &msg) {
    if (api != API::LOGIN::NORMAL) return;
    QMessageBox::warning(this, QString("登录失败"), QString("登录失败：%1").arg(msg));
}
