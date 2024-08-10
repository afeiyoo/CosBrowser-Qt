#ifndef VERSIONCMD_H
#define VERSIONCMD_H

#include <QStringList>

#include "version.h"

class VersionCmd : public Version {
public:
    VersionCmd(int argc, char* argv[]);

    void setVersion() override;

    bool isValid();

private:
    QStringList m_argv;
};

#endif  // VERSIONCMD_H
