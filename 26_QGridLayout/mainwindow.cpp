#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout = new QGridLayout();
    layout->addWidget(new QPushButton(tr("按钮1")), 0, 0, 1, 1);
    layout->addWidget(new QPushButton(tr("按钮2")), 0, 1, 1, 1);
    layout->addWidget(new QPushButton(tr("按钮3")), 1, 0, 1, 1);

    widget = new QWidget();
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

