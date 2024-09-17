#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class BaseDialog;
}
QT_END_NAMESPACE

class BaseDialog : public QDialog {
    Q_OBJECT

public:
    BaseDialog(QWidget* parent = nullptr);
    ~BaseDialog();

    /**
     * @brief 设置标题
     * @param title 标题文本
     */
    void setTitle(const QString& title);

    /**
     * @brief 设置logo
     * @param path logo图片路径
     */
    void setLogo(const QString& path);

    /**
     * @brief 添加最小化按钮
     * @param path 按钮图片路径
     * @param hoverPath 按钮悬浮图片路径
     */
    void addMinButton(const QString& path, const QString& hoverPath);

    /**
     * @brief 添加最大化按钮
     * @param maxPath 最大化按钮图片路径
     * @param maxPathHover 最大化按钮悬浮图片路径
     * @param normalPath 还原按钮图片路径
     * @param normalPathHover 还原按钮悬浮图片路径
     */
    void addMaxButton(const QString& maxPath, const QString& maxPathHover, const QString& normalPath,
                      const QString& normalPathHover);

    /**
     * @brief 添加一个新的按钮
     * @param path 按钮图片路径
     * @param hoverPath 按钮悬浮图片路径
     * @return 新增的按钮指针
     */
    QPushButton* addButton(const QString& path, const QString& hoverPath);

    /**
     * @brief 设置按钮图片
     * @param btn 按钮指针
     * @param path 按钮图片路径
     * @param hoverPath 按钮悬浮图片路径
     */
    void setButtonImage(QPushButton* btn, const QString& path, const QString& hoverPath);

    /**
     * @brief 设置所有按钮为统一大小
     * @param w 大小
     */
    void setAllButtonSize(int w = 20);

protected:
    void     mousePressEvent(QMouseEvent* event);
    void     mouseMoveEvent(QMouseEvent* event);
    QWidget* body();  // 为了让子界面也加入该窗口的对象树

private:
    void addCloseButton(const QString& path, const QString& hoverPath);
    void addWidget(QWidget* w);

protected:
    Ui::BaseDialog* m_ui;  // 设置为protected，因此子类也可以对窗口进行设置

private:
    QPoint m_start;
    int    m_sz = 20;  // 为了保证后续添加的自定义按钮大小也正常
};
#endif  // BASEDIALOG_H
