#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new QLabel(tr("我是QLabel"), this);
    label->setGeometry(QRect(100, 100, 200, 30));
    label->setStyleSheet("font-size:20px;color:red;font-weight:bold;font-style:italic;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

