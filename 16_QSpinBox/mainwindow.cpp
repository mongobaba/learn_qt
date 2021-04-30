#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSpinBox* spinBox = new QSpinBox(this);
    spinBox->setGeometry(QRect(50, 50, 100, 25));
    spinBox->setRange(0, 200);
    spinBox->setValue(10);
    spinBox->setPrefix(tr("金额"));
    spinBox->setSuffix(tr("元"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

