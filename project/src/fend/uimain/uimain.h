#ifndef UIMAIN_H
#define UIMAIN_H

#include "src/fend/uicom/uiqosdialog.h"
#include "src/fend/uitransfer/uitransfer.h"
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

    // 显示传输窗口
    void showTransfer();

    void onError(int api, const QString &msg, const QJsonValue &req);

private:
    Ui::UiMain *ui;
    UiTransfer *m_transfer = nullptr;
};

#endif  // UIMAIN_H
