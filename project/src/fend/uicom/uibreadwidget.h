#ifndef UIBREADWIDGET_H
#define UIBREADWIDGET_H

#include <QWidget>

namespace Ui {
class UiBreadWidget;
}

class UiBreadWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiBreadWidget(QWidget *parent = nullptr);
    ~UiBreadWidget();

private:
    Ui::UiBreadWidget *ui;
};

#endif  // UIBREADWIDGET_H
