#ifndef UIBUCKETDELEGATE_H
#define UIBUCKETDELEGATE_H

#include <QStyledItemDelegate>
#include <QWidget>

class UiBucketDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    UiBucketDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif  // UIBUCKETDELEGATE_H
