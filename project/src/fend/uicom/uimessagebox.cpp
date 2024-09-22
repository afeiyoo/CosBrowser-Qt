#include "uimessagebox.h"

#include <QPushButton>

#include "src/fend/uicom/uipushbutton.h"
#include "ui_uimessagebox.h"

UiMessageBox::UiMessageBox(QWidget *parent) : UiQosDialog(parent), ui(new Ui::UiMessageBox) {
    ui->setupUi(body());
    resize(500, 350);
}

UiMessageBox::~UiMessageBox() { delete ui; }

QString UiMessageBox::showMessage(const QString &title, const QString &text, const QStringList &btnTextList) {
    m_text = "";
    setTitle(title);
    ui->label->setText(text);
    createBtns(btnTextList);
    exec();
    return m_text;
}

void UiMessageBox::createBtns(const QStringList &textList) {
    for (const auto &text : qAsConst(textList)) {
        UiPushButton *btn = new UiPushButton(this);
        btn->setText(text);
        connect(btn, &QPushButton::clicked, [=]() {
            m_text = text;
            accept();
        });
        ui->horizontalLayout->addWidget(btn);
    }
}
