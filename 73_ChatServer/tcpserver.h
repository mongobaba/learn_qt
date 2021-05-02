#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject* parent = nullptr, int port = 0);

signals:
    void updateServer(QString, qint64);

protected:
    void incomingConnection(qintptr handle) override;

private slots:
    void updateClients(QString message, qint64 length);
    void tcpDisconnected(qintptr handle);

private:
    QList<QTcpSocket*> sockList;
};

#endif // TCPSERVER_H
