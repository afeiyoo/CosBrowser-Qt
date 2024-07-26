#include "objectswidget.h"
#include "src/bend/man/manbuckets.h"
#include "src/fend/uidelegate/bucketdelegate.h"
#include "ui_objectswidget.h"

ObjectsWidget::ObjectsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->tableView->setModel(MB->model());
    // 为第1列（从0开始）指定代理
    ui->tableView->setItemDelegateForColumn(1, new BucketDelegate());
}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}
