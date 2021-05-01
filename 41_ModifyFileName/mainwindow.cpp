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

    newName = new QLineEdit(this);
    newName->setGeometry(QRect(50, 90, 200, 25));
    newName->setText(tr("新名称.txt"));

    browseButton = new QPushButton(tr("浏览"), this);
    browseButton->setGeometry(QRect(270, 50, 80, 25));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browseFile()));

    renameButton = new QPushButton(tr("重命名"), this);
    renameButton->setGeometry(QRect(270, 90, 80, 25));
    connect(renameButton, SIGNAL(clicked()), this, SLOT(renameFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::browseFile()
{
    const char* filter = "text file(*.txt);;C file(*.cpp);;All file(*.*)";
    QString str(QFileDialog::getOpenFileName(this, tr("open file"), "/", filter));
    filePath->setText(str);
}

void MainWindow::renameFile()
{
    QFileInfo fileInfo(filePath->text());
    QString dir(fileInfo.absolutePath());
    if (QFile::rename(filePath->text(), dir + "/" + newName->text()))
    {
        QMessageBox::warning(this, tr("修改文件名"), tr("修改文件名成功！"));
    }
    else
    {
        QMessageBox::warning(this, tr("修改文件名"), tr("修改文件名失败！"));
    }
}
