#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QTimer>

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
    void updateTime();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QTimer* timer;
};
#endif // MAINWINDOW_H
