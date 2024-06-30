#include "toolbarwidget.h"
#include "ui_toolbarwidget.h"

ToolBarWidget::ToolBarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolBarWidget)
{
    ui->setupUi(this);
    connect(ui->btnQuit, &QPushButton::clicked, this, &ToolBarWidget::quitLogin);
}

ToolBarWidget::~ToolBarWidget()
{
    delete ui;
}


