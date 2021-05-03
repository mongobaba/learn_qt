#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr int MaxValue = 100000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bar = new QProgressBar(this);
    bar->setGeometry(QRect(50, 50, 200, 23));
    bar->setRange(0, MaxValue - 1);
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
    button->setEnabled(false);
    for (int i = 0; i < MaxValue; i++)
    {
        bar->setValue(i);
    }
    button->setEnabled(true);
}
