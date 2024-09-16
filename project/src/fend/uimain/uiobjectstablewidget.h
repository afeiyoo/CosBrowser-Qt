#ifndef UIOBJECTSTABLEWIDGET_H
#define UIOBJECTSTABLEWIDGET_H

#include <QWidget>

#include "src/middle/models/cloudmodels.h"

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

    void onPathChanged(const QString &newPath);

    void onPageNumChanged(int start, int maxLen);

private:
    Ui::UiObjectsTableWidget *ui;
};

#endif  // UIOBJECTSTABLEWIDGET_H
