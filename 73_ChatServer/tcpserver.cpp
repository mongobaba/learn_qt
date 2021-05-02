#include "tcpserver.h"
#include "tcpsocket.h"

TcpServer::TcpServer(QObject* parent, int port)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any, port);
}

void TcpServer::incomingConnection(qintptr handle)
{
    TcpSocket* sock = new TcpSocket(this);
    connect(sock, SIGNAL(updateClients(QString, qint64)), this, SLOT(updateClients(QString, qint64)));
    connect(sock, SIGNAL(disconnected(qintptr)), this, SLOT(tcpDisconnected(qintptr)));
    sock->setSocketDescriptor(handle);
    sockList.append(sock);
}

void TcpServer::updateClients(QString message, qint64 length)
{
    emit updateServer(message, length);
    for (int i = 0; i < sockList.count(); ++i)
    {
        QTcpSocket* tmp = sockList.at(i);
        if (tmp->write(message.toLatin1(), length) != length)
        {
            continue;
        }
    }
}

void TcpServer::tcpDisconnected(qintptr handle)
{
    for (int i = 0; i < sockList.count(); ++i)
    {
        QTcpSocket* tmp = sockList.at(i);
        if (tmp->socketDescriptor() == handle)
        {
            sockList.removeAt(i);
            return;
        }
    }
}
