#include "uibucketstablewidget.h"

#include <QAction>
#include <QJsonObject>
#include <QMessageBox>
#include <QStandardItemModel>

#include "src/bend/gateway/gateway.h"
#include "src/config/apis.h"
#include "src/fend/uidelegate/uibucketdelegate.h"
#include "src/fend/uimain/uicreatebucketdialog.h"
#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uibucketstablewidget.h"

UiBucketsTableWidget::UiBucketsTableWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBucketsTableWidget) {
    ui->setupUi(this);

    ui->tableView->setModel(MG->mModels->modelBuckets());
    // 为第1列（从0开始）指定代理
    // ui->tableView->setItemDelegateForColumn(1, new UiBucketDelegate());

    // 设置列宽度
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 120);
    // 设置最后一列占满整个表
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // 隐藏垂直标题
    ui->tableView->verticalHeader()->setHidden(true);

    // 设置鼠标点击排序
    ui->tableView->setSortingEnabled(true);

    // 设置视图选择行为：行，列，单元格
    // ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 设置视图选择模式：单选，多选
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // 设置单元格不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 初始化翻页按钮
    ui->widgetPage->setMaxRowList(QList<int>() << 2 << 5 << 10);
    connect(ui->widgetPage, &UiPageWidget::pageNumChanged, this, &UiBucketsTableWidget::onPageNumChanged);

    connect(MG->mSignal, &ManSignals::bucketsSuccess, this, &UiBucketsTableWidget::onBucketsSuccess);

    // 创建右键菜单
    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *delAction = new QAction(QString("删除桶"), this);
    connect(delAction, &QAction::triggered, this, &UiBucketsTableWidget::onDelBucket);
    ui->tableView->addAction(delAction);
}

UiBucketsTableWidget::~UiBucketsTableWidget() { delete ui; }

void UiBucketsTableWidget::on_tableView_doubleClicked(const QModelIndex &index) {
    if (index.column() == 0) {
        QJsonObject params;
        params["bucketName"] = index.data().toString();
        params["dir"]        = "";

        MG->mGate->send(API::OBJECTS::LIST, params);
    }
}

void UiBucketsTableWidget::onPageNumChanged(int start, int maxLen) {
    QStandardItemModel *model = MG->mModels->modelBuckets();

    for (int i = 0; i < model->rowCount(); i++) {
        bool hidden = (i < start || (i >= start + maxLen));
        ui->tableView->setRowHidden(i, hidden);
    }
}

void UiBucketsTableWidget::onBucketsSuccess(const QList<MyBucket> &buckets) {
    ui->widgetPage->setTotalRow(buckets.size());
}

void UiBucketsTableWidget::on_btnCreateBuckets_clicked() {
    UiCreateBucketDialog dialog(this);
    int                  ret = dialog.exec();
    if (ret == QDialog::Accepted) {
        MyBucket bucket = dialog.getBucket();
        if (bucket.isValid()) {
            QJsonObject params;
            params["bucketName"] = bucket.name;
            params["location"]   = bucket.location;

            MG->mGate->send(API::BUCKETS::PUT, params);
        }
    }
}

void UiBucketsTableWidget::onDelBucket() {
    QModelIndex idx = ui->tableView->currentIndex();
    if (idx.isValid()) {
        QString name = idx.data().toString();
        // int ret = QMessageBox::question(this, QString("删除桶"), QString("是否确认删除桶【%1】吗?").arg(name));
        // 修改按钮内容为中文
        QMessageBox box(QMessageBox::Question, QString("删除桶"), QString("是否确认删除桶【%1】吗?").arg(name),
                        QMessageBox::Yes | QMessageBox::No);
        box.setButtonText(QMessageBox::Yes, QString("删除"));
        box.setButtonText(QMessageBox::No, QString("取消"));
        int ret = box.exec();

        if (ret == QMessageBox::Yes) {
            QJsonObject params;
            params["bucketName"] = name;

            MG->mGate->send(API::BUCKETS::DEL, params);
        }
    }
}

void UiBucketsTableWidget::on_btnRefresh_clicked() { MG->mGate->send(API::BUCKETS::LIST); }
