#include "basedialog.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QPushButton>

#include "ui_basedialog.h"

BaseDialog::BaseDialog(QWidget *parent) : QDialog(parent), m_ui(new Ui::BaseDialog) {
    m_ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);

    setLogo(":/static/imgs/qtlogo.png");
    addCloseButton(":/static/imgs/Close-1.png", ":/static/imgs/Close-2.png");
    setAllButtonSize();
    m_ui->labelLogo->setFixedSize(28, 28);
}

BaseDialog::~BaseDialog() { delete m_ui; }

void BaseDialog::setTitle(const QString &title) { m_ui->labelTitle->setText(title); }

void BaseDialog::setLogo(const QString &path) {
    m_ui->labelLogo->setStyleSheet(QString("border-image: url(\"%1\");").arg(path));
}

void BaseDialog::addMinButton(const QString &path, const QString &hoverPath) {
    QPushButton *btn = addButton(path, hoverPath);
    connect(btn, &QPushButton::clicked, this, &BaseDialog::showMinimized);
}

void BaseDialog::addMaxButton(const QString &maxPath, const QString &maxPathHover, const QString &normalPath,
                              const QString &normalPathHover) {
    QPushButton *btn = addButton(maxPath, maxPathHover);

    auto funcImg = [=]() {
        isMaximized() ? setButtonImage(btn, normalPath, normalPathHover) : setButtonImage(btn, maxPath, maxPathHover);
    };
    auto funcShow = [=]() {
        isMaximized() ? showNormal() : showMaximized();
        funcImg();
    };

    connect(btn, &QPushButton::clicked, this, funcShow);
    funcImg();
}

QPushButton *BaseDialog::addButton(const QString &path, const QString &hoverPath) {
    QPushButton *btn = new QPushButton;
    btn->setFixedSize(m_sz, m_sz);
    setButtonImage(btn, path, hoverPath);
    addWidget(btn);
    return btn;
}

void BaseDialog::setButtonImage(QPushButton *btn, const QString &path, const QString &hoverPath) {
    btn->setStyleSheet(QString("QPushButton{border-image: url(\"%1\");}"
                               "QPushButton:hover{border-image: url(\"%2\");}")
                           .arg(path, hoverPath));
}

void BaseDialog::setAllButtonSize(int w) {
    QList<QPushButton *> btnList = m_ui->frameTitle->findChildren<QPushButton *>();
    for (auto *btn : btnList) {
        btn->setFixedSize(w, w);
    }
    m_sz = w;
}

void BaseDialog::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_start = event->pos();  // 相对于父控件坐标原点的位置
    }
    QDialog::mousePressEvent(event);
}

void BaseDialog::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        QPoint targetPos = event->pos() - m_start + pos();
        this->move(targetPos);
    }
    QDialog::mouseMoveEvent(event);
}

QWidget *BaseDialog::body() { return m_ui->widgetBody; }

void BaseDialog::addCloseButton(const QString &path, const QString &hoverPath) {
    setButtonImage(m_ui->btnClose, path, hoverPath);
    m_ui->horizontalLayout->addWidget(m_ui->btnClose);
    connect(m_ui->btnClose, &QPushButton::clicked, this, &BaseDialog::reject);
}

void BaseDialog::addWidget(QWidget *w) {
    int i = m_ui->horizontalLayout->indexOf(m_ui->btnClose);
    m_ui->horizontalLayout->insertWidget(i, w);
}
