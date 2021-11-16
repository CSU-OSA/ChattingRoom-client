#ifndef CSU_H
#define CSU_H

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
namespace Ui { class csu; }
QT_END_NAMESPACE

class csu : public QMainWindow
{
    Q_OBJECT

public:
    csu(QWidget *parent = nullptr);
    ~csu();
    Ui::csu *ui;
    QString nick;
    QString ticket;
private:
    QUrl url;
    QNetworkRequest req;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
public slots:
    void preStart();
    void startRequest(const QUrl &requestedUrl);
    void replyFinished();
private slots:
};
#endif // CSU_H
