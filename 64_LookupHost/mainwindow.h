#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QHostInfo>

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
    void sendUrl();
    void lookup(const QHostInfo& info);

private:
    Ui::MainWindow *ui;
    QLabel* urlLabel;
    QLineEdit* urlLineEdit;
    QLabel* ipLabel;
    QPushButton* button;
};
#endif // MAINWINDOW_H
