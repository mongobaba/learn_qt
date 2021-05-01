#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setGeometry(QRect(160, 50, 300, 300));

    image = new QImage();
    image->load(":/new/prefix1/butterfly.png");
    label->setPixmap(QPixmap::fromImage(*image));

    hButton = new QPushButton(tr("水平翻转"), this);
    hButton->setGeometry(QRect(50, 400, 80, 25));
    connect(hButton, SIGNAL(clicked()), this, SLOT(hShow()));

    vButton = new QPushButton(tr("垂直翻转"), this);
    vButton->setGeometry(QRect(160, 400, 80, 25));
    connect(vButton, SIGNAL(clicked()), this, SLOT(vShow()));

    angleButton = new QPushButton(tr("角度操作"), this);
    angleButton->setGeometry(QRect(270, 400, 80, 25));
    connect(angleButton, SIGNAL(clicked()), this, SLOT(angleShow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hShow()
{
    *image = image->mirrored(true, false);
    label->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::vShow()
{
    *image = image->mirrored(false, true);
    label->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::angleShow()
{
    QMatrix matrix;
    matrix.rotate(45);
    *image = image->transformed(matrix);
    label->setPixmap(QPixmap::fromImage(*image));
}
