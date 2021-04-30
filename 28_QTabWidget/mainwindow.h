#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// TabA和TabB必须在头文件中定义

class TabA : public QWidget
{
    Q_OBJECT
public:
    TabA(QWidget* parent = nullptr);
};

class TabB : public QWidget
{
    Q_OBJECT
public:
    TabB(QWidget* parent = nullptr);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTabWidget* tabWidget;
};
#endif // MAINWINDOW_H
