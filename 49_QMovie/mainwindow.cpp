#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMovie>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this);
    label->setGeometry(QRect(20, 20, 161, 290));
    QMovie* movie = new QMovie(":/new/prefix1/onedriver.gif");
    QTimer::singleShot(3 * 1000, label, SLOT(close()));
    label->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

