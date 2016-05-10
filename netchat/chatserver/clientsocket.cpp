#include <QDebug>
#include "clientsocket.h"

ClientSocket::ClientSocket(int fd,QObject * parent ) : QTcpSocket(parent)
{

    this->setSocketDescriptor(fd);
    QObject::connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnect()));
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
}
void ClientSocket::slotDisconnect()
{
    emit signalDisconnect(this->socketDescriptor());
}
void ClientSocket::slotReadyRead()
{
    char buf[1024] = {0};
    this->readData(buf,1024);
    qDebug()<<"recv: "<<buf;
    //发送数据可读信号
    QString msg(buf);
    emit(signalReadyRead(msg,msg.size()));
}
