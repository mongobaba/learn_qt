#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextEdit* textEdit = new QTextEdit(this);
    textEdit->setGeometry(QRect(50, 50, 200, 150));

    // 方案一
    // textEdit->setText(tr("我是第一行<br/>我是第二行"));

    // 方案二
    textEdit->setText(tr("我是第一行\n我是第二行"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

