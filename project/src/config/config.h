#ifndef CONFIG_H
#define CONFIG_H

#include "src/helper/filehelper.h"
#include <QString>
#include <QDir>

namespace CONF {
namespace PATH {
static const QString WORK = QDir::currentPath();
static const QString TMP = FileHelper::joinPath(WORK, "tmp");
}; // namespace PATH

namespace SQLITE {
static const QString NAME = FileHelper::joinPath(PATH::TMP, "cos.db");
}; // namespace SQLITE

namespace SQL {
static const QString LOGIN_INFO_TABLE = ":/static/sql/login_info.sql";
}; // namespace SQL

static bool init(){
    return FileHelper::mkPath(PATH::TMP);
}

static bool OK = init();

} // namespace CONF

#endif // CONFIG_H
