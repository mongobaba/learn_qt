#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QDir::currentPath());

    QString file = QDir::currentPath() + "/test.db";
    // 每次重新创建新的数据库文件
    QFile::remove(file);
    if (connectDB())
    {
        createDB();
        bindData();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::connectDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    return db.open();
}

void MainWindow::createDB()
{
    QSqlQuery query;
    query.exec("CREATE TABLE person ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name VARCHAR(50) NOT NULL, "
               "time TIMESTAMP default CURRENT_TIMESTAMP)");
    query.exec("INSERT INTO person (name) VALUES ('张三')");
    query.exec("INSERT INTO person (name) VALUES ('李四')");
    query.exec("INSERT INTO person (name) VALUES ('王五')");
}

void MainWindow::bindData()
{
    QTableView* view = new QTableView(this);
    view->setGeometry(QRect(50, 80, 500, 200));
    QSqlTableModel* model = new QSqlTableModel(view, db);
    model->setTable("person");
    model->select();
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
