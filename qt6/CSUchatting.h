#ifndef CSUCHATTING_H
#define CSUCHATTING_H

#include <QMainWindow>

#include <QMainWindow>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include <QPushButton>
#pragma once
QT_BEGIN_NAMESPACE
namespace Ui
{
    class CSUchatting;
}
QT_END_NAMESPACE

class CSUchatting : public QMainWindow
{
    Q_OBJECT

public:
    CSUchatting(QWidget *parent = nullptr);
    ~CSUchatting();
    Ui::CSUchatting *ui;
    QString nick;
    QString ticket;
private:
    QUrl url;
    QNetworkRequest req;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
public slots:
    void preStart();
    void startRequest(const QString &requestedUrl);
    void replyFinished();
private slots:
};
#endif // CSUCHATTING_H
