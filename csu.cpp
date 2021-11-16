#include "csu.h"
#include "ui_csu.h"

csu::csu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::csu)
{
    ui->setupUi(this);
    //设置输入框placeholder
    ui->lineEdit->setPlaceholderText("Nick");
    ui->lineEdit_2->setPlaceholderText("Ticket");
    //将Ticket输入框设置为密码格式
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    //创建Submit按钮
    QPushButton *sub = new QPushButton("Submit",this);
    sub->move(100,100);
    //点击时运行preStart函数
    connect(sub,&QPushButton::clicked,this,&csu::preStart);
}
void csu::preStart(){
    //读取输入框内内的字符
    nick=ui->lineEdit->text();
    ticket=ui->lineEdit_2->text();
    //目标网站登录
    QString request_url="http://c76d3656e.top:8003/chat/user/login?";
    qDebug()<< request_url;
    //startRequest开始请求连接
    startRequest(QUrl(request_url));
}
void csu::startRequest(const QUrl &requestedUrl){
    //接受网站
    url= requestedUrl;
    //创建manager
    manager = new QNetworkAccessManager(this);
    //req在csu.h中定义，用于请求
    req.setUrl(url);
    //post 的填充拼接
    QString data_load;
    data_load="nick="+nick;
    data_load+="&ticket="+ticket;
    QByteArray data = data_load.toUtf8();
    //获得网页回应
    reply = manager->post(req,data);
    //当完成网页信息获取后执行replyFinished
    connect(reply,&QNetworkReply::finished,this,&csu::replyFinished);

}

void csu::replyFinished(){
    //若返回错误则输出错误内容
    if(reply->error()){
        QString error = reply->errorString();
        qDebug()<<error;
        ui->textBrowser->setText(error);
        reply->deleteLater();
        reply = nullptr;
        return;
    }
    //输出状态码
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug()<<"statusCode: "<<statusCode;
    //状态码正常输出内容
    if(statusCode>=200&&statusCode<300){
        QString all = reply->readAll();
        qDebug()<<all;
        ui->textBrowser->setText(all);
        reply->deleteLater();
        reply = nullptr;
    }else if(statusCode >=300 && statusCode <400){
        //重定向
        const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        if(!redirectionTarget.isNull()){
            //获取重定向连接
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());
            reply->deleteLater();
            reply = nullptr;
            //开始重定向
            startRequest(redirectedUrl);
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }

    }
}

csu::~csu()
{
    delete ui;
}





