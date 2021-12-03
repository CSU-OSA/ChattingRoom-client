//
// Created by Oct_Autumn on 2021/11/23.
//

#pragma once

#include <QMainWindow>

#include <QTcpSocket>
#include "HeartBeat.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    QString addLog(const QString &target, const QString &logContent, bool refreshLogBox = true);

    QString getLocalTime();

private:
    Ui::MainWindow *ui;

    HeartBeat *heartBeat;
    QTcpSocket *mp_clientSocket;

    QMap<QString, std::shared_ptr<QString>> logMap;
    QMap<QString, QString> nickMap;

signals:

    void joinChaResponse(const char *);

    void createChaResponse(const char *);

    void quitChaResponse(const char *);

public slots:

    void HandleSerializeMessage();

    bool SendSerializeMessage(const char *);

private slots:

    void ConnectServer();

    void DisConnectServer();

    void SocketActive();

    void SocketInactive();

    void sendHeartBeat();

    void heartBeatStopped(const HeartBeat *);

    void SendMsg();

    void refreshChaList();

    void joinCha();

    void createCha();

    void quitCha();

    void changeLogBox(int);
};

