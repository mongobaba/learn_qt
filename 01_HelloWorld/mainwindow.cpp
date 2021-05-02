#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel* label = new QLabel(this);
    label->setText("Hello, world");
    // 方式一，其实也是调用下面的形式
    // label->setGeometry(50, 50, 200, 25);
    // 方式二
    label->setGeometry(QRect(50, 50, 200, 25));
}

MainWindow::~MainWindow()
{
    delete ui;
}

