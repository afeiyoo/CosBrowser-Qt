#include "uibucketslistwidget.h"

#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "ui_uibucketslistwidget.h"

UiBucketsListWidget::UiBucketsListWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBucketsListWidget) {
    ui->setupUi(this);
    ui->listView->setModel(MG->mModels->model());
}

UiBucketsListWidget::~UiBucketsListWidget() { delete ui; }
