#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsBlurEffect>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect(this);
    effect->setColor(QColor(0, 0, 192));

    QLabel* label = new QLabel(this);
    label->setGeometry(QRect(25, 25, 300, 300));
    label->setPixmap(QPixmap(":/new/prefix1/butterfly.png"));
    label->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

