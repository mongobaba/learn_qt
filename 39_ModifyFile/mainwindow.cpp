#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    edit = new QTextEdit(this);
    edit->setGeometry(QRect(50, 50, 240, 26));

    content = new QTextEdit(this);
    content->setGeometry(QRect(50, 80, 320, 150));

    browseButton = new QPushButton(tr("浏览文件"), this);
    browseButton->setGeometry(QRect(290, 50, 80, 25));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browseFile()));

    saveButton = new QPushButton(tr("保存"), this);
    saveButton->setGeometry(QRect(290, 240, 80, 25));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::browseFile()
{
    QString filter = tr("文本文件(*.txt);;所有文件(*.*)");
    QString str(QFileDialog::getOpenFileName(this, tr("打开文件"), "/", filter));
    edit->setText(str);
    if (!str.isEmpty())
    {
        QFile file(str);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            // 需要与文件编码保持一致，否则可能乱码
            stream.setCodec("UTF-8");
            content->setPlainText(stream.readAll());
        }
        else
        {
            QMessageBox::warning(this, tr("打开文件"), tr("打开文件失败！"));
        }
    }
}

void MainWindow::saveFile()
{
    QFile file(edit->toPlainText());
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        file.write(content->toPlainText().toUtf8());
        file.flush();
        QMessageBox::warning(this, tr("修改文件"), tr("文件修改成功！"));
    }
    else
    {
        QMessageBox::warning(this, tr("修改文件"), tr("文件打开失败！"));
    }
}
