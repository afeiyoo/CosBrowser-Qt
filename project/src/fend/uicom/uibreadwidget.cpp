#include "uibreadwidget.h"

#include "ui_uibreadwidget.h"

UiBreadWidget::UiBreadWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiBreadWidget) { ui->setupUi(this); }

UiBreadWidget::~UiBreadWidget() { delete ui; }
