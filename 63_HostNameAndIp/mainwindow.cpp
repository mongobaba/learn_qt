#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString hostName = QHostInfo::localHostName();
    qDebug() << "计算机名:" << hostName;

    QHostInfo info = QHostInfo::fromName(hostName);
    for (QHostAddress addr : info.addresses())
    {
        switch (addr.protocol())
        {
        case QAbstractSocket::IPv4Protocol:
            qDebug() << "IPV4地址：" << addr.toString();
            break;
        case QAbstractSocket::IPv6Protocol:
            qDebug() << "IPV6地址：" << addr.toString();
            break;
        default:
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

