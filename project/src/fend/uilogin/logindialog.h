﻿#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "src/fend/uicom/qosdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

class LoginDialog : public QosDialog {
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void updateLoginInfo();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void onBtnLoginClicked();
    void onLoginSucceed();
    void onLoginError(int api, const QString &msg);

private:
    Ui::LoginDialog *ui;
    QPoint           m_start;
};
#endif  // LOGINDIALOG_H
