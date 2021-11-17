#ifndef RENEW_H
#define RENEW_H
#include <QThread>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#pragma once
class ReNew : public QThread
{
public:
    ReNew();
    void run();
    void preRun(QUrl url_need,QByteArray data_need);
    QByteArray data;
    QNetworkAccessManager *manager;
    QNetworkRequest req;
};

#endif // RENEW_H
