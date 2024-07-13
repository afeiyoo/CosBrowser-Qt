#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialog) {
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);

    // QPixmap pixmap(
    //     "F:/300_Study/303_Qt/01_CosBrowser/Code/COSBrowser/project/qt.png");
    // ui->labelLogo->setPixmap(pixmap.scaled(ui->labelLogo->size()));

    ui->labelTitle->setProperty("style", "h3");
    ui->labelSecretId->setProperty("style", "h4");
    ui->labelSecretKey->setProperty("style", "h4");
    ui->labelRemark->setProperty("style", "h4");
    ui->btnClose->setProperty("style", "h4");
    ui->btnLogin->setProperty("style", "h4");

    ui->lineSecretKey->installEventFilter(this);    // 对lineSecretKey安装事件过滤器
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

bool LoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    // watched表示需要关注的控件对象 event表示传递给事件对象的事件
    if(watched == ui->lineSecretKey){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->modifiers() == Qt::ControlModifier){
                if(keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
                    return true;    // true表示事件已被处理，不再往下传递，false表示继续传递到子控件
            }
        }
    }
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
