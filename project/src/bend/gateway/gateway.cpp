#include "gateway.h"

#include <QtConcurrent>

#include "src/bend/man/mancloud.h"
#include "src/config/apis.h"
#include "src/config/errorcode.h"
#include "src/config/exception.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"

GateWay::GateWay(QObject *parent) : QObject{parent} {}

GateWay::~GateWay() { qDebug("delete GateWay "); }

void GateWay::send(int api, const QJsonValue &params) {
    // 将请求转发给线程，避免前端界面卡顿，提高软件性能
    QtConcurrent::run([=]() {
        try {
            this->dispatch(api, params);
        } catch (BaseException e) {
            mError(e.msg());
            emit MG->mSignal->error(api, e.msg(), params);
        } catch (...) {
            BaseException e = BaseException(EC_100000, QString("未知错误"));
            mError(e.msg());
            emit MG->mSignal->error(api, e.msg(), params);
        }
    });
}

void GateWay::dispatch(int api, const QJsonValue &params) {
    // 查询路由表，调用接口
    switch (api) {
        case API::LOGIN::NORMAL:
            apiLogin(params);
            break;
            // 桶操作接口
        case API::BUCKETS::LIST:
            apiGetBuckets(params);
            break;
        case API::BUCKETS::DEL:
            apiDeleteBucket(params);
            break;
        case API::BUCKETS::PUT:
            apiPutBucket(params);
            break;

            // 对象操作接口
        case API::OBJECTS::GET:
            apiGetObject(params);
            break;
        case API::OBJECTS::LIST:
            apiGetObjects(params);
            break;
        case API::OBJECTS::PUT:
            apiPutObject(params);
            break;
        default:
            break;
    }
}

void GateWay::apiLogin(const QJsonValue &params) {
    QString secretId  = params["secretId"].toString();
    QString secretKey = params["secretKey"].toString();
    MG->mCloud->login(secretId, secretKey);
    emit MG->mSignal->loginSuccess();  // 发出登录成功信号
}

void GateWay::apiGetBuckets(const QJsonValue &params) {
    Q_UNUSED(params);
    MG->mCloud->getBuckets();
}

void GateWay::apiPutBucket(const QJsonValue &params) {
    QString bucketName = params["bucketName"].toString();
    QString location   = params["location"].toString();
    MG->mCloud->putBucket(bucketName, location);
}

void GateWay::apiDeleteBucket(const QJsonValue &params) {
    QString bucketName = params["bucketName"].toString();
    MG->mCloud->deleteBucket(bucketName);
}

void GateWay::apiGetObjects(const QJsonValue &params) {
    QString bucketName = params["bucketName"].toString();
    QString dir        = params["dir"].toString();
    MG->mCloud->getObjects(bucketName, dir);
}

void GateWay::apiGetObject(const QJsonValue &params) {
    QString jobId      = params["jobId"].toString();  // 用于更新下载进度的任务id
    QString bucketName = params["bucketName"].toString();
    QString key        = params["key"].toString();
    QString localPath  = params["localPath"].toString();
    MG->mCloud->getObject(jobId, bucketName, key, localPath);
}

void GateWay::apiPutObject(const QJsonValue &params) {
    QString jobId      = params["jobId"].toString();  // 用于更新下载进度的任务id
    QString bucketName = params["bucketName"].toString();
    QString key        = params["key"].toString();
    QString localPath  = params["localPath"].toString();
    MG->mCloud->putObjcet(jobId, bucketName, key, localPath);
}
