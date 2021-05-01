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
    scene->setForegroundBrush(QColor(0, 255, 255, 127));
    QFont font("黑体", 60);
    scene->addSimpleText("图形图像", font);

    QGraphicsView* view = new QGraphicsView(scene);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

