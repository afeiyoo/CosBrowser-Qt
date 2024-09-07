#ifndef QOSDIALOG_H
#define QOSDIALOG_H

#include "basedialog.h"

namespace Ui {
class QosDialog;
}

class QosDialog : public BaseDialog {
    Q_OBJECT

public:
    explicit QosDialog(QWidget *parent = nullptr);
    ~QosDialog();

private:
    Ui::QosDialog *ui;
};

#endif  // QOSDIALOG_H
