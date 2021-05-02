#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    command = new QLineEdit(this);
    command->setText(tr("ipconfig"));
    command->setGeometry(QRect(20, 20, 260, 25));

    execute = new QPushButton(tr("执行"), this);
    execute->setGeometry(QRect(290, 20, 80, 25));
    connect(execute, SIGNAL(clicked()), this, SLOT(executeCommand()));

    output = new QPlainTextEdit(this);
    output->setGeometry(QRect(20, 60, 350, 200));

    process = new QProcess();
    connect(process, SIGNAL(readyRead()), this, SLOT(readOutput()));

    label = new QLabel(this);
    label->setGeometry(QRect(30, 265, 200, 25));
    label->setText(tr("<a href=\"http://www.baidu.com/s?wd=dos 命令大全\">命令 DOS 查阅</a>"));
    label->setOpenExternalLinks(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::executeCommand()
{
    QString cmd = command->text();
    process->start(cmd);
    output->setPlainText(result);
}

void MainWindow::readOutput()
{
    result += QString::fromLocal8Bit(process->readAll());
    output->setPlainText(result);
}
