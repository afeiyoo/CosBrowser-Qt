#include "uiobjectstablewidget.h"

#include <QFileDialog>
#include <QJsonObject>
#include <QMessageBox>

#include "src/bend/gateway/gateway.h"
#include "src/bend/man/mancloud.h"
#include "src/config/apis.h"
#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uiobjectstablewidget.h"

UiObjectsTableWidget::UiObjectsTableWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiObjectsTableWidget) {
    ui->setupUi(this);

    ui->btnBuckets->setProperty("style_button", "main");

    ui->tableView->setModel(MG->mModels->modelObjects());

    // 设置列宽度
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 120);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);  // 设置最后一列占满整个表

    // 隐藏垂直标题
    ui->tableView->verticalHeader()->setHidden(true);

    // 设置鼠标点击排序
    ui->tableView->setSortingEnabled(true);

    // 设置视图选择模式：单选，多选
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // 设置单元格不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 初始化翻页按钮
    ui->widgetPage->setMaxRowList(QList<int>() << 5 << 10 << 20);
    connect(ui->widgetPage, &UiPageWidget::pageNumChanged, this, &UiObjectsTableWidget::onPageNumChanged);

    connect(MG->mSignal, &ManSignals::objectsSuccess, this, &UiObjectsTableWidget::onObjectsSuccess);
    connect(ui->widgetBread, &UiBreadWidget::pathChanged, this, &UiObjectsTableWidget::onPathChanged);

    // 关联上传成功信号
    connect(MG->mSignal, &ManSignals::uploadSuccess, this, &UiObjectsTableWidget::onUploadSuccess);
    // 关联下载成功信号
    connect(MG->mSignal, &ManSignals::downloadSuccess, this, &UiObjectsTableWidget::onDownloadSuccess);
}

UiObjectsTableWidget::~UiObjectsTableWidget() { delete ui; }

void UiObjectsTableWidget::on_btnBuckets_clicked() { MG->mGate->send(API::BUCKETS::LIST); }

void UiObjectsTableWidget::on_tableView_doubleClicked(const QModelIndex &index) {
    MyObject obj = index.data(Qt::UserRole).value<MyObject>();

    if (obj.isDir()) {
        QJsonObject params;
        params["bucketName"] = MG->mCloud->currentBucketName();
        params["dir"]        = obj.key;

        MG->mGate->send(API::OBJECTS::LIST, params);
    }
}

void UiObjectsTableWidget::onObjectsSuccess(const QList<MyObject> &objects) {
    // 更新面包屑显示
    QString path = MG->mCloud->currentBucketName() + "/" + MG->mCloud->currentDir();

    ui->widgetBread->setPath(path);
    ui->widgetPage->setTotalRow(objects.size());
}

void UiObjectsTableWidget::onPathChanged(const QString &newPath) {
    // newPath = file-1300416378/test/bll
    // 需要将newPath转换为test/bll/
    QString key = newPath + "/";
    key         = key.mid(key.indexOf("/") + 1);

    QJsonObject params;
    params["bucketName"] = MG->mCloud->currentBucketName();
    params["dir"]        = key;

    MG->mGate->send(API::OBJECTS::LIST, params);
}

void UiObjectsTableWidget::onPageNumChanged(int start, int maxLen) {
    QStandardItemModel *model = MG->mModels->modelObjects();

    for (int i = 0; i < model->rowCount(); i++) {
        bool hidden = (i < start || (i >= start + maxLen));
        ui->tableView->setRowHidden(i, hidden);
    }
}

void UiObjectsTableWidget::on_btnRefresh_clicked() { onPathChanged(ui->widgetBread->currentPath()); }

void UiObjectsTableWidget::onUploadSuccess(const QString &jobId) {
    on_btnRefresh_clicked();

    showMessage(QString("上传文件"), QString("上传文件成功"));
}

void UiObjectsTableWidget::on_btnUpload_clicked() {
    static QString lastDir = "./";
    // 1. 获取本地文件
    QString   filePath = QFileDialog::getOpenFileName(this, QString("上传文件"), lastDir);
    QFileInfo info(filePath);
    if (info.isFile() && info.exists()) {
        QString jobId = QUuid::createUuid().toString();

        filePath    = filePath.replace("\\", "/");
        QString key = MG->mCloud->currentBucketName();

        QJsonObject params;
        params["jobId"]      = jobId;
        params["bucketName"] = MG->mCloud->currentBucketName();
        params["key"]        = MG->mCloud->currentDir() + info.fileName();
        params["localPath"]  = filePath;

        MG->mGate->send(API::OBJECTS::PUT, params);

        lastDir = info.dir().absolutePath();  // 更新路径

        emit MG->mSignal->startUpload(jobId, key, filePath);
    }
}

void UiObjectsTableWidget::on_btnDownload_clicked() {
    QModelIndex idx = ui->tableView->currentIndex();
    if (!idx.isValid()) {
        showMessage(QString("下载文件"), QString("请选择要下载的文件"));
        return;
    }
    MyObject obj = idx.data(Qt::UserRole).value<MyObject>();
    if (obj.isDir()) {
        showMessage(QString("下载文件"), QString("只能选择文件进行下载"));
        return;
    }
    QString        name    = idx.data().toString();
    static QString lastDir = "./";
    QString filePath = QFileDialog::getSaveFileName(this, QString("下载文件"), FileHelper::joinPath(lastDir, name));
    QFileInfo info(filePath);

    QString jobId = QUuid::createUuid().toString();
    QString key   = MG->mCloud->currentBucketName();
    filePath      = filePath.replace("\\", "/");

    QJsonObject params;
    params["jobId"]      = jobId;
    params["bucketName"] = MG->mCloud->currentBucketName();
    params["key"]        = MG->mCloud->currentDir() + name;
    params["localPath"]  = filePath;

    MG->mGate->send(API::OBJECTS::GET, params);

    lastDir = info.dir().absolutePath();  // 更新路径

    emit MG->mSignal->startDownload(jobId, key, filePath, obj.size);
}

void UiObjectsTableWidget::showMessage(const QString &title, const QString &info) {
    QMessageBox box(QMessageBox::Information, title, info, QMessageBox::Ok);
    box.setButtonText(QMessageBox::Ok, QString("确定"));
    box.exec();
}

void UiObjectsTableWidget::onDownloadSuccess(const QString &jobId) {
    showMessage(QString("下载文件"), QString("下载文件成功"));
}
