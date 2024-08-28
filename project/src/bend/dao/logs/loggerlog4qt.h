#ifndef LOGGERLOG4QT_H
#define LOGGERLOG4QT_H

#include "basiclogger.h"

class LoggerLog4qt : public BasicLogger
{
public:
    explicit LoggerLog4qt(QObject *parent = nullptr);
};

#endif // LOGGERLOG4QT_H
