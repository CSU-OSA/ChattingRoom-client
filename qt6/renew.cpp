#include "renew.h"

ReNew::ReNew()
{

}
void ReNew::run(){
    manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    QString all;
    while (true) {
        reply = manager->post(req,data);
        all = reply->readAll();
        qDebug()<<all;
        sleep(15);
    }
}
void ReNew::preRun(QUrl url_need,QByteArray data_need){
    QUrl url=url_need;
    data=data_need;
    req.setUrl(url);
}
