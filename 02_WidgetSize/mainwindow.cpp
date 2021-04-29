#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Qt窗体应用"));

    // 方案一
    // this->setMaximumSize(300, 300);
    // this->setMinimumSize(300, 300);

    // 方案二
    this->setFixedSize(300, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

