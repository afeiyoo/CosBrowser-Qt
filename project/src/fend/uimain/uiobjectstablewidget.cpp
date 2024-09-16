#include "uiobjectstablewidget.h"

#include "ui_uiobjectstablewidget.h"

UiObjectsTableWidget::UiObjectsTableWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiObjectsTableWidget) {
    ui->setupUi(this);
}

UiObjectsTableWidget::~UiObjectsTableWidget() { delete ui; }
