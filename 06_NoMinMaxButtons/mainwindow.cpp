#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 保留最大最小按钮，但是关闭按钮失效
    // this->setWindowFlags(Qt::WindowMinMaxButtonsHint);

    // 保留关闭按钮，没有最大最小按钮
    this->setWindowFlags(Qt::WindowCloseButtonHint);

    // 默认窗口样式至少有这两个
    // this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

