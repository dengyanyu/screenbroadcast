#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include "clientsocket.h"

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    ChatServer(const QHostAddress & address, quint16 port,QObject * parent = 0);
   void  sendMsgGroup(QString msg);
public slots:
        void slotReadyRead(QString msg,int len);
        void slotDisconnect(int fd);
protected:
         void	incomingConnection ( int socketDescriptor );
signals:
    void signalClientInfo(QString address);
    void signalUpdataMsg(QString msg);
    void signalClientOffLine(QString address);
private:
        QList<ClientSocket *> clientList;


};

#endif // CHATSERVER_H
