#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCalendarWidget>
#include <QLabel>
#include <QLineEdit>
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
    void showTime();
    void setDate();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QLineEdit* lineEdit;
    QCalendarWidget* calendar;
};
#endif // MAINWINDOW_H
