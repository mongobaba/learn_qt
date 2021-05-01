#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    urlLabel = new QLabel(tr("网址"), this);
    urlLabel->setGeometry(QRect(40, 50, 50, 25));

    urlLineEdit = new QLineEdit(this);
    urlLineEdit->setGeometry(QRect(100, 50, 150, 25));
    urlLineEdit->setText(tr("www.baidu.com"));

    button = new QPushButton(tr("查询"), this);
    button->setGeometry(QRect(280, 50, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(sendUrl()));

    ipLabel = new QLabel(this);
    ipLabel->setGeometry(QRect(100, 90, 150, 25));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendUrl()
{
    QHostInfo::lookupHost(urlLineEdit->text(), this, SLOT(lookup(const QHostInfo&)));
}

void MainWindow::lookup(const QHostInfo& info)
{
    ipLabel->setText(info.addresses().first().toString());
}
