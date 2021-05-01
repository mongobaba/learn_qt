#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , index(0)
{
    ui->setupUi(this);

    QPixmap pixmap(":/new/prefix1/0.png");
    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 250, 80));
    label->setPixmap(pixmap);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeImage()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeImage()
{
    QPixmap pixmap(QString::asprintf(":/new/prefix1/%d.png", index & 1));
    label->setPixmap(pixmap);
    ++index;
}
