#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene();
    // 切换下面两行代码查看背景色和前景色的差异
    // scene->setBackgroundBrush(QColor(0, 255, 255, 127));
    scene->setForegroundBrush(QColor(0, 255, 255, 127));
    QFont font(tr("黑体"), 60);
    scene->addSimpleText(tr("图形图像"), font);

    QGraphicsView* view = new QGraphicsView(scene);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

