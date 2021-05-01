#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
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
    void writeFile();

private:
    Ui::MainWindow *ui;
    QGridLayout* layout;
    QWidget* widget;
    QLabel* fileLabel;
    QLineEdit* filePath;
    QLabel* nodeLabel;
    QLineEdit* nodeName;
    QLabel* keyLabel;
    QLineEdit* key;
    QLabel* valueLabel;
    QLineEdit* value;
    QPushButton* button;
};
#endif // MAINWINDOW_H
