//
// Created by Oct_Autumn on 2021/12/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QuitChaDialog.h" resolved

#include <src/dependencies/proto/Request.pb.h>
#include <src/dependencies/proto/Response.pb.h>
#include "quitchadialog.h"
#include "ui_QuitChaDialog.h"


QuitChaDialog::QuitChaDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::QuitChaDialog)
{
    ui->setupUi(this);

    connect(ui->quitBtn, SIGNAL(clicked()), this, SLOT(quitBtnPressed()));
    connect(ui->chaNameEdit, SIGNAL(textEdited(QString)), this, SLOT(chaNameEdit_textChanged()));
}

QuitChaDialog::~QuitChaDialog()
{
    disconnect(ui->quitBtn, SIGNAL(clicked()), this, SLOT(quitBtnPressed()));
    disconnect(ui->chaNameEdit, SIGNAL(textEdited(QString)), this, SLOT(chaNameEdit_textChanged()));
    disconnect(parent(), SIGNAL(quitChaResonse(const char*)), this, SLOT(quitResponse(const char*)));
    disconnect(this, SIGNAL(sendQuitCHAMsg(const char*)), nullptr, nullptr);
    delete ui;
}

void QuitChaDialog::quitBtnPressed()
{
    if (ui->chaNameEdit->text() == "")
    {
        ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
        ui->chaNameEdit->setPlaceholderText("不能为空");
        return;
    }
    if (ui->chaNameEdit->text().contains(' '))
    {
        ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
        ui->msgBox->setText("频道名不能包含空格");
        return;
    }

    //qDebug() << "Trying to send QuitCha pack...";
    auto *requestPojo = new proto::request::RequestPOJO();
    requestPojo->set_operation(proto::request::RequestPOJO_Operation_QUIT_CHA);

    auto *channel = new proto::request::Channel();

    channel->set_channel(ui->chaNameEdit->text().toStdString());

    //qDebug() << channel->DebugString().data();

    requestPojo->set_allocated_channel(channel);

    std::basic_string<char> serializeStr;
    requestPojo->SerializeToString(&serializeStr);

    //qDebug() << requestPojo->DebugString().data();

    QString str(serializeStr.data());

    emit sendQuitCHAMsg(str.toUtf8());

    channel->release_channel();

    requestPojo->release_channel();

    delete channel;
    delete requestPojo;
}

void QuitChaDialog::quitResponse(const char *incomeData)
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

void QuitChaDialog::chaNameEdit_textChanged()
{
    if (ui->chaNameEdit->text() == "")
        ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 135, 135)");
    else
        ui->chaNameEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
}

