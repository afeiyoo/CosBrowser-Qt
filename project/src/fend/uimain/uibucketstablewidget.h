#ifndef UIBUCKETSTABLEWIDGET_H
#define UIBUCKETSTABLEWIDGET_H

#include <QWidget>

#include "src/middle/models/cloudmodels.h"

namespace Ui {
class UiBucketsTableWidget;
}

class UiBucketsTableWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiBucketsTableWidget(QWidget *parent = nullptr);
    ~UiBucketsTableWidget();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void onPageNumChanged(int start, int maxLen);
    void onBucketsSuccess(const QList<MyBucket> &buckets);

    void on_btnCreateBuckets_clicked();
    void onDelBucket();

    void on_btnRefresh_clicked();
private:
    Ui::UiBucketsTableWidget *ui;
};

#endif  // UIBUCKETSTABLEWIDGET_H
