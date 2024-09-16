#include "uibucketslistwidget.h"

#include <QJsonObject>

#include "src/bend/gateway/gateway.h"
#include "src/config/apis.h"
#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "ui_uibucketslistwidget.h"

UiBucketsListWidget::UiBucketsListWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBucketsListWidget) {
    ui->setupUi(this);
    ui->listView->setModel(MG->mModels->modelBuckets());
}

UiBucketsListWidget::~UiBucketsListWidget() { delete ui; }

void UiBucketsListWidget::on_listView_doubleClicked(const QModelIndex &index) {
    QJsonObject params;
    params["bucketName"] = index.data().toString();
    params["dir"]        = "";

    MG->mGate->send(API::OBJECTS::LIST, params);
}
