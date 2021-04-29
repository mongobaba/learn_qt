#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(100, 100);

    // 方案一
    // this->setStyleSheet("background:red");

    // 方案二
    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::red);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

