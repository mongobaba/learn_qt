#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setText(tr("创建如下XML文件：\n"
                      "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                      "<Root href=\"http://qt.nokia.com/\">\n"
                      "    <title>Qt Home</title>\n"
                      "</Root>"));
    label->setGeometry(QRect(50, 50, 350, 100));

    button = new QPushButton(tr("创建XML文件"), this);
    button->setGeometry(QRect(50, 180, 100, 25));
    connect(button, SIGNAL(clicked()), this, SLOT(createFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFile()
{
    QFile file(tr("D:/testdir/config.xml"));
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QXmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);
        writer.writeStartDocument();
        writer.writeStartElement("Root");
        writer.writeAttribute("href", tr("http://qt.nokia.com/"));
        writer.writeTextElement("title", tr("Qt Home"));
        writer.writeEndElement();
        writer.writeEndDocument();
        QMessageBox::warning(this, tr("创建XML文件"), tr("创建XML文件成功！"));
    }
}
