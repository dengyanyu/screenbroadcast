#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QUdpSocket>
#include <QTcpSocket>

namespace Ui {
    class ClientDialog;
}

class ClientDialog : public QDialog {
    Q_OBJECT
public:
    ClientDialog(QWidget *parent = 0);
    ~ClientDialog();
    enum	MsgType { ServerAddress,File,Image};
    void handle_serveraddress(quint32 size);
    void handle_fileDown(QString filename,quint32 size);
public slots:
    void slotGetServerPort();
    void slot_connected_to_server();
     void slot_disconnected_to_server();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClientDialog *ui;
    //用于接收广播数据的套接字
    QUdpSocket *getServer;
    //用于连接服务器的套接字
    QTcpSocket *interactWithServer;
    quint16 serverPort ;
    QString serverIP;
    bool haveGetServerInfo;

private slots:
    void on_pExit_clicked();
};

#endif // CLIENTDIALOG_H
