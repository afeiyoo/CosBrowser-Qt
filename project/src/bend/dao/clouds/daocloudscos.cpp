#include "daocloudscos.h"

#include <QDebug>

#include "cos_api.h"
#include "src/config/errorcode.h"
#include "src/config/exception.h"

using namespace qcloud_cos;

DaoCloudsCos::DaoCloudsCos() { m_config = new CosConfig("./cosconfig.json"); }

DaoCloudsCos::~DaoCloudsCos() {
    delete m_config;
    m_config = nullptr;
}

QList<MyBucket> DaoCloudsCos::buckets() {
    QList<MyBucket> res;

    GetServiceReq  req;
    GetServiceResp resp;
    CosAPI         cos    = qcloud_cos::CosAPI(*m_config);
    CosResult      result = cos.GetService(req, &resp);

    if (result.IsSucc()) {
        std::vector<Bucket> bs = resp.GetBuckets();
        for (std::vector<Bucket>::const_iterator itr = bs.begin(); itr != bs.end(); ++itr) {
            const Bucket &v = *itr;

            // 转换成统一的数据结构 MyBucket
            MyBucket b;
            b.name       = QString(v.m_name.c_str());
            b.location   = QString(v.m_location.c_str());
            b.createDate = QString(v.m_create_date.c_str());
            res.append(b);
        }
    } else {
        QString msg = QString::fromLocal8Bit("腾讯云错误码【%1】： %2")
                          .arg(result.GetErrorCode().c_str(), result.GetErrorMsg().c_str());
        throw BaseException(EC_211000, msg);
    }
    //    throwError(result);

    return res;
}

QList<MyBucket> DaoCloudsCos::login(const QString &secretId, const QString &secretKey) {
    m_config->SetAccessKey(secretId.toStdString());
    m_config->SetSecretKey(secretKey.toStdString());
    m_config->SetRegion("ap-nanjing");

    return buckets();
}

bool DaoCloudsCos::isBucketExists(const QString &bucketName) {
    QString location = getBucketLocation(bucketName);
    m_config->SetRegion(location.toLocal8Bit().data());
    CosAPI cos = CosAPI(*m_config);
    return cos.IsBucketExist(bucketName.toStdString());
}

QString DaoCloudsCos::getBucketLocation(const QString &bucketName) {
    CosAPI cos = CosAPI(*m_config);
    return QString(cos.GetBucketLocation(bucketName.toStdString()).c_str());
}
