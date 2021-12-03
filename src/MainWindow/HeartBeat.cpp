//
// Created by Oct_Autumn on 2021/11/28.
//

#include "HeartBeat.h"

void HeartBeat::run()
{
    while (keepRunning)
    {
        QThread::sleep(2);
        emit heartbeat_bell();
    }

    emit isDone(this);
}

HeartBeat::HeartBeat(QObject *parent)
{
    keepRunning = true;
}

HeartBeat::~HeartBeat()
{

}

void HeartBeat::stopRunning()
{
    keepRunning = false;
}
