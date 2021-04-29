#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    // 方案一，会自动缩放，如果窗口大小不等于图片大小，可能会有一点点不清晰
    // this->setStyleSheet("border-image:url(:/new/prefix1/bkground.png)");

    // 方案二，不会缩放，清晰度不会有问题。如果把窗口调整为与图片同样大小，可以不设置background-repeat属性
    this->setStyleSheet("background-image:url(:/new/prefix1/bkground.png);background-repeat:no-repeat;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

