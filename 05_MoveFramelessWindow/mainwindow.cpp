#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 方案一，直接设置单独的flag
    // this->setWindowFlag(Qt::FramelessWindowHint);

    // 方案二，一口气设置所有flags
    this->setWindowFlags(Qt::FramelessWindowHint);

    btnClose = new QPushButton(this);
    btnClose->setText(tr("close"));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    lastPoint = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    int dx = event->globalX() - lastPoint.x();
    int dy = event->globalY() - lastPoint.y();
    move(x() + dx, y() + dy);
    lastPoint = event->globalPos();
}
