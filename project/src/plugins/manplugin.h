#ifndef MANPLUGIN_H
#define MANPLUGIN_H

#include <QObject>
#include "src/config/globals.h"

using namespace GLOBAL;

class DaoClouds;
class Version;

#define MP ManPlugin::instance()

class ManPlugin : public QObject
{
    Q_OBJECT
public:
    explicit ManPlugin(QObject *parent = nullptr);

    ~ManPlugin();

    static ManPlugin* instance();

    DaoClouds *clouds() const;

    void installPlugins(int argc, char *argv[]);
signals:

private:
    DaoClouds* m_clouds;    // 注意，为了屏蔽派生类的差异，不能使用派生类作为他的类型

    Version* m_version;
};

#endif // MANPLUGIN_H
