#include "mainwindow.h"
#include "tcpserver.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateServer(QString message, qint64 length)
{
    int n = static_cast<int>(length);
    ui->listWidget->addItem(message.left(n).trimmed());
}

void MainWindow::on_startButton_clicked()
{
    server = new TcpServer(this, 8010);
    connect(server, SIGNAL(updateServer(QString, qint64)), this, SLOT(updateServer(QString, qint64)));
    ui->startButton->setEnabled(false);
}

void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}
