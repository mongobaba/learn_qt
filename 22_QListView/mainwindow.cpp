#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listView = new QListView(this);
    listView->setGeometry(QRect(50, 50, 150, 100));

    QStringList list;
    list << tr("数学") << tr("语文") << tr("外语") << tr("地理");

    // view是与model搭配使用的，注意比较QComboBox与QListView添加内容的差异
    model = new QStringListModel(list, listView);
    // setModel并不会自动为model设置parent，所以创建时最好手动指定，以免内存泄漏
    listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

