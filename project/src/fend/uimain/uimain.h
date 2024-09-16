#ifndef UIMAIN_H
#define UIMAIN_H

#include "src/fend/uicom/uiqosdialog.h"
#include "src/middle/models/cloudmodels.h"

namespace Ui {
class UiMain;
}

class UiMain : public UiQosDialog {
    Q_OBJECT

public:
    explicit UiMain(QWidget *parent = nullptr);
    ~UiMain();

private slots:
    void onButtonClicked(const QString &text);
    void onUpload();
    void onDownload();
    void onRefresh();
    void onUnLogin();

    // 获取存储桶列表成功
    void onBucketsSuccess(const QList<MyBucket> &buckets);

    // 获取对象列表成功
    void onObjectsSuccess(const QList<MyObject> &objects);

private:
    Ui::UiMain *ui;
};

#endif  // UIMAIN_H
