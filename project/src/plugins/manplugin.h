#ifndef MANPLUGIN_H
#define MANPLUGIN_H

#include <QObject>

class DaoClouds;

#define MP ManPlugin::instance()

class ManPlugin : public QObject
{
    Q_OBJECT
public:
    explicit ManPlugin(QObject *parent = nullptr);

    static ManPlugin* instance();

    DaoClouds *clouds() const;

signals:

private:
    void installPlugins();

private:
    DaoClouds* m_clouds;    // 注意，为了屏蔽派生类的差异，不能使用派生类作为他的类型

};

#endif // MANPLUGIN_H
