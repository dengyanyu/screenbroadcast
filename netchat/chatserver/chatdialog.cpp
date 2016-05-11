#include <QTcpSocket>
#include <QList>
#include <QHostAddress>
#include <QNetworkInterface>
#include "chatdialog.h"
#include "ui_chatdialog.h"

ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
    ui->pAddress->setText(this->getLocalAddress());
    QObject::connect(ui->pcreate,SIGNAL(clicked()),this,SLOT(slotCreateChat()));
    QObject::connect(ui->pexit,SIGNAL(clicked()),this,SLOT(close()));
    ui->pSendText->setEnabled(false);
    ui->pSendBtn->setEnabled(false);

}

ChatDialog::~ChatDialog()
{
    delete ui;
}
//更新消息显示界面
void ChatDialog::slotUpdateMsg(QString msg)
{
    ui->pMsgList->addItem(msg);
}
void ChatDialog::changeEvent(QEvent *e)
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
//创建网络聊天室
void ChatDialog::slotCreateChat()
{
    if(ui->pAddress->text().isEmpty() || ui->pPort->text().isEmpty())
        return;
    bool ok;
    ui->pcreate->setEnabled(false);
    ui->pAddress->setReadOnly(true);
    ui->pPort->setReadOnly(true);
    ui->pSendText->setEnabled(true);
    ui->pSendBtn->setEnabled(true);


    server = new ChatServer(QHostAddress(ui->pAddress->text()),ui->pPort->text().toUShort(&ok,10));
    QObject::connect(server,SIGNAL(signalClientInfo(QString)),this,SLOT(slotRecvClientInfo(QString)));
    QObject::connect(server,SIGNAL(signalUpdataMsg(QString)),this,SLOT(slotUpdateMsg(QString)));
    QObject::connect(server,SIGNAL(signalClientOffLine(QString)),this,SLOT(slotClientOffLine(QString)));

}

//显示客户端信息
void ChatDialog::slotRecvClientInfo(QString address)
{
    ui->pUerList->addItem(address);
}
//删除下线客户端
void ChatDialog::slotClientOffLine(QString address)
{
    this->ui->pMsgList->addItem(QObject::tr("%1 offline!").arg(address));
   QList<QListWidgetItem *> temp =  ui->pUerList->findItems(address,Qt::MatchContains);
   ui->pUerList->removeItemWidget(temp.at(0));
   delete temp.at(0);
}
QString ChatDialog::getLocalAddress()
{
    QString hostIP = "127.0.0.1";
        QList<QHostAddress> list = QNetworkInterface::allAddresses();
        foreach (QHostAddress address, list)
        {
            if(address.protocol() == QAbstractSocket::IPv4Protocol)
            {
                //IPv4地址
                if (address.toString().contains("127.0."))
                {
                    continue;
                }
                hostIP = address.toString();
            }
        }
       return hostIP;
}

