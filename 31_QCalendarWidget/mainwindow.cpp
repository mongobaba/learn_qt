#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(tr("选择日期："), this);
    label->setGeometry(QRect(50, 50, 100, 25));

    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(150, 50, 150, 25));
    connect(lineEdit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(showTime()));

    calendar = new QCalendarWidget(this);
    calendar->setGeometry(QRect(20, 80, 350, 180));
    // 默认隐藏
    calendar->setHidden(true);
    connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(setDate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{
    calendar->setHidden(false);
}

void MainWindow::setDate()
{
    QDate date = calendar->selectedDate();
    lineEdit->setText(date.toString("yyyy-MM-dd"));
    // 选择之后再次隐藏
    calendar->setHidden(true);
}
