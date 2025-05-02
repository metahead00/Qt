#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new Client(this);
    connect(client, &Client::log, this, &MainWindow::logMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    client->connectToServer();
}

void MainWindow::on_buttonDisconnect_clicked()
{
    client->disconnectFromServer();
}

void MainWindow::logMessage(const QString &message)
{
    ui->logBox->append(message);
}

void MainWindow::on_buttonMessage_clicked()
{
    QString message = ui->lineEdit_message->text();
    client->sendMessage(message);
}

