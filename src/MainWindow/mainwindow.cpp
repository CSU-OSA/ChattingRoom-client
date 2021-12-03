//
// Created by Oct_Autumn on 2021/11/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QTime>
#include <string>
#include <QMetaMethod>
#include <src/MainWindow/JoinChaDialog/joinchadialog.h>
#include <src/MainWindow/CreateChaDialog/createchadialog.h>
#include <QDialog>
#include <src/MainWindow/QuitChaDialog/quitchadialog.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "src/dependencies/proto/Request.pb.h"
#include "src/dependencies/proto/Response.pb.h"

#define TERMINAL "控制台"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mp_clientSocket = new QTcpSocket();

    std::shared_ptr<QString> consoleLog(new QString(""));
    logMap.insert(TERMINAL, consoleLog);

    ui->terminalSelect->addItem(TERMINAL);
    ui->terminalSelect->setCurrentIndex(0);

    ui->serverURL->setText("127.0.0.1");
    ui->serverPort->setValue(8080);

    ui->refreshChaListBtn->setDisabled(true);
    ui->joinChaBtn->setDisabled(true);
    ui->newChaBtn->setDisabled(true);
    ui->quitChaBtn->setDisabled(true);

    connect(ui->connectServerBtn, SIGNAL(clicked()), this, SLOT(ConnectServer()));
    connect(ui->refreshChaListBtn, SIGNAL(clicked()), this, SLOT(refreshChaList()));
    connect(ui->terminalSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLogBox(int)));
    connect(ui->joinChaBtn, SIGNAL(clicked()), this, SLOT(joinCha()));
    connect(ui->newChaBtn, SIGNAL(clicked()), this, SLOT(createCha()));
    connect(ui->quitChaBtn, SIGNAL(clicked()), this, SLOT(quitCha()));
    connect(ui->lineInput, SIGNAL(returnPressed()), this, SLOT(SendMsg()));
}

MainWindow::~MainWindow()
{
    mp_clientSocket->close();
    delete ui;
}

void MainWindow::ConnectServer()
{
    if (mp_clientSocket->isOpen())
    {
        addLog(TERMINAL, "Operation refused.");
        addLog(TERMINAL, "You have already connected on a Server.");
        return;
    }

    connect(mp_clientSocket, SIGNAL(connected()), this, SLOT(SocketActive()));

    addLog(TERMINAL, "Connecting...");

    QString serverURL = ui->serverURL->displayText();
    int serverPort = ui->serverPort->value();

    mp_clientSocket->connectToHost(serverURL, serverPort);

    if (!mp_clientSocket->waitForConnected(5000))
    {
        addLog(TERMINAL, "Connection timeout.");
        addLog(TERMINAL, QString(
                "Failed to connect to Server [" + serverURL + "] at Port [" + std::to_string(serverPort).c_str() +
                "]"));
        mp_clientSocket->close();
        return;
    }

    connect(heartBeat, SIGNAL(heartbeat_bell()), this, SLOT(sendHeartBeat()));
    connect(mp_clientSocket, SIGNAL(disconnected()), this, SLOT(SocketInactive()));
}


void MainWindow::DisConnectServer()
{
    heartBeat->stopRunning();
    auto *requestPojo = new proto::request::RequestPOJO();
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_LOGOUT);

    std::basic_string<char> serializeStr;
    requestPojo->SerializeToString(&serializeStr);

    disconnect(heartBeat, SIGNAL(heartbeat_bell()), this, SLOT(sendHeartBeat()));
    mp_clientSocket->write(serializeStr.data());
    mp_clientSocket->flush();
}

void MainWindow::SocketActive()
{
    ui->refreshChaListBtn->setDisabled(false);
    ui->joinChaBtn->setDisabled(false);
    ui->newChaBtn->setDisabled(false);
    ui->quitChaBtn->setDisabled(false);

    disconnect(mp_clientSocket, SIGNAL(connected()), this, SLOT(SocketActive()));

    connect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(HandleSerializeMessage()));

    addLog(TERMINAL, QString("Connected to Server."));

    ui->connectServerBtn->setText("断开连接");
    ui->connectServerBtn->setStyleSheet("background-color: rgb(255, 135, 135);"
                                        "color: rgb(130, 69, 69);"
                                        "border-style: outset;"
                                        "border-width: 2px;"
                                        "border-radius: 10px;"
                                        "border-color: white;"
                                        "font: 700 9pt \"Microsoft YaHei UI\";");
    disconnect(ui->connectServerBtn, SIGNAL(clicked()), this, SLOT(ConnectServer()));
    connect(ui->connectServerBtn, SIGNAL(clicked()), this, SLOT(DisConnectServer()));

    ui->serverURL->setDisabled(true);
    ui->serverPort->setDisabled(true);

    heartBeat = new HeartBeat(this);
    heartBeat->start();

    refreshChaList();
}

void MainWindow::SocketInactive()
{
    ui->refreshChaListBtn->setDisabled(true);
    ui->joinChaBtn->setDisabled(true);
    ui->newChaBtn->setDisabled(true);
    ui->quitChaBtn->setDisabled(true);

    disconnect(mp_clientSocket, SIGNAL(disconnected()), this, SLOT(SocketInactive()));

    disconnect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(HandleSerializeMessage()));

    connect(heartBeat, SIGNAL(isDone(const HeartBeat*)), this, SLOT(heartBeatStopped(const HeartBeat*)));

    addLog(TERMINAL, "Connection closed.\n");
    mp_clientSocket->close();

    ui->connectServerBtn->setText("连接");
    ui->connectServerBtn->setStyleSheet("background-color: rgb(146, 240, 146);"
                                        "color: rgb(76, 125, 76);"
                                        "border-style: outset;"
                                        "border-width: 2px;"
                                        "border-radius: 10px;"
                                        "border-color: white;"
                                        "font: 700 9pt \"Microsoft YaHei UI\";");
    disconnect(ui->connectServerBtn, SIGNAL(clicked()), this, SLOT(DisConnectServer()));
    connect(ui->connectServerBtn, SIGNAL(clicked()), this, SLOT(ConnectServer()));

    ui->serverURL->setDisabled(false);
    ui->serverPort->setDisabled(false);

    heartBeat->stopRunning();

    QMap<QString, std::shared_ptr<QString>>::const_iterator i = logMap.constBegin();
    while (i != logMap.constEnd())
    {
        if (i.key() != TERMINAL)
        {
            ui->terminalSelect->removeItem(ui->terminalSelect->findText(i.key()));
            logMap.remove(i.key());
        }
        i++;
    }

    nickMap.clear();
    changeLogBox(0);

    ui->channelList->setPlainText("");
}

void MainWindow::sendHeartBeat()
{

    auto *requestPojo = new proto::request::RequestPOJO();
    std::basic_string<char> HBData;

    //qDebug() << "Trying to send Heartbeat pack...";
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_HEARTBEAT);
    requestPojo->SerializeToString(&HBData);

    SendSerializeMessage(HBData.data());

    //qDebug() << "Trying to send GetMsg pack...";
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_GETMSG);
    requestPojo->SerializeToString(&HBData);

    SendSerializeMessage(HBData.data());

    delete requestPojo;
}

void MainWindow::heartBeatStopped(const HeartBeat *HBThread)
{
    disconnect(heartBeat, SIGNAL(isDone(const HeartBeat*)), this, SLOT(heartBeatStopped(const HeartBeat*)));
    delete HBThread;
}

void MainWindow::SendMsg()
{
    QString msgToSend = ui->lineInput->text();
    QString chaName = ui->terminalSelect->itemText(ui->terminalSelect->currentIndex());
    std::string msgToSend_str = msgToSend.toStdString();

    ui->lineInput->clear();

    auto *requestPojo = new proto::request::RequestPOJO();
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_SENDMSG);

    auto *message = new proto::request::Message();
    message->set_channel(chaName.toStdString());
    message->set_content(msgToSend.toStdString());

    requestPojo->set_allocated_message(message);

    std::basic_string<char> serializeStr;
    requestPojo->SerializeToString(&serializeStr);
    //qDebug() << requestPojo->DebugString().data() << Qt::endl;

    SendSerializeMessage(serializeStr.data());

    message->release_channel();
    message->release_content();

    requestPojo->release_message();

    delete message;
    delete requestPojo;

    addLog(chaName, getLocalTime() + " | " + nickMap.value(chaName) + "\n" + msgToSend + "\n");
}

QString MainWindow::addLog(const QString &target, const QString &logContent, bool refreshLogBox)
{
    if (target == TERMINAL)
        logMap.value(target)->append(getLocalTime() + " | SYS\n" + logContent + "\n");
    else
        logMap.value(target)->append(logContent);

    if (refreshLogBox)
    {
        ui->logBox->setPlainText(*logMap.value(ui->terminalSelect->itemText(ui->terminalSelect->currentIndex())));
        ui->logBox->moveCursor(QTextCursor::End);
    }

    return nullptr;
}

void MainWindow::changeLogBox(int index)
{
    QString terminalName = ui->terminalSelect->itemText(index);
    ui->logBox->setPlainText(*logMap.value(terminalName));
    ui->logBox->moveCursor(QTextCursor::End);
}

bool MainWindow::SendSerializeMessage(const char *serializedStr)
{
    if (!mp_clientSocket->isWritable())
    {
        //qDebug() << "Error. Socket is not writable!";
        return false;
    }
    //qDebug() << "SEND Success";
    mp_clientSocket->write(serializedStr);
    mp_clientSocket->flush();
    return true;
}

void MainWindow::HandleSerializeMessage()
{
    QByteArray incomeData = mp_clientSocket->readAll();

    proto::response::ResponsePOJO responsePojo;
    responsePojo.ParseFromString(QString::fromUtf8(incomeData).toStdString());
    qDebug() << responsePojo.DebugString().data() << Qt::endl;

    switch (responsePojo.type())
    {
        case proto::response::ResponsePOJO_Type_RESULT:
        {
            QString msgStr = responsePojo.result().msg().data();
            if (msgStr.startsWith("VERSION"))
            {
                addLog(TERMINAL, msgStr);
                return;
            }
            if (msgStr.startsWith("HEARTBEAT"))
                return;
            if (msgStr.startsWith("JOIN_CHA"))
            {
                addLog(TERMINAL, msgStr, false);
                emit joinChaResponse(incomeData);
                if (responsePojo.result().result())
                {
                    QString chaName = msgStr.split('|')[1].split(" ")[0];
                    QString nick = msgStr.split('|')[1].split(" ")[1];

                    std::shared_ptr<QString> logPtr(new QString(""));
                    logMap.insert(chaName, logPtr);
                    nickMap.insert(chaName, nick);

                    addLog(chaName, getLocalTime() + " | SYS" + "\n" + "You joined this channel using nick [" +
                                    nickMap.value(chaName) + "]\n");

                    ui->terminalSelect->addItem(chaName);
                    ui->terminalSelect->setCurrentIndex(ui->terminalSelect->findText(chaName));
                }
                refreshChaList();
                return;
            }
            if (msgStr.startsWith("CREATE_CHA"))
            {
                addLog(TERMINAL, msgStr, false);
                emit createChaResponse(incomeData);
                if (responsePojo.result().result())
                {
                    QString chaName = msgStr.split('|')[1].split(" ")[0];
                    QString nick = msgStr.split('|')[1].split(" ")[1];

                    std::shared_ptr<QString> logPtr(new QString(""));
                    logMap.insert(chaName, logPtr);
                    nickMap.insert(chaName, nick);

                    addLog(chaName, getLocalTime() + " | SYS" + "\n" + "You joined this channel using nick [" +
                                    nickMap.value(chaName) + "]\n");

                    ui->terminalSelect->addItem(chaName);
                    ui->terminalSelect->setCurrentIndex(ui->terminalSelect->findText(chaName));
                }
                refreshChaList();
                return;
            }
            if (msgStr.startsWith("QUIT_CHA"))
            {
                addLog(TERMINAL, msgStr, false);
                emit quitChaResponse(incomeData);
                if (responsePojo.result().result())
                {
                    QString chaName = msgStr.split('|')[1].split(" ")[0];

                    logMap.remove(chaName);
                    nickMap.remove(chaName);

                    ui->terminalSelect->removeItem(ui->terminalSelect->findText(chaName));
                    ui->terminalSelect->setCurrentIndex(0);
                }
                refreshChaList();
                return;
            }
            if (msgStr.startsWith("SENDMSG"))
            {
                return;
            }
            addLog(TERMINAL, msgStr, false);
            return;
        }
        case proto::response::ResponsePOJO_Type_ChannelList:
            if (responsePojo.channelinfo_size() == 0)
                ui->channelList->setPlainText("No Channel opened");
            else
            {
                QString chaListStr;
                chaListStr.append("频道名称 | 频道权限 | 频道内人数\n");
                for (const auto &item: responsePojo.channelinfo())
                {
                    chaListStr.append(item.name().data());
                    chaListStr.append(" | ");
                    chaListStr.append(item.ispublic() ? "公共" : "私有");
                    chaListStr.append(" | ");
                    chaListStr.append(std::to_string(item.membernum()).data());
                    chaListStr.append('\n');
                }
                ui->channelList->setPlainText(chaListStr);
            }
            return;
        case proto::response::ResponsePOJO_Type_MESSAGE:
            if (responsePojo.message_size() != 0)
            {
                QString message;
                for (const auto &item: responsePojo.message())
                {
                    message.append(item.rectime().data());
                    message.append(" | ");
                    message.append(item.fromnick().data());
                    message.append('\n');
                    message.append(item.content().data());
                    message.append('\n');

                    if (logMap.contains(item.channel().data()))
                        logMap.value(item.channel().data())->append(message);
                }
                QString terminalName = ui->terminalSelect->itemText(ui->terminalSelect->currentIndex());
                ui->logBox->setPlainText(*logMap.value(terminalName));
            }
            return;
        default:
            //qDebug() << "Un supported response type.";
            return;
    }

}

void MainWindow::refreshChaList()
{
    auto *requestPojo = new proto::request::RequestPOJO();
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_GET_CHANNEL_LIST);

    std::basic_string<char> serializeStr;
    requestPojo->SerializeToString(&serializeStr);

    SendSerializeMessage(serializeStr.data());

    delete requestPojo;
}

void MainWindow::joinCha()
{
    joinChaDialog joinChaDialog_inst(this);
    disconnect(this, SIGNAL(joinChaResponse(const char*)), nullptr, nullptr);
    connect(this, SIGNAL(joinChaResponse(const char*)), &joinChaDialog_inst, SLOT(joinResponse(const char*)));
    connect(&joinChaDialog_inst, SIGNAL(sendJoinCHAMsg(const char*)), this, SLOT(SendSerializeMessage(const char*)));
    joinChaDialog_inst.exec();
}

void MainWindow::createCha()
{
    CreateChaDialog createChaDialog_inst(this);
    disconnect(this, SIGNAL(createChaResponse(const char*)), nullptr, nullptr);
    connect(this, SIGNAL(createChaResponse(const char*)), &createChaDialog_inst, SLOT(createResponse(const char*)));
    connect(&createChaDialog_inst, SIGNAL(sendCreateCHAMsg(const char*)), this,
            SLOT(SendSerializeMessage(const char*)));
    createChaDialog_inst.exec();
}

void MainWindow::quitCha()
{
    QuitChaDialog quitChaDialog_inst(this);
    disconnect(this, SIGNAL(quitChaResponse(const char*)), nullptr, nullptr);
    connect(this, SIGNAL(quitChaResponse(const char*)), &quitChaDialog_inst, SLOT(quitResponse(const char*)));
    connect(&quitChaDialog_inst, SIGNAL(sendQuitCHAMsg(const char*)), this, SLOT(SendSerializeMessage(const char*)));
    quitChaDialog_inst.exec();
}

QString MainWindow::getLocalTime()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    return curDateTime.toString("yyyy-MM-dd hh:mm:ss");
}
