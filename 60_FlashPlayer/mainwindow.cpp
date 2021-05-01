#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAxWidget>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAxWidget* flash = new QAxWidget();
    // 系统没装Flash，跑不出效果来，代码仅供参考
    if (flash->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")))
    {
        flash->dynamicCall("LoadMovie(long,string)", 0, "D:/testdir/1.swf");
    }

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(flash);

    QWidget* widget = new QWidget();
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

