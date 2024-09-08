#ifndef UIOBJECTSWIDGET_H
#define UIOBJECTSWIDGET_H

#include <QWidget>

namespace Ui {
class UiObjectsWidget;
}

class UiObjectsWidget : public QWidget {
    Q_OBJECT

public:
    explicit UiObjectsWidget(QWidget *parent = nullptr);
    ~UiObjectsWidget();

private:
    Ui::UiObjectsWidget *ui;
};

#endif  // UIOBJECTSWIDGET_H
