#ifndef UIPAGEWIDGET_H
#define UIPAGEWIDGET_H

#include <QWidget>

namespace Ui {
class UiPageWidget;
}

class UiPageWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiPageWidget(QWidget *parent = nullptr);
    ~UiPageWidget();

private:
    Ui::UiPageWidget *ui;
};

#endif  // UIPAGEWIDGET_H
