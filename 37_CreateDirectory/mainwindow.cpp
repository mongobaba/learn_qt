#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(50, 50, 200, 25));
    lineEdit->setText(tr("D:\\testdir"));

    button = new QPushButton(tr("创建"), this);
    button->setGeometry(QRect(280, 50, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(createFolder()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFolder()
{
    QDir* dir = new QDir();
    bool exist = dir->exists(lineEdit->text());
    if (exist)
    {
        QMessageBox::warning(this, tr("创建文件夹"), tr("文件夹已经存在！"));
    }
    else
    {
        bool ok = dir->mkdir(lineEdit->text());
        if (ok)
        {
            QMessageBox::warning(this, tr("创建文件夹"), tr("文件夹创建成功！"));
        }
        else
        {
            QMessageBox::warning(this, tr("创建文件夹"), tr("文件夹创建失败！"));
        }
    }
}
