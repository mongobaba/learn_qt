#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filePath = new QLineEdit(this);
    filePath->setGeometry(QRect(50, 50, 200, 25));
    filePath->setText(tr("D:/testdir/write.txt"));

    content = new QLineEdit(this);
    content->setGeometry(QRect(50, 100, 200, 25));
    content->setText(tr("要写入文件的内容"));

    button = new QPushButton(tr("写入"), this);
    button->setGeometry(QRect(270, 50, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(writeFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeFile()
{
    QFile file(filePath->text());
    if (file.exists())
    {
        QMessageBox::warning(this, tr("创建文件"), tr("文件已经存在！"));
    }
    else
    {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QByteArray bytes = content->text().toUtf8();
        file.write(bytes);
        file.flush();
        QMessageBox::warning(this, tr("创建文件"), tr("写入文件成功！"));
    }
}
