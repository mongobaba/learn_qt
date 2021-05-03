#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 300, 300));
    label->setPixmap(QPixmap(":/new/prefix1/butterfly.png"));

    button = new QPushButton(tr("移动"), this);
    button->setGeometry(QRect(50, 400, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(moveImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveImage()
{
    static int i = 50;
    i += 50;
    label->move(i, 50);
}
