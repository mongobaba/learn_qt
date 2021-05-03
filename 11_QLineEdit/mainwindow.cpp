#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(100, 100, 250, 25));
    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color:blue red;");
    lineEdit->setMaxLength(12);
    lineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

