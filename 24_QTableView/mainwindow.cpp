#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView(this);
    tableView->setGeometry(QRect(50, 50, 600, 200));

    model = new QStandardItemModel(tableView);
    model->setHorizontalHeaderItem(0, new QStandardItem(tr("数学")));
    model->setHorizontalHeaderItem(1, new QStandardItem(tr("语文")));
    model->setHorizontalHeaderItem(2, new QStandardItem(tr("外语")));

    model->setItem(0, 0, new QStandardItem(tr("数学A")));
    model->setItem(0, 1, new QStandardItem(tr("语文A")));
    model->setItem(0, 2, new QStandardItem(tr("外语A")));

    model->setItem(1, 0, new QStandardItem(tr("数学B")));
    model->setItem(1, 1, new QStandardItem(tr("语文B")));
    model->setItem(1, 2, new QStandardItem(tr("外语B")));

    // 设置单元格居中显示
    for (int i = 0; i < model->rowCount(); i++)
    {
        for (int j = 0; j < model->columnCount(); j++)
        {
            model->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

