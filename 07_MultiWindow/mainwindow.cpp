#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pushButton = new QPushButton(this);
    pushButton->setGeometry(QRect(50, 50, 100, 25));
    pushButton->setText(tr("按钮"));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(showMainWindow2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMainWindow2()
{
    w2.show();
}
