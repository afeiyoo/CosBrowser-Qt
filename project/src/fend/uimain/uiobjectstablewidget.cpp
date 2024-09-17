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

    QMessageBox box(QMessageBox::Information, QString("上传文件"), QString("上传文件成功"), QMessageBox::Ok);
    box.setButtonText(QMessageBox::Ok, QString("确定"));
    box.exec();
}

void UiObjectsTableWidget::on_btnUpload_clicked() {
    static QString lastDir = "./";
    // 1. 获取本地文件
    QString   filePath = QFileDialog::getOpenFileName(this, QString("上传文件"), lastDir);
    QFileInfo info(filePath);
    if (info.isFile() && info.exists()) {
        QString jobId = QUuid::createUuid().toString();

        filePath = filePath.replace("\\", "/");

        QJsonObject params;
        params["jobId"]      = jobId;
        params["bucketName"] = MG->mCloud->currentBucketName();
        params["key"]        = MG->mCloud->currentDir() + info.fileName();
        params["localPath"]  = filePath;

        MG->mGate->send(API::OBJECTS::PUT, params);

        lastDir = info.dir().absolutePath();  // 更新路径
    }
}
