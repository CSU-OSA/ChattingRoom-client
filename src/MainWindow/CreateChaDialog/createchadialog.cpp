//
// Created by Oct_Autumn on 2021/11/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateChaDialog.h" resolved

#include <src/dependencies/proto/Request.pb.h>
#include <src/dependencies/proto/Response.pb.h>
#include "createchadialog.h"
#include "ui_CreateChaDialog.h"


CreateChaDialog::CreateChaDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::CreateChaDialog)
{
    ui->setupUi(this);

    connect(ui->createBtn, SIGNAL(clicked()), this, SLOT(createBtnPressed()));
    connect(ui->chaNameEdit, SIGNAL(textEdited(QString)), this, SLOT(chaNameEdit_textChanged()));
    connect(ui->nickEdit, SIGNAL(textEdited(QString)), this, SLOT(nickEdit_textChanged()));

}

CreateChaDialog::~CreateChaDialog()
{
    disconnect(ui->createBtn, SIGNAL(clicked()), this, SLOT(createBtnPressed()));
    disconnect(ui->chaNameEdit, SIGNAL(textEdited(QString)), this, SLOT(chaNameEdit_textChanged()));
    disconnect(ui->nickEdit, SIGNAL(textEdited(QString)), this, SLOT(nickEdit_textChanged()));
    disconnect(parent(), SIGNAL(createChaResponse(const char*)), this, SLOT(createResponse(const char*)));
    disconnect(this, SIGNAL(sendCreateCHAMsg(const char*)), nullptr, nullptr);
    delete ui;
}

void CreateChaDialog::createBtnPressed()
{
    {
        bool isOK = true;
        if (ui->chaNameEdit->text() == "")
        {
            ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
            ui->chaNameEdit->setPlaceholderText("不能为空");
            isOK = false;
        }
        if (ui->chaNameEdit->text().contains(' '))
        {
            ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
            ui->msgBox->setText("频道名或昵称不能包含空格!");
            isOK = false;
        }
        if (ui->nickEdit->text() == "")
        {
            ui->nickEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
            ui->nickEdit->setPlaceholderText("不能为空");
            isOK = false;
        }
        if (ui->nickEdit->text().contains(' '))
        {
            ui->nickEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
            ui->msgBox->setText("频道名或昵称不能包含空格!");
            isOK = false;
        }
        if (!isOK)
            return;
    }

    //qDebug() << "Trying to send CreateCha pack...";
    auto *requestPojo = new proto::request::RequestPOJO();
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_CREATE_CHA);

    auto *channel = new proto::request::Channel();

    channel->set_channel(ui->chaNameEdit->text().toStdString());
    channel->set_nick(ui->nickEdit->text().toStdString());
    if (ui->chaTicketEdit->text() != "")
        channel->set_ticket(ui->chaTicketEdit->text().toStdString());

    //qDebug() << channel->DebugString().data();

    requestPojo->set_allocated_channel(channel);

    std::basic_string<char> serializeStr;
    requestPojo->SerializeToString(&serializeStr);

    //qDebug() << requestPojo->DebugString().data();

    QString str(serializeStr.data());

    emit sendCreateCHAMsg(str.toUtf8());

    channel->release_channel();
    channel->release_nick();
    if (ui->chaTicketEdit->text() != "")
        channel->release_ticket();

    requestPojo->release_channel();

    delete channel;
    delete requestPojo;
}

void CreateChaDialog::createResponse(const char *incomeData)
{
    proto::response::ResponsePOJO responsePojo;
    responsePojo.ParseFromString(QString::fromUtf8(incomeData).toStdString());

    if (responsePojo.result().result())
        this->close();
    else
    {
        QString oriMsg = responsePojo.result().msg().data();
        ui->msgBox->setText(oriMsg.split("|")[1]);
    }
}

void CreateChaDialog::chaNameEdit_textChanged()
{
    if (ui->chaNameEdit->text() == "")
        ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
    else
        ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
}

void CreateChaDialog::nickEdit_textChanged()
{
    if (ui->nickEdit->text() == "")
        ui->nickEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
    else
        ui->nickEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
}

