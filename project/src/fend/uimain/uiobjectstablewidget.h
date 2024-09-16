#ifndef UIOBJECTSTABLEWIDGET_H
#define UIOBJECTSTABLEWIDGET_H

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

private:
    Ui::UiObjectsTableWidget *ui;
};

#endif  // UIOBJECTSTABLEWIDGET_H
