#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    radioM = new QRadioButton(tr("男"), this);
    radioM->setGeometry(QRect(50, 50, 50, 50));

    radioW = new QRadioButton(tr("女"), this);
    radioW->setGeometry(QRect(100, 50, 50, 50));

    label = new QLabel(this);
    label->setGeometry(QRect(50, 100, 100, 25));

    // 默认状态
    radioM->setChecked(true);
    label->setText(tr("男"));

    connect(radioM, SIGNAL(clicked()), this, SLOT(radioChange()));
    connect(radioW, SIGNAL(clicked()), this, SLOT(radioChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::radioChange()
{
    QRadioButton* button = (QRadioButton*)sender();
    label->setText(button->text());
}

