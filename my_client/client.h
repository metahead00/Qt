#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer();
    void disconnectFromServer();
    void sendMessage(const QString& message);

signals:
    void log(const QString& message);

private slots:
    void onReadyRead();

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
