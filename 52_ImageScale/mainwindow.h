#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

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
    void showLarger();
    void showSmaller();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QImage* image;
    QPushButton* larger;
    QPushButton* smaller;
};
#endif // MAINWINDOW_H
