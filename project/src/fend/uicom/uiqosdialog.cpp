#include "uiqosdialog.h"

#include "src/config/globals.h"
#include "ui_uibasedialog.h"
#include "ui_uiqosdialog.h"

UiQosDialog::UiQosDialog(QWidget *parent) : UiBaseDialog(parent), ui(new Ui::UiQosDialog) {
    ui->setupUi(body());  // 加入父窗口的对象树
    setLogo(GLOBAL::PATH::LOGO_PATH);
    setTitle(QString("Qos Browser"));
    m_ui->labelLogo->setFixedSize(32, 24);  // 要使用父窗口的ui对象，需要引入父窗口的ui头文件
    m_ui->labelTitle->setProperty("style_font", "h4");
}

UiQosDialog::~UiQosDialog() { delete ui; }
