#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comboBox = new QFontComboBox(this);
    comboBox->setGeometry(QRect(50, 51, 120, 28));

    button = new QPushButton(this);
    button->setText(tr("显示名称"));
    button->move(180, 50);
    connect(button, SIGNAL(clicked()), this, SLOT(txtButton()));

    label = new QLabel(this);
    label->setGeometry(QRect(50, 150, 300, 25));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::txtButton()
{
    label->setText(tr("选择字体：") + comboBox->currentText());
}
