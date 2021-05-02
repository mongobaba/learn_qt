#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket(QObject* parent = nullptr);

signals:
    void updateClients(QString, qint64);
    void disconnected(qintptr);

public slots:
    void dataReceived();
    void dataDisconnected();
};

#endif // TCPSOCKET_H
