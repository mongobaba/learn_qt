#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

TabA::TabA(QWidget* parent) : QWidget(parent)
{
    QPushButton* button = new QPushButton(this);
    button->setText(tr("页面A"));
}

TabB::TabB(QWidget* parent) : QWidget(parent)
{
    QPushButton* button = new QPushButton(this);
    button->setText(tr("页面B"));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tabWidget = new QTabWidget(this);
    tabWidget->setGeometry(QRect(30, 30, 340, 140));
    tabWidget->addTab(new TabA(), tr("A栏目"));
    tabWidget->addTab(new TabB(), tr("B栏目"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

