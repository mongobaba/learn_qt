#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QRadioButton>

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
    void radioChange();

private:
    Ui::MainWindow *ui;
    QRadioButton* radioM;
    QRadioButton* radioW;
    QLabel* label;
};
#endif // MAINWINDOW_H
