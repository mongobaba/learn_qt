#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , trayIcon(nullptr)
{
    ui->setupUi(this);
    createMenu();
    if (QSystemTrayIcon::isSystemTrayAvailable())
    {
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon(":/new/prefix1/pygame.ico"));
        trayIcon->setToolTip(tr("Qt托盘图标功能"));
        // windows xp那种气泡效果，但是在win10系统上，这一行好像没什么用
        trayIcon->showMessage(tr("托盘"), tr("托盘管理"), QSystemTrayIcon::Information, 10000);
        trayIcon->setContextMenu(menu);
        trayIcon->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenu()
{
    restoreAct = new QAction(tr("恢复(&R)"), this);
    connect(restoreAct, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAct = new QAction(tr("退出(&Q)"), this);
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    // 如果不包含QDesktopWidget头文件，这里需要增加一个到QWidget*
    // 的强制类型转换，因为编译器不知道这两个类之间的继承关系
    menu = new QMenu(QApplication::desktop());
    menu->addAction(restoreAct);
    menu->addSeparator();
    menu->addAction(quitAct);
}

void MainWindow::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::WindowStateChange && isMinimized())
    {
        hide();
    }
}
