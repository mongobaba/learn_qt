#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileName = new QLineEdit(this);
    fileName->setGeometry(QRect(50, 50, 450, 25));
    button = new QPushButton(tr("浏览"), this);
    button->setGeometry(QRect(520, 50, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(showFiles()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFiles()
{
    QString filter(tr("文本文件(*.txt);;C/C++文件(*.cpp);;所有文件(*.*)"));
    // 这里的"/"在Windows系统下会指向磁盘（例如D盘）根目录
    QString str = QFileDialog::getOpenFileName(this, tr("打开文件"), "/", filter);
    fileName->setText(str);
}
