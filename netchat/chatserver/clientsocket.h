#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QTcpSocket>

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(int fd,QObject * parent = 0);
public slots:
    void slotDisconnect();
    void slotReadyRead();
signals:
    void signalDisconnect(int fd);
    void signalReadyRead(QString msg,int len);
};

#endif // CLIENTSOCKET_H
