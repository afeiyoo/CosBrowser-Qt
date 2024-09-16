#ifndef UIBUCKETSLISTWIDGET_H
#define UIBUCKETSLISTWIDGET_H

#include <QWidget>

#include "src/middle/models/cloudmodels.h"

namespace Ui {
class UiBucketsListWidget;
}

class UiBucketsListWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiBucketsListWidget(QWidget *parent = nullptr);
    ~UiBucketsListWidget();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);
    void onBucketsSuccess(const QList<MyBucket> &buckets);
    void showBucketObjects(const QString &bucketName);

private:
    Ui::UiBucketsListWidget *ui;
};

#endif  // UIBUCKETSLISTWIDGET_H
