#include "mansignals.h"

ManSignals::ManSignals(QObject *parent) : QObject{parent} {}

ManSignals::~ManSignals() { qDebug("delete ManSignals "); }
