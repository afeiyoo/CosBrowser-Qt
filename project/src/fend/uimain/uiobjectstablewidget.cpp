#include "uiobjectstablewidget.h"

#include <QJsonObject>

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

    connect(MG->mSignal, &ManSignals::objectsSuccess, this, &UiObjectsTableWidget::onObjectsSuccess);
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
}
