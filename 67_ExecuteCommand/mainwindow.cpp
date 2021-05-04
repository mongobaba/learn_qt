#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    command = new QLineEdit(this);
    command->setText(tr("ipconfig"));
    command->setGeometry(QRect(20, 20, 400, 25));

    execute = new QPushButton(tr("执行"), this);
    execute->setGeometry(QRect(430, 20, 90, 25));
    connect(execute, SIGNAL(clicked()), this, SLOT(executeCommand()));

    output = new QPlainTextEdit(this);
    output->setGeometry(QRect(20, 60, 500, 400));

    process = new QProcess();
    connect(process, SIGNAL(readyRead()), this, SLOT(readOutput()));

    // label是完全独立的演示，跟其他部分没关系
    label = new QLabel(this);
    label->setGeometry(QRect(30, 470, 200, 24));
    label->setText(tr("<a href=\"http://www.baidu.com/s?wd=dos 命令大全\">命令 DOS 查阅</a>"));
    label->setOpenExternalLinks(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::executeCommand()
{
    // 执行前清空result和output内容，避免多次执行时信息叠加
    result.clear();
    output->setPlainText(result);
    QString cmd = command->text();
    process->start(cmd);
}

void MainWindow::readOutput()
{
    // 进程输出为本地编码，需要转换
    result += QString::fromLocal8Bit(process->readAll());
    output->setPlainText(result);
}
