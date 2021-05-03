#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    treeView = new QTreeView(this);
    treeView->setGeometry(QRect(50, 50, 350, 200));

    model = new QStandardItemModel(3, 2, treeView);
    model->setHeaderData(0, Qt::Horizontal, tr("第一列"));
    model->setHeaderData(1, Qt::Horizontal, tr("第二列"));

    QStandardItem* item1 = new QStandardItem(tr("数学"));
    item1->setIcon(QIcon(":/new/prefix1/folder.ico"));
    // model会管理所有的item
    model->setItem(0, 0, item1);

    QStandardItem* item2 = new QStandardItem(tr("语文"));
    item2->setIcon(QIcon(":/new/prefix1/folder.ico"));
    model->setItem(1, 0, item2);

    QStandardItem* item3 = new QStandardItem(tr("外语"));
    item3->setIcon(QIcon(":/new/prefix1/folder.ico"));
    model->setItem(2, 0, item3);

    QStandardItem* item4 = new QStandardItem(tr("外语A"));
    item4->setIcon(QIcon(":/new/prefix1/file.ico"));
    item3->appendRow(item4);

    treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

