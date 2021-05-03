#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileMenu = new QMenu(this);
    editMenu = new QMenu(this);
    helpMenu = new QMenu(this);

    // addAction不会更改ownership，所以这里设置parent是必要的
    newAct = new QAction(QIcon(":/new/prefix1/new.png"), tr("新建"), this);
    newAct->setShortcut(QString("Ctrl+N"));
    newAct->setStatusTip(tr("新建文件"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    cutAct = new QAction(QIcon(":/new/prefix1/cut.png"), tr("剪切"), this);
    cutAct->setShortcut(QString("Ctrl+X"));
    cutAct->setStatusTip(tr("剪切内容"));

    copyAct = new QAction(QIcon(":/new/prefix1/copy.png"), tr("复制"), this);
    copyAct->setShortcut(QString("Ctrl+C"));
    copyAct->setStatusTip(tr("复制内容"));

    pasteAct = new QAction(QIcon(":/new/prefix1/paste.png"), tr("粘贴"), this);
    pasteAct->setShortcut(QString("Ctrl+V"));
    pasteAct->setStatusTip(tr("粘贴内容"));

    aboutQtAct = new QAction(tr("关于Qt"), this);
    aboutQtAct->setStatusTip(tr("关于Qt信息"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    fileMenu = menuBar()->addMenu(tr("文件"));
    // 不会更改ownership
    fileMenu->addAction(newAct);

    editMenu = menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    helpMenu = menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(aboutQtAct);

    fileToolBar = addToolBar(tr("新建"));
    fileToolBar->addAction(newAct);

    editToolBar = addToolBar(tr("修改"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    QMessageBox::warning(this,
                         tr("warning"),
                         tr("创建新文件？"),
                         QMessageBox::Yes | QMessageBox::Default,
                         QMessageBox::No);
}
