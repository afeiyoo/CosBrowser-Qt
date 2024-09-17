#ifndef UIMAIN_H
#define UIMAIN_H

#include <QWidget>

namespace Ui {
class UiMain;
}

class UiMain : public QWidget {
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

private:
    Ui::UiMain *ui;
};

#endif  // UIMAIN_H
