#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
 #include <QUdpSocket>
#include <QTimer>
#include <QStringList>
#include <QList>
#include <QImage>
#include "clientsocket.h"

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    enum	MsgType { ServerAddress,File,Image};
    ChatServer(const QHostAddress & address, quint16 port,QObject * parent = 0);
   void  sendMsgGroup(QString msg);
<<<<<<< HEAD
   void sendImageGroup(QByteArray & data);
=======
>>>>>>> 9f28b1457708a01ace051446a6878624eb12c0e8
   QString setBroadcastMsg(MsgType type,quint32 size,QString filename=QString());
public slots:
        void slotReadyRead(QString msg,int len);
        void slotDisconnect(int fd);
         void slotSendServerInfo();
         void slotSendFileDown(QStringList fileNames);
         void slotSendScreenBroadcast(QImage image);

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
        quint16 broadcastPort;
        QString serverIP;


};

#endif // CHATSERVER_H
