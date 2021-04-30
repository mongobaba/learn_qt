#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QLabel>
#include <QMainWindow>

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
    void checkChanged(bool checked);

private:
    Ui::MainWindow *ui;
    QCheckBox* checkBox01;
    QCheckBox* checkBox02;
    QCheckBox* checkBox03;
    QLabel* label;
};
#endif // MAINWINDOW_H
