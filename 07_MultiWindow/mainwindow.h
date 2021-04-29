#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow2.h"

#include <QMainWindow>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showMainWindow2();

private:
    Ui::MainWindow *ui;
    QPushButton* pushButton;
    MainWindow2 w2;
};
#endif // MAINWINDOW_H
