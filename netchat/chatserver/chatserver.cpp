#include <QTcpSocket>
#include "clientsocket.h"
#include "chatserver.h"

ChatServer::ChatServer(const QHostAddress & address, quint16 port,QObject * parent ):QTcpServer(parent)
{
    this->listen(address,port);
    this->port = port;
    serverIP = address.toString();
    timeForSendServerInfo = new QTimer(this);
    QObject::connect(this->timeForSendServerInfo,SIGNAL(timeout()),this,SLOT(slotSendServerInfo()));
    sendServerInfo = new QUdpSocket;
    timeForSendServerInfo->start(1000);
}
QString ChatServer::setBroadcastMsg(MsgType type, quint32 size, QString filename)
{
    QString head("CHATSERVER/1.0");
    head.append('\n');
    head.append(QObject::tr("Content-type: %1").arg(type)).append('\n');
    head.append(QObject::tr("Content-size: %1").arg(size)).append('\n');
    head.append('\r').append('\n');
    return head;

}
void ChatServer::incomingConnection(int socketDescriptor)
{
     ClientSocket *client = new ClientSocket( socketDescriptor);
    clientList.append(client);
    emit signalClientInfo(client->peerAddress().toString());
    QObject::connect(client,SIGNAL(signalDisconnect(int)),this,SLOT(slotDisconnect(int)));
    QObject::connect(client,SIGNAL(signalReadyRead(QString,int)),this,SLOT(slotReadyRead(QString,int)));
}
//每隔100ms发送一次服务器的端口号
void ChatServer::slotSendServerInfo()
{
    QString serverPort(QObject::tr("%1").arg(port));
    quint16 broadcastPort = 7777;
    QString msg(QObject::tr("%1#%2").arg(serverIP).arg(serverPort));
    QString head = this->setBroadcastMsg(ServerAddress,msg.size());

    //发送协议头
    sendServerInfo->writeDatagram(head.toAscii(),QHostAddress::Broadcast,broadcastPort);

    //发送数据
    sendServerInfo->writeDatagram(msg.toAscii(),QHostAddress::Broadcast,broadcastPort);
    timeForSendServerInfo->start(1000);
    qDebug()<<"SendServerInfo :  "<<serverPort;
}
void ChatServer::slotReadyRead(QString msg,int len)
{
	//接收客户端发送的数据
        qDebug()<<"charserver recv: "<<msg;
         //发送给界面
          emit signalUpdataMsg(msg);
         //群发该消息
          sendMsgGroup(msg);
}
void ChatServer::slotDisconnect(int fd)
{
    ClientSocket *p = NULL;
    for (int i = 0; i < clientList.size(); ++i)
    {
          p = clientList.at(i);
          if(p->socketDescriptor() == fd)
          {
              //客户端链表中删除该客户端
              clientList.removeAt(i);
              //发送离线客户端的IP
              qDebug()<<"charserver: client leave ip:"<<p->peerAddress().toString();
              emit signalClientOffLine(p->peerAddress().toString());
              //群发离线信息
              QString msg = QObject::tr("%1 off line!").arg(p->peerAddress().toString());
              sendMsgGroup(msg);
              break;
          }
     }
}
void ChatServer::sendMsgGroup(QString msg)
{
    if(clientList.size() == 0)
        return;
    for(int i = 0;i < clientList.size();++i)
        clientList.at(i)->write(msg.toLatin1())   ;
}
