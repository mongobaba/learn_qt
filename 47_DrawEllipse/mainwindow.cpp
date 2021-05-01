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
    scene->addEllipse(50, 50, 100, 120);

    QGraphicsView* view = new QGraphicsView(scene);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

