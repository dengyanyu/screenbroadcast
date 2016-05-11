#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
 #include <QUdpSocket>
#include <QTimer>
#include <QList>
#include "clientsocket.h"

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    ChatServer(const QHostAddress & address, quint16 port,QObject * parent = 0);
   void  sendMsgGroup(QString msg);
   QString setBroadcastMsg(QString type,quint32 size,QString filename=QString());
public slots:
        void slotReadyRead(QString msg,int len);
        void slotDisconnect(int fd);
         void slotSendServerInfo();

protected:
         void	incomingConnection ( int socketDescriptor );
signals:
    void signalClientInfo(QString address);
    void signalUpdataMsg(QString msg);
    void signalClientOffLine(QString address);

private:
        QList<ClientSocket *> clientList;
        QTimer *timeForSendServerInfo;
        QUdpSocket  *sendServerInfo;
        quint16 port;
        QString serverIP;


};

#endif // CHATSERVER_H
