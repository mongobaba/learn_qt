#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsBlurEffect>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(8, 8);

    QLabel* label = new QLabel(this);
    label->setGeometry(QRect(25, 25, 300, 300));
    label->setPixmap(QPixmap(":/new/prefix1/butterfly.png"));
    label->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

