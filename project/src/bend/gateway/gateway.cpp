#include "gateway.h"

#include <QtConcurrent>

#include "src/bend/man/mancloud.h"
#include "src/config/apis.h"
#include "src/config/loggerproxy.h"

Q_GLOBAL_STATIC(GateWay, ins);

GateWay::GateWay(QObject *parent) : QObject{parent} {}

GateWay *GateWay::instance() { return ins(); }

void GateWay::send(int api, const QJsonValue &value) {
    // 将请求转发给线程，避免前端界面卡顿，提高软件性能
    QtConcurrent::run([=]() {
        try {
            this->dispatch(api, value);
        } catch (QString e) {
            mError(e);
        }
    });
}

void GateWay::dispatch(int api, const QJsonValue &value) {
    switch (api) {
        case API::LOGIN::NORMAL:
            apiLogin(value);
            break;
        default:
            break;
    }
}

void GateWay::apiLogin(const QJsonValue &value) {
    QString secretId  = value["secretId"].toString();
    QString secretKey = value["secretKey"].toString();
    MC->login(secretId, secretKey);
}
