#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileLabel = new QLabel(tr("ini文件完整路径"));
    filePath = new QLineEdit(tr("D:/testdir/config.ini"));

    nodeLabel = new QLabel(tr("节点名"));
    nodeName = new QLineEdit("node");

    keyLabel = new QLabel(tr("键"));
    key = new QLineEdit("ip");

    valueLabel = new QLabel(tr("值"));
    value = new QLineEdit();

    button = new QPushButton(tr("读取文件"));
    connect(button, SIGNAL(clicked()), this, SLOT(readFile()));

    layout = new QGridLayout();
    layout->addWidget(fileLabel, 0, 0, 1, 1);
    layout->addWidget(filePath, 0, 1, 1, 4);
    layout->addWidget(nodeLabel, 1, 0, 1, 1);
    layout->addWidget(nodeName, 1, 1, 1, 1);
    layout->addWidget(keyLabel, 2, 0, 1, 1);
    layout->addWidget(key, 2, 1, 1, 1);
    layout->addWidget(valueLabel, 2, 3, 1, 1);
    layout->addWidget(value, 2, 4, 1, 1);
    layout->addWidget(button, 3, 4, 1, 1);

    widget = new QWidget();
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QSettings settings(filePath->text(), QSettings::IniFormat);
    QString str = settings.value(nodeName->text() + "/" + key->text()).toString();
    value->setText(str);
}
