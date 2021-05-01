#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button = new QPushButton(tr("选择颜色"), this);
    button->setGeometry(QRect(200, 50, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(editText()));

    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 150, 25));
    label->setText(tr("我的颜色可以改变"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editText()
{
    QColorDialog::setCustomColor(0, QRgb(0x0000ff));
    QColor color = QColorDialog::getColor(QColor(0, 255, 0));
    QPalette palette = label->palette();
    palette.setColor(QPalette::WindowText, color);
    label->setPalette(palette);
}
