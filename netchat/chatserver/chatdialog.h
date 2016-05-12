#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QList>
#include <QTimer>
#include "chatserver.h"

namespace Ui {
    class ChatDialog;
}

class ChatDialog : public QDialog {
    Q_OBJECT
public:
    ChatDialog(QWidget *parent = 0);
    ~ChatDialog();

protected:
    void changeEvent(QEvent *e);
public slots:
    void slotCreateChat();
    void slotRecvClientInfo(QString address);
    void slotUpdateMsg(QString msg);
    void slotClientOffLine(QString address);
    QString getLocalAddress();


private:
    Ui::ChatDialog *ui;
    ChatServer *server;



private slots:
    void on_psendDir_clicked();
    void on_pSendBtn_clicked();
};

#endif // CHATDIALOG_H
