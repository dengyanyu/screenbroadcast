#include <QByteArray>
#include <QHostAddress>
#include <QStringList>
#include <QImage>

#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    getServer = new QUdpSocket();
     QObject::connect(getServer,SIGNAL(readyRead()),this,SLOT(slotGetServerPort()));
    getServer->bind(QHostAddress::Any,7777);
    haveGetServerInfo = false;

    //创建连接服务器的tcp套接子
    interactWithServer = new QTcpSocket();
    QObject::connect(interactWithServer,SIGNAL(connected()),this,SLOT(slot_connected_to_server()));
    QObject::connect(interactWithServer,SIGNAL(disconnected()),this,SLOT(slot_disconnected_to_server()));


}
//接收服务器发来的广播消息---端口号
void ClientDialog::slotGetServerPort()
{
     QByteArray recvMsg;

     bool ok;
    //while(getServer->hasPendingDatagrams())
    recvMsg.resize(getServer->pendingDatagramSize());
    getServer->readDatagram(recvMsg.data(),recvMsg.size());


    QString msg(recvMsg);
    qDebug()<<"recv msg:  "<<msg;
    QStringList detailMsg = msg.split('\n');

    QString temp = detailMsg.at(0);

    if(temp != "CHATSERVER/1.0" )
    {
        getServer->readAll();
        qDebug()<<"dicard package!!!";
        return;
    }

     quint32 recv_len = 0;
     temp = detailMsg.at(3);
     temp = temp.split(" ").at(1);
     recv_len = temp.toUInt(&ok,10);

     temp = detailMsg.at(1);
     temp = temp.split(" ").at(1);
     qDebug()<<"temp = "<<temp;
    if(temp.toUInt(&ok,10) == ServerAddress )
    {
        if (haveGetServerInfo ==  false)
                return handle_serveraddress(recv_len);
     }
    if(temp.toUInt(&ok,10) == File )
    {
              temp = detailMsg.at(2);
              QString filename = temp.split(" ").at(1);
              return handle_fileDown(filename,recv_len);
    }
    if(temp.toUInt(&ok,10) == Image )
    {
              return handle_screenBroadcast(recv_len);
    }
}
void ClientDialog::handle_serveraddress(quint32 size)
{

    QByteArray recvMsg;
    bool ok;

   recvMsg.resize(size);
   //数据不正确抛弃数据包
   if(size != getServer->readDatagram(recvMsg.data(),recvMsg.size()))
       return;
   qDebug()<<"handle recv msg:  "<<QString(recvMsg);
   QStringList temp = QString(recvMsg).split('#');
   serverIP = temp.at(0);
   serverPort = temp.at(1).toUInt(&ok,10);
   qDebug()<<"serverIP: "<<serverIP<<"\tsereverPort: "<<serverPort;
   interactWithServer->connectToHost(serverIP,serverPort);
}
void ClientDialog::slot_connected_to_server()
{
    qDebug()<<"connect successful!!";
    haveGetServerInfo = true;
}
void ClientDialog::slot_disconnected_to_server()
{
    qDebug()<<"server disconnect!!";
    haveGetServerInfo = false;
}

//接收下载文件数据包
void ClientDialog::handle_fileDown(QString filename,quint32 size)
{
    qDebug()<<"recv filename: "<<filename<<"\tfilesize: "<<size;
}
ClientDialog::~ClientDialog()
{
    delete ui;
}
//接收广播命令

void ClientDialog::handle_screenBroadcast(quint32 size)
{
    QByteArray images;
    images.resize(size);
    if(size != getServer->readDatagram(images.data(),images.size()))
        return;
    QImage pic = QImage::fromData(images);
    qDebug()<<"handle recv screen broadcast pic size:  "<<pic.byteCount();
}

void ClientDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ClientDialog::on_pExit_clicked()
{
    this->close();
}
