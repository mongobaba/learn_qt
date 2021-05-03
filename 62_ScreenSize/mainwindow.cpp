#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QScreen>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 250, 25));

    // 下面这种方式已经被废弃了
    // QApplication::desktop()->screenGeometry();

    QList<QScreen*> screens = QGuiApplication::screens();
    QRect rect = screens.at(0)->geometry();
    QString format = tr("主屏幕分辨率为：%1*%2");
    label->setText(format.arg(rect.width()).arg(rect.height()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

