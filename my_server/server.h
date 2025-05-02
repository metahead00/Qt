#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = nullptr);
    void startServer();
    void stopServer();
    void sendMessage(const QString& message);

signals:
    void log(const QString& message);

private slots:
    void onNewConn();
    void onReadyRead();

private:
    QTcpServer* server;
    // later, change this to an array
    QTcpSocket* clientSocket = nullptr;
};

#endif // SERVER_H
