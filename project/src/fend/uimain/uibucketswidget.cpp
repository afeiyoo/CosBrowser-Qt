#include "uibucketswidget.h"

#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "ui_uibucketswidget.h"

UiBucketsWidget::UiBucketsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBucketsWidget) {
    ui->setupUi(this);
    ui->listView->setModel(MG->mModels->model());
}

UiBucketsWidget::~UiBucketsWidget() { delete ui; }
