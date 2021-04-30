#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimeEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateEdit* dateEdit = new QDateEdit(this);
    dateEdit->setGeometry(QRect(50, 50, 120, 25));
    QDateTime sysTime = QDateTime::currentDateTime();
    dateEdit->setDate(sysTime.date());
}

MainWindow::~MainWindow()
{
    delete ui;
}

