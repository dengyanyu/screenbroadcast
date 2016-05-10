#include <QByteArray>
#include <QHostAddress>
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


}
//接收服务器发来的广播消息---端口号
void ClientDialog::slotGetServerPort()
{
     QByteArray port;
     bool ok;
    while(getServer->hasPendingDatagrams())
     {
            port.resize(getServer->pendingDatagramSize());
            getServer->readDatagram(port.data(), port.size());
            serverPort = port.toUShort(&ok,10);
            qDebug()<<"get server port : "<<serverPort;
      }

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
