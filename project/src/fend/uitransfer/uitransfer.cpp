#include "uitransfer.h"

#include "ui_uitransfer.h"

UiTransfer::UiTransfer(QWidget *parent) : UiQosDialog(parent), ui(new Ui::UiTransfer) {
    ui->setupUi(body());
    setTitle(QString("传输列表"));
    setFixedSize(800, 450);
}

UiTransfer::~UiTransfer() { delete ui; }
