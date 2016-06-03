#include <QTcpSocket>
<<<<<<< HEAD
#include <QDataStream>
=======
>>>>>>> 9f28b1457708a01ace051446a6878624eb12c0e8
#include <QImage>
#include <QStringList>
#include <QFile>
#include "clientsocket.h"
#include "chatserver.h"

ChatServer::ChatServer(const QHostAddress & address, quint16 port,QObject * parent ):QTcpServer(parent)
{
    this->listen(address,port);
    this->port = port;
    serverIP = address.toString();
    timeForSendServerInfo = new QTimer(this);
    QObject::connect(this->timeForSendServerInfo,SIGNAL(timeout()),this,SLOT(slotSendServerInfo()));
     broadcastPort = 7777;
    sendServerInfo = new QUdpSocket;
<<<<<<< HEAD
    timeForSendServerInfo->start(1000);
=======
    //timeForSendServerInfo->start(1000);
>>>>>>> 9f28b1457708a01ace051446a6878624eb12c0e8
}
QString ChatServer::setBroadcastMsg(MsgType type, quint32 size, QString filename)
{
    QString head(QObject::tr("CHATSERVER/1.0"));
    head.append('\n');
    head.append(QObject::tr("Content-type: %1").arg(type)).append('\n');
    head.append(QObject::tr("Filename: %1").arg(filename)).append('\n');
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
<<<<<<< HEAD
void ChatServer::sendImageGroup(QByteArray &data)
{

    if(clientList.size() == 0)
        return;
    for(int i = 0;i < clientList.size();++i)
        clientList.at(i)->write(data.data(),data.size());
}
=======
>>>>>>> 9f28b1457708a01ace051446a6878624eb12c0e8
void ChatServer::sendMsgGroup(QString msg)
{
    if(clientList.size() == 0)
        return;
    for(int i = 0;i < clientList.size();++i)
        clientList.at(i)->write(msg.toLatin1())   ;
}
//发送下载文件命令
void ChatServer::slotSendFileDown(QStringList fileNames)
{
    if(fileNames.isEmpty())
        return;
      qDebug()<<"select numb: "<<fileNames.size()<<"\tlist: "<<fileNames.at(0);
      QFile file;
       QString head;
      for(int i = 0;i < fileNames.size();++i)
      {
            file.setFileName(fileNames.at(i));
            if(!file.open(QIODevice::ReadOnly))
            {
                qDebug()<<"open  file: "<<file.fileName()<<"  failed!!!,errno: "<<file.errorString();
                continue;
            }
            //发送协议头
            head = this->setBroadcastMsg(File,file.size(),file.fileName());
            sendServerInfo->writeDatagram(head.toAscii(),QHostAddress::Broadcast,broadcastPort);

            //发送文件内容

            qDebug()<<"head  = "<<head<<endl;
      }
}

//发送屏幕广播
void ChatServer::slotSendScreenBroadcast(QImage image)
{
<<<<<<< HEAD

    QByteArray temp;
    //发送协议头
    temp = this->setBroadcastMsg(Image,image.byteCount()).toLatin1();
    //发送图片
    temp.append((const char *)image.bits(),image.byteCount());
    this->sendImageGroup(temp);
    qDebug()<<"slot send broadcast image size = "<<temp.size()<<endl;
=======
    QString head;
    QByteArray temp;
    temp = temp.
    //发送协议头
    head = this->setBroadcastMsg(Image,image.byteCount());
    sendServerInfo->writeDatagram(head.toAscii(),QHostAddress::Broadcast,broadcastPort);

    //发送图片

    sendServerInfo->writeDatagram(image.bits(),image.byteCount(),QHostAddress::Broadcast,broadcastPort);
    qDebug()<<"slot send broadcast image size = "<<image.byteCount()<<endl;
>>>>>>> 9f28b1457708a01ace051446a6878624eb12c0e8
}


