#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createMenu();
    void changeEvent(QEvent* e) override;

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon* trayIcon;
    QMenu* menu;
    QAction* restoreAct;
    QAction* quitAct;
};
#endif // MAINWINDOW_H
