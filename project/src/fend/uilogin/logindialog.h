﻿#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_btnLogin_clicked();

    void on_btnClose_clicked();

private:
    Ui::LoginDialog *ui;
};
#endif // LOGINDIALOG_H
