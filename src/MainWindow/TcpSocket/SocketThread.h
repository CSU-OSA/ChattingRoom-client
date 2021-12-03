//
// Created by Oct_Autumn on 2021/11/30.
//

#pragma once

#include <QThread>
#include <QTcpSocket>

class SocketThread : public QThread
{
public:
    explicit SocketThread(QObject *parent = nullptr);

    ~SocketThread();

protected:
    virtual void run();

signals:

    void receiveSerializedMsg(const char *);

public slots:

    void sendSerializedMsg(const char *);
};