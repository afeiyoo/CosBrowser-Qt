#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialog) {
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);

    QPixmap pixmap(
        "F:/300_Study/303_Qt/01_CosBrowser/Code/COSBrowser/project/qt.png");
    ui->labelLogo->setPixmap(pixmap.scaled(ui->labelLogo->size()));
}

LoginDialog::~LoginDialog() { delete ui; }

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_start = event->pos(); // 相对于父控件坐标原点的位置
    }
    QDialog::mousePressEvent(event);
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        QPoint targetPos = event->pos() - m_start + pos();
        this->move(targetPos);
    }
    QDialog::mouseMoveEvent(event);
}

void LoginDialog::on_btnLogin_clicked() {
    // 登录信息验证
    if (ui->lineSecretId->text().trimmed() == "zhangsan" &&
        ui->lineSecretKey->text().trimmed() == "123") {
        accept();
    } else {
        QMessageBox::warning(
            this, QString::fromLocal8Bit("登录失败"),
            QString::fromLocal8Bit("请检查SecretId或SecretKey是否正确"));
    }
}

void LoginDialog::on_btnClose_clicked() { reject(); }
