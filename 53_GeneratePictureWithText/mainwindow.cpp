#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setText(tr("等待生成"));
    label->setGeometry(QRect(50, 50, 300, 25));

    button = new QPushButton(tr("生成图片"), this);
    button->setGeometry(QRect(50, 100, 80, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(generatePicture()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generatePicture()
{
    QImage image(":/new/prefix1/butterfly.png");
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    QPen pen = painter.pen();
    pen.setColor(Qt::red);
    painter.setPen(pen);

    QFont font = painter.font();
    font.setBold(true);
    font.setPixelSize(50);
    painter.setFont(font);

    painter.drawText(image.rect(), Qt::AlignCenter, tr("你好，蝴蝶"));
    if (image.save(tr("D:/testdir/蝴蝶.png"), "PNG", 100))
    {
        label->setText(tr("图片生成成功"));
    }
    else
    {
        label->setText(tr("图片生成失败"));
    }
}

