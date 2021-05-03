#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , index(0)
{
    ui->setupUi(this);

    // 只有两张图片，所以简单逐条加载
    pixmap[0].load(":/new/prefix1/0.png");
    pixmap[1].load(":/new/prefix1/1.png");

    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 250, 80));
    label->setPixmap(pixmap[0]);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeImage()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeImage()
{
    index = (index + 1) & 1;
    label->setPixmap(pixmap[index]);
}
