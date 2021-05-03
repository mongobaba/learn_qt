#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filePath = new QLineEdit(this);
    filePath->setGeometry(QRect(50, 50, 200, 25));

    browseButton = new QPushButton(tr("浏览文件"), this);
    browseButton->setGeometry(QRect(270, 50, 80, 25));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browseFile()));

    deleteButton = new QPushButton(tr("删除文件"), this);
    deleteButton->setGeometry(QRect(50, 100, 80, 25));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::browseFile()
{
    QString filter = tr("文本文件(*.txt);;所有文件(*.*)");
    QString str(QFileDialog::getOpenFileName(this, tr("打开文件"), "/", filter));
    filePath->setText(str);
}

void MainWindow::deleteFile()
{
    if (QFile::remove(filePath->text()))
    {
        QMessageBox::warning(this, tr("删除文件"), tr("删除文件成功！"));
    }
}
