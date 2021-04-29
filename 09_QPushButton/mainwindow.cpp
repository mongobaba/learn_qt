#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button = new QPushButton(tr("按钮A"), this);
    button->setGeometry(QRect(100, 100, 100, 25));
    connect(button, SIGNAL(released()), this, SLOT(txtButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::txtButton()
{
    button->setText(tr("按钮B"));
}
