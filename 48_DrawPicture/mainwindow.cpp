#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(800, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* /*e*/)
{
    QPixmap image(":/new/prefix1/logo.png");
    QPainter painter(this);
    painter.drawPixmap(12, 12, image.width(), image.height(), image);
}
