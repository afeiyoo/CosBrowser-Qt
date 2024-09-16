#ifndef UIBUCKETSTABLEWIDGET_H
#define UIBUCKETSTABLEWIDGET_H

#include <QWidget>

namespace Ui {
class UiBucketsTableWidget;
}

class UiBucketsTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiBucketsTableWidget(QWidget *parent = nullptr);
    ~UiBucketsTableWidget();

private:
    Ui::UiBucketsTableWidget *ui;
};

#endif // UIBUCKETSTABLEWIDGET_H
