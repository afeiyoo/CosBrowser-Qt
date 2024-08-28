#include "objectswidget.h"

#include "src/bend/man/mancloud.h"
#include "src/fend/uidelegate/bucketdelegate.h"
#include "src/middle/manglobal.h"
#include "ui_objectswidget.h"

ObjectsWidget::ObjectsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ObjectsWidget) {
    ui->setupUi(this);
    ui->tableView->setModel(MG->mCloud->model());
    // 为第1列（从0开始）指定代理
    ui->tableView->setItemDelegateForColumn(1, new BucketDelegate());

    // 设置标题内容
    QStandardItemModel *model = MG->mCloud->model();
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

ObjectsWidget::~ObjectsWidget() { delete ui; }
