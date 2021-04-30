#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    menu = new QMenu((QWidget*)QApplication::desktop());
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
