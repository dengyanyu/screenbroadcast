#include <QtGui/QApplication>
#include "clientdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientDialog w;
    w.show();
    return a.exec();
}
