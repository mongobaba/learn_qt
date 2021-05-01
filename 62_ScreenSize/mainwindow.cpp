#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 250, 25));

    QList<QScreen*> screens = QGuiApplication::screens();
    QRect rect = screens.at(0)->geometry();
    QString str = tr("主屏幕分辨率为：%1*%2");
    label->setText(str.arg(rect.width()).arg(rect.height()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

