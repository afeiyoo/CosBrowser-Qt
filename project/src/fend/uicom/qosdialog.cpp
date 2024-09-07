#include "qosdialog.h"

#include "src/config/globals.h"
#include "ui_basedialog.h"
#include "ui_qosdialog.h"

QosDialog::QosDialog(QWidget *parent) : BaseDialog(parent), ui(new Ui::QosDialog) {
    ui->setupUi(body());  // 加入父窗口的对象树
    setLogo(GLOBAL::PATH::LOGO_PATH);
    setTitle(QString("Qos Browser"));
    m_ui->labelLogo->setFixedSize(32, 24);
    m_ui->labelTitle->setProperty("style", "h4");
}

QosDialog::~QosDialog() { delete ui; }
