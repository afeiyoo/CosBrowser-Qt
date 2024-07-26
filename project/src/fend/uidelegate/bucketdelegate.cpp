#include "bucketdelegate.h"

#include <QComboBox>

BucketDelegate::BucketDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

QWidget *BucketDelegate::createEditor(QWidget *parent,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const {
    Q_UNUSED(option);
    Q_UNUSED(index);

    QComboBox *box = new QComboBox(parent); // 结束编辑时，这个box会自动释放
    box->addItem("ap-bejin");
    box->addItem("ap-shanghai");
    box->addItem("ap-guangzhou");
    box->setFrame(false);
    return box;
}

void BucketDelegate::setEditorData(QWidget *editor,
                                   const QModelIndex &index) const {
    QComboBox *box = static_cast<QComboBox *>(editor);
    QString text = index.data(Qt::EditRole).toString();
    box->setCurrentText(text);
}

void BucketDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                  const QModelIndex &index) const {
    QComboBox *box = static_cast<QComboBox *>(editor);
    model->setData(index, box->currentText());
}
