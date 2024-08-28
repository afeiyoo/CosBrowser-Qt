#include "gateway.h"

#include <QtConcurrent>

#include "src/bend/man/mancloud.h"
#include "src/config/apis.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"

GateWay::GateWay(QObject *parent) : QObject{parent} {}

GateWay::~GateWay() { qDebug("delete GateWay "); }

void GateWay::send(int api, const QJsonValue &value) {
    // 将请求转发给线程，避免前端界面卡顿，提高软件性能
    QtConcurrent::run([=]() {
        try {
            this->dispatch(api, value);
        } catch (QString e) {
            mError(e);
            emit MG->mSignal->error(api, e);
        }
    });
}

void GateWay::dispatch(int api, const QJsonValue &value) {
    // 查询路由表，调用接口
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
    MG->mCloud->login(secretId, secretKey);
    emit MG->mSignal->loginSuccess();  // 发出登录成功信号
}
