#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 200, 25));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QDateTime sysTime = QDateTime::currentDateTime();
    label->setText(sysTime.toString());
}
