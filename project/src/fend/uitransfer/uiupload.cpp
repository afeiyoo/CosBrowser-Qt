#include "uiupload.h"

#include <QFileInfo>

#include "src/config/apis.h"
#include "src/fend/uicom/uiprogresswidget.h"
#include "src/fend/uidelegate/uitableitemdelegate.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uiupload.h"

UiUpload::UiUpload(QWidget *parent) : QWidget(parent), ui(new Ui::UiUpload) {
    ui->setupUi(this);
    initHeader();
    connect(MG->mSignal, &ManSignals::startUpload, this, &UiUpload::onStartUpload);
    connect(MG->mSignal, &ManSignals::uploadProcess, this, &UiUpload::onUploadProcess);
    connect(MG->mSignal, &ManSignals::uploadSuccess, this, &UiUpload::onUploadSuccess);
    connect(MG->mSignal, &ManSignals::error, this, &UiUpload::onError);

    ui->tableWidget->setItemDelegate(new UiTableItemDelegate(ui->tableWidget));
}

UiUpload::~UiUpload() { delete ui; }

void UiUpload::onStartUpload(const QString &jobId, const QString &key, const QString &localPath) {
    ui->tableWidget->insertRow(0);  // 在首行插入
    ui->tableWidget->setRowHeight(0, 40);

    QTableWidgetItem *item = new QTableWidgetItem(key);
    item->setData(Qt::UserRole, jobId);  // 可以通过jobId找到对应的行
    ui->tableWidget->setItem(0, 0, item);
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(localPath));

    QFileInfo         info(localPath);
    UiProgressWidget *bar = new UiProgressWidget();
    bar->setRange(0, info.size());
    ui->tableWidget->setCellWidget(0, 2, bar);
}

void UiUpload::onUploadProcess(const QString &jobId, qulonglong transferedSize, qulonglong totalSize) {
    UiProgressWidget *w = findTableWidgetItem(jobId);
    w->setValue(transferedSize);
}

void UiUpload::onUploadSuccess(const QString &jobId) {
    UiProgressWidget *w = findTableWidgetItem(jobId);
    w->setFinished(QString("上传成功"));
}

void UiUpload::onError(int api, const QString &msg, const QJsonValue &req) {
    if (api != API::OBJECTS::PUT) return;
    UiProgressWidget *w = findTableWidgetItem(req["jobId"].toString());
    w->setError(QString("上传失败"));
    w->setToolTip(msg);
}

UiProgressWidget *UiUpload::findTableWidgetItem(const QString &jobId) {
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        QTableWidgetItem *item   = ui->tableWidget->item(i, 0);
        QString           itemId = item->data(Qt::UserRole).toString();
        if (itemId == jobId) {
            return dynamic_cast<UiProgressWidget *>(ui->tableWidget->cellWidget(i, 2));
        }
    }
    return nullptr;
}

void UiUpload::initHeader() {
    QStringList headers;
    headers << QString("云端路径") << QString("本地路径") << QString("上传状态");
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(1);
}
