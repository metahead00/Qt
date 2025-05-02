#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new Server(this);
    connect(server, &Server::log, this, &MainWindow::logMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logMessage(const QString &message)
{
    ui->logBox->append(message);
}

void MainWindow::on_buttonStartServer_clicked()
{
    server->startServer();
}

void MainWindow::on_buttonStopServer_clicked()
{
    server->stopServer();
}

void MainWindow::on_buttonMessage_clicked()
{
    QString message = ui->lineEdit_message->text();
    server->sendMessage(message);
}

