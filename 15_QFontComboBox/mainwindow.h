#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFontComboBox>
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
    void txtButton();

private:
    Ui::MainWindow *ui;
    QFontComboBox* comboBox;
    QPushButton* button;
    QLabel* label;
};
#endif // MAINWINDOW_H
