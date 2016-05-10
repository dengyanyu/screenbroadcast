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

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ClientDialog *ui;
    QUdpSocket *getServer;
};

#endif // CLIENTDIALOG_H
