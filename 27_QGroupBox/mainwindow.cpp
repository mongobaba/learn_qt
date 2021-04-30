#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    group = new QGroupBox(this);
    group->setGeometry(QRect(30, 30, 340, 100));
    group->setTitle(tr("语音栏目"));

    button = new QPushButton(tr("按钮"));
    layout = new QVBoxLayout();
    layout->addWidget(button);
    group->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

