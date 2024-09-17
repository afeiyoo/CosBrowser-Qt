#include "bucketswidget.h"

#include "src/bend/man/mancloud.h"
#include "src/middle/manglobal.h"
#include "ui_bucketswidget.h"

BucketsWidget::BucketsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::BucketsWidget) {
    ui->setupUi(this);
    ui->listView->setModel(MG->mCloud->model());
}

BucketsWidget::~BucketsWidget() { delete ui; }
