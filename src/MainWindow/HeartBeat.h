//
// Created by Oct_Autumn on 2021/11/28.
//
#pragma once

#include <QThread>
#include <QTcpSocket>

class HeartBeat : public QThread
{
Q_OBJECT
public:
    explicit HeartBeat(QObject *parent = 0);

    ~HeartBeat();

protected:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run();

private:
    bool keepRunning;
signals:

    void isDone(const HeartBeat *);  //处理完成信号
    void heartbeat_bell();

public slots:

    void stopRunning();
};
