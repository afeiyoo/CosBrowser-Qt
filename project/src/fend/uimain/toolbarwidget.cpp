#include "toolbarwidget.h"

#include <QSignalMapper>

#include "ui_toolbarwidget.h"

ToolBarWidget::ToolBarWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ToolBarWidget) {
    ui->setupUi(this);
    QSignalMapper       *mapper     = new QSignalMapper(this);
    QList<QPushButton *> buttonList = findChildren<QPushButton *>();

    for (auto btn : buttonList) {
        connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(btn, btn->text());
    }

    connect(mapper, SIGNAL(mapped(QString)), this, SIGNAL(buttonClicked(QString)));
}

ToolBarWidget::~ToolBarWidget() { delete ui; }
