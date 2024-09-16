#include "uibucketslistwidget.h"

#include <QJsonObject>

#include "src/bend/gateway/gateway.h"
#include "src/config/apis.h"
#include "src/middle/manglobal.h"
#include "src/middle/manmodels.h"
#include "src/middle/signals/mansignals.h"
#include "ui_uibucketslistwidget.h"

UiBucketsListWidget::UiBucketsListWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBucketsListWidget) {
    ui->setupUi(this);
    ui->listView->setModel(MG->mModels->modelBuckets());

    connect(MG->mSignal, &ManSignals::bucketsSuccess, this, &UiBucketsListWidget::onBucketsSuccess);
    connect(ui->lineEdit, &UiComboLine::itemSelected, this, &UiBucketsListWidget::showBucketObjects);
    connect(ui->lineEdit, &UiComboLine::textEdited, this, &UiBucketsListWidget::onTextEdited);
}

UiBucketsListWidget::~UiBucketsListWidget() { delete ui; }

void UiBucketsListWidget::on_listView_doubleClicked(const QModelIndex &index) {
    showBucketObjects(index.data().toString());
}

void UiBucketsListWidget::onBucketsSuccess(const QList<MyBucket> &buckets) {
    QStringList words;
    for (const auto &bucket : qAsConst(buckets)) {
        words.append(bucket.name);
    }
    ui->lineEdit->setWords(words);
}

void UiBucketsListWidget::showBucketObjects(const QString &bucketName) {
    QJsonObject params;
    params["bucketName"] = bucketName;
    params["dir"]        = "";

    MG->mGate->send(API::OBJECTS::LIST, params);
}

void UiBucketsListWidget::onTextEdited(const QString &text) {
    QStandardItemModel *model = MG->mModels->modelBuckets();
    for (int i = 0; i < model->rowCount(); ++i) {
        bool hidden = !(model->index(i, 0).data().toString().contains(text));
        ui->listView->setRowHidden(i, hidden);
    }
}
