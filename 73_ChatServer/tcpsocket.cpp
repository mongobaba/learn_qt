#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject* parent)
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(this, SIGNAL(disconnected()), this, SLOT(dataDisconnected()));
}

void TcpSocket::dataReceived()
{
    while (bytesAvailable() > 0)
    {
        char buf[1024];
        qint64 length = bytesAvailable();
        read(buf, length);
        QString message = buf;
        emit updateClients(message, length);
    }
}

void TcpSocket::dataDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
