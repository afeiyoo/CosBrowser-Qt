#ifndef UIBUCKETSLISTWIDGET_H
#define UIBUCKETSLISTWIDGET_H

#include <QWidget>

namespace Ui {
class UiBucketsListWidget;
}

class UiBucketsListWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiBucketsListWidget(QWidget *parent = nullptr);
    ~UiBucketsListWidget();

private:
    Ui::UiBucketsListWidget *ui;
};

#endif  // UIBUCKETSLISTWIDGET_H
