#include "mainwindow.h"
#include "server.h"
#include "client.h"
#include <QApplication>

/*
send message butonu aslinda set message
client connect yapinca set messagedaki message terminalde gozukuyor

---------to do----------
1. split client and server
2. update component names
3. logging
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
