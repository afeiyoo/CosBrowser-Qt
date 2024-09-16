#ifndef UIOBJECTSTABLEWIDGET_H
#define UIOBJECTSTABLEWIDGET_H

#include "src/middle/models/cloudmodels.h"
#include <QWidget>

namespace Ui {
class UiObjectsTableWidget;
}

class UiObjectsTableWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiObjectsTableWidget(QWidget *parent = nullptr);
    ~UiObjectsTableWidget();

private slots:
    void on_btnBuckets_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    // 获取对象列表成功
    void onObjectsSuccess(const QList<MyObject> &objects);

private:
    Ui::UiObjectsTableWidget *ui;
};

#endif  // UIOBJECTSTABLEWIDGET_H
