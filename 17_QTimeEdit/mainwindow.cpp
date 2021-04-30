#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimeEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimeEdit* timeEdit = new QTimeEdit(this);
    timeEdit->setGeometry(QRect(50, 50, 120, 25));
    // QTimeEdit默认不会显示秒
    timeEdit->setDisplayFormat("hh:mm:ss");
    QDateTime sysTime = QDateTime::currentDateTime();
    timeEdit->setTime(sysTime.time());
}

MainWindow::~MainWindow()
{
    delete ui;
}

