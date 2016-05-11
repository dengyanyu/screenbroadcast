#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QUdpSocket>

namespace Ui {
    class ClientDialog;
}

class ClientDialog : public QDialog {
    Q_OBJECT
public:
    ClientDialog(QWidget *parent = 0);
    ~ClientDialog();
public slots:
    void slotGetServerPort();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClientDialog *ui;
    QUdpSocket *getServer;
    quint16 serverPort ;
    bool haveGetServerInfo;

private slots:
    void on_pExit_clicked();
};

#endif // CLIENTDIALOG_H
