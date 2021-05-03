#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsBlurEffect>
#include <QLabel>
#include <QPainter>

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

void MainWindow::paintEvent(QPaintEvent* /*e*/)
{
    QPainter painter(this);
    // 从下面两个矩形的位置可以看出：阴影是在label区域之外
    painter.drawRect(QRect(25, 350, 300, 20));  // x坐标和宽度相同
    painter.drawRect(QRect(350, 25, 20, 300));  // y坐标和高度相同
}
