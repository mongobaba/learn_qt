#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

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

void MainWindow::paintEvent(QPaintEvent */*e*/)
{
    QPixmap pixmap(":/new/prefix1/butterfly.png");
    QPainter painter(this);

    painter.drawRect(24, 49, 152, 152);
    painter.drawPixmap(25, 50, 150, 150, pixmap);

    painter.drawRect(199, 49, 152, 152);
    painter.shear(0.5, 0);
    painter.drawPixmap(200, 50, 150, 150, pixmap);
}
