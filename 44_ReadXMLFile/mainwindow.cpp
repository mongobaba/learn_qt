#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QXmlStreamWriter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setGeometry(QRect(50, 50, 300, 100));

    button = new QPushButton(tr("读取title节点"), this);
    button->setGeometry(QRect(50, 180, 150, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(readNode()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readNode()
{
    QFile file(tr("D:/testdir/config.xml"));

    if (!file.exists())
    {
        label->setText(tr("文件不存在"));
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        label->setText(tr("文件打开失败"));
        return;
    }

    QXmlStreamReader reader(&file);
    while (!reader.atEnd())
    {
        reader.readNext();
        // 与上一个示例的结构保持一致
        if (reader.isStartElement() && reader.name() == "title")
        {
            label->setText(reader.readElementText());
            return;
        }
    }

    label->setText(tr("没有找到节点"));
}
