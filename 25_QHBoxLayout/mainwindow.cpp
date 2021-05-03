#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout = new QHBoxLayout();
    layout->setSpacing(60);

    for (int i = 1; i <= 3; ++i)
    {
        QString text = tr("按钮") + QString::number(i);
        layout->addWidget(new QPushButton(text));
    }

    widget = new QWidget();
    // 或者将widget传给layout的构造函数
    // setLayout会改变parent
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

