#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setMovie与ownership无关，所以这里要设置parent
    movie = new QMovie(this);
    movie->setFileName(":/new/prefix1/onedriver.gif");
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(frameChanged(int)));

    label = new QLabel(this);
    label->setGeometry(QRect(20, 20, 161, 290));
    label->setMovie(movie);

    // 开始播放动画
    movie->start();

    // 定时关闭
    // QTimer::singleShot(5 * 1000, movie, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::frameChanged(int frameNumber)
{
    // 播放完一遍后停止，也可以在第二遍的第一帧结束
    if (frameNumber == movie->frameCount() - 1)
    {
        movie->stop();
    }
}
