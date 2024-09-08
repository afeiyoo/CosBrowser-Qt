#include "ui_uipagewidget.h"
#include "uipagewidget.h"

UiPageWidget::UiPageWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UiPageWidget) { ui->setupUi(this); }

UiPageWidget::~UiPageWidget() { delete ui; }
