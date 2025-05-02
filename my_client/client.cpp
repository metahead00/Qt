#include "client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject{parent} {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::connectToServer() {
    // address
    socket->connectToHost("127.0.0.1", 1234);
    if(!socket->waitForConnected(30000)) {
        emit log("Failed to connect to the server.");
    } else {
        emit log("Connected to server.");
    }
}

void Client::disconnectFromServer() {
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
        emit log("Disconnected from server.");
    }
}

void Client::onReadyRead() {
    QString message = QString::fromUtf8(socket->readAll());
    emit log("Server said: " + message);
}

void Client::sendMessage(const QString& message) {
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());
        socket->flush();
    } else {
        emit log("Not connected.");
    }
}
