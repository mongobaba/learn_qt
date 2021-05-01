#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsBlurEffect>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* text = new QLabel(tr("背景文字"), this);
    text->setGeometry(QRect(60, 80, 80, 50));

    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(0.5);

    QLabel* label = new QLabel(this);
    label->setGeometry(QRect(25, 25, 300, 300));
    label->setPixmap(QPixmap(":/new/prefix1/butterfly.png"));

    // 注释此行代码查看差异
    label->setGraphicsEffect(effect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

