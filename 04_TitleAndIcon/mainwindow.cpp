#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Qt窗体应用"));
    this->setWindowIcon(QIcon(":/new/prefix1/pygame.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

