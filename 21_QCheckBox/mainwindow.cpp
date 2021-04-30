#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    checkBox01 = new QCheckBox(tr("数学"), this);
    checkBox02 = new QCheckBox(tr("语文"), this);
    checkBox03 = new QCheckBox(tr("地理"), this);
    label = new QLabel(this);

    checkBox01->setGeometry(QRect(50, 50, 100, 50));
    checkBox02->setGeometry(QRect(150, 50, 100, 50));
    checkBox03->setGeometry(QRect(250, 50, 100, 50));
    label->setGeometry(QRect(50, 100, 200, 50));

    connect(checkBox01, SIGNAL(clicked(bool)), this, SLOT(checkChanged(bool)));
    connect(checkBox02, SIGNAL(clicked(bool)), this, SLOT(checkChanged(bool)));
    connect(checkBox03, SIGNAL(clicked(bool)), this, SLOT(checkChanged(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkChanged(bool checked)
{
    QString str(label->text());
    QCheckBox* checkBox = (QCheckBox*)sender();
    if (checked)
    {
        str += checkBox->text();
    }
    else
    {
        str.replace(checkBox->text(), "");
    }
    label->setText(str);
}
