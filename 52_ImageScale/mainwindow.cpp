#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setGeometry(QRect(160, 50, 300, 300));

    image.load(":/new/prefix1/butterfly.png");
    label->setPixmap(QPixmap::fromImage(image));

    larger = new QPushButton(tr("放大"), this);
    larger->setGeometry(QRect(50, 400, 80, 25));
    connect(larger, SIGNAL(clicked()), this, SLOT(showLarger()));

    smaller = new QPushButton(tr("缩小"), this);
    smaller->setGeometry(QRect(260, 400, 80, 25));
    connect(smaller, SIGNAL(clicked()), this, SLOT(showSmaller()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLarger()
{
    QSize size = image.size();
    image = image.scaled(2 * size.width(), 2 * size.height(), Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::showSmaller()
{
    QSize size = image.size();
    image = image.scaled(size.width() / 2, size.height() / 2, Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(image));
}
