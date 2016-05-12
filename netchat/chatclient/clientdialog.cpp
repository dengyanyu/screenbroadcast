#include <QByteArray>
#include <QHostAddress>
#include <QStringList>

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

    QStringList detailMsg = msg.split('\n');

    QString temp = detailMsg.at(0);
    if(temp != "CHATSERVER/1.0")
    {
        getServer->readAll();
        qDebug()<<"非chatsercer 协议包: \t"<<temp;
        return;
    }

    temp = detailMsg.at(2);

    temp = temp.split(" ").at(1);
    quint32 recv_len = temp.toUInt(&ok,10);
    temp = detailMsg.at(1);

    if(temp.toUInt(&ok,10) == ServerAddress)
            return handle_serveraddress(recv_len);
   // serverPort = port.toUShort(&ok,10);
    //qDebug()<<"get server port : "<<serverPort;
}
void ClientDialog::handle_serveraddress(quint32 size)
{
    QByteArray recvMsg;

    bool ok;
   recvMsg.resize(getServer->pendingDatagramSize());
   getServer->readDatagram(recvMsg.data(),recvMsg.size());
   QStringList temp = QString(recvMsg).split('#');
   serverIP = temp.at(0);
   serverPort = temp.at(1).toUInt(&ok,10);
   qDebug()<<"serverIP: "<<serverIP<<"\tsereverPort: "<<serverPort;
}
ClientDialog::~ClientDialog()
{
    delete ui;
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
