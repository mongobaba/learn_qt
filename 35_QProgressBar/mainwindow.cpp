#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bar = new QProgressBar(this);
    bar->setGeometry(QRect(50, 50, 200, 20));
    bar->setRange(0, 10000-1);
    bar->setValue(0);

    button = new QPushButton(tr("开始"), this);
    button->setGeometry(QRect(270, 50, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(startBar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startBar()
{
    for (int i = 0; i < 10000; i++)
    {
        if (i == 9999)
        {
            button->setText(tr("结束"));
        }
        bar->setValue(i);
    }
}
