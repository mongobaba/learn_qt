#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scrollBar = new QScrollBar(this);
    scrollBar->setOrientation(Qt::Horizontal);
    scrollBar->setGeometry(QRect(50, 50, 180, 20));
    scrollBar->setPageStep(10);

    spinBox = new QSpinBox(this);
    spinBox->setGeometry(QRect(50, 90, 100, 25));

    connect(scrollBar, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), scrollBar, SLOT(setValue(int)));

    // 需要放在connect之后
    scrollBar->setValue(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

