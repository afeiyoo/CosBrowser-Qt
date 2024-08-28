#include "bucketswidget.h"

#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "ui_bucketswidget.h"

BucketsWidget::BucketsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::BucketsWidget) {
    ui->setupUi(this);
    ui->listView->setModel(MG->mModels->model());
}

BucketsWidget::~BucketsWidget() { delete ui; }
