#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QComboBox* comboBox = new QComboBox(this);
    comboBox->setGeometry(QRect(50, 50, 120, 30));
    QStringList list;
    list << tr("数学") << tr("语文") << tr("地理");
    comboBox->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

