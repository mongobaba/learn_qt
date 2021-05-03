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
    void changeImage();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QTimer* timer;
    QPixmap pixmap[2];
    int index;
};
#endif // MAINWINDOW_H
