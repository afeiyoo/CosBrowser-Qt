#include "uibucketstablewidget.h"

#include <QStandardItemModel>

#include "src/fend/uidelegate/uibucketdelegate.h"
#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "ui_uibucketstablewidget.h"

UiBucketsTableWidget::UiBucketsTableWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBucketsTableWidget) {
    ui->setupUi(this);

    ui->tableView->setModel(MG->mModels->model());
    // 为第1列（从0开始）指定代理
    ui->tableView->setItemDelegateForColumn(1, new UiBucketDelegate());

    // 设置标题内容
    QStandardItemModel *model = MG->mModels->model();
    QStringList         labels;
    labels << QString("桶名称") << QString("地区") << QString("创建时间");
    model->setColumnCount(labels.size());
    model->setHorizontalHeaderLabels(labels);

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
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 设置视图选择模式：单选，多选
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

UiBucketsTableWidget::~UiBucketsTableWidget() { delete ui; }
