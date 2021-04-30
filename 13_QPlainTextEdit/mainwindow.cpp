#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPlainTextEdit* textEdit = new QPlainTextEdit(this);
    textEdit->setGeometry(QRect(50, 50, 200, 100));

    // 不换行，<br/>原样输出
    // textEdit->setPlainText(tr("第一行<br/>第二行"));

    // 正常换行
    textEdit->setPlainText(tr("第一行\n第二行"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

