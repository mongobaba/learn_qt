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
        if (addr.protocol() == QAbstractSocket::IPv4Protocol)
        {
            qDebug() << "IPV4地址：" << addr.toString();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

