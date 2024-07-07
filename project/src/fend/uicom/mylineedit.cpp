#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent) {}

void MyLineEdit::keyPressEvent(QKeyEvent *event) {
    if (event->modifiers() == Qt::ControlModifier) {
        if (event->key() == Qt::Key_C || event->key() == Qt::Key_V)
            return;
    }

    QLineEdit::keyPressEvent(event);
}
