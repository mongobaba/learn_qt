#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListView>
#include <QProcess>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList list = QProcess::systemEnvironment();
    QStringListModel* model = new QStringListModel(list, this);
    QListView* view = new QListView(this);
    view->setModel(model);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

