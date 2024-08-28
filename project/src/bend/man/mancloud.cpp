#include "mancloud.h"

#include <QDebug>

#include "src/bend/dao/clouds/daoclouds.h"
#include "src/middle/manglobal.h"
#include "src/middle/models/cloudmodels.h"
#include "src/middle/signals/mansignals.h"
#include "src/plugins/manplugin.h"

ManCloud::ManCloud(QObject *parent) : QObject{parent} {}

ManCloud::~ManCloud() { qDebug("delete ManCloud "); }

void ManCloud::login(QString secretId, QString secretKey) {
    QList<MyBucket> buckets = MG->mPlugin->clouds()->login(secretId, secretKey);

    emit MG->mSignal->bucketSuccess(buckets);
}
