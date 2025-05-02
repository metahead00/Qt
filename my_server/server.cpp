#include "server.h"
#include <QDebug>

Server::Server(QObject* parent) : QObject(parent) {
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &Server::onNewConn);
}

void Server::startServer() {
    if(!server->listen(QHostAddress::Any, 1234)) {
        emit log("Server failed to start");
    } else {
        emit log("Server started");
    }
}

void Server::onNewConn() {
    clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);

    emit log("Client connected.");
    clientSocket->flush();
}

void Server::stopServer() {
    if(server->isListening()) {
        server->close();
        emit log("Server closed");
    }
}

void Server::onReadyRead() {
    QString message = QString::fromUtf8(clientSocket->readAll());
    emit log("Client said: " + message);
}

void Server::sendMessage(const QString& message) {
    if (clientSocket && clientSocket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(message.toUtf8());
        clientSocket->flush();
    } else {
        emit log("Not connected.");
    }
}

