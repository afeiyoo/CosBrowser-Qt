#include "uicomboline.h"

#include <QCompleter>

#include "src/fend/uidelegate/uitableitemdelegate.h"

UiComboLine::UiComboLine(QWidget *parent) : QLineEdit(parent) { UiComboLine(QStringList(), parent); }

UiComboLine::UiComboLine(const QStringList &words, QWidget *parent) : QLineEdit(parent) { setWords(words); }

void UiComboLine::setWords(const QStringList &words) {
    QCompleter *com = new QCompleter(words, this);
    // 取消下拉框的滚动条
    QAbstractItemView *view = com->popup();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setItemDelegate(new UiTableItemDelegate(view));
    view->setCursor(Qt::PointingHandCursor);
    connect(com, QOverload<const QString &>::of(&QCompleter::activated),
            [=](const QString &text) { emit itemSelected(text); });

    setCompleter(com);                      // 设置自动填充
    com->setFilterMode(Qt::MatchContains);  // 设置匹配方式
}

void UiComboLine::setWords(const QList<int> words) {
    QStringList strs;
    for (int i : words) {
        strs << QString::number(i);
    }
    setWords(strs);
}

void UiComboLine::setWords(int start, int len) {
    QStringList strs;
    for (int i = start; i <= len; i++) {
        strs << QString::number(i);
    }
    setWords(strs);
}

QStringList UiComboLine::getWords() {
    QStringList strs;
    if (completer()) {
        QAbstractItemModel *m = completer()->model();
        for (int i = 0; i < m->rowCount(); i++) {
            strs << m->index(i, 0).data().toString();
        }
    }
    return strs;
}

void UiComboLine::mousePressEvent(QMouseEvent *event) {
    if (completer()) {
        completer()->complete();  // 弹出下拉框
    }

    QLineEdit::mousePressEvent(event);
}
