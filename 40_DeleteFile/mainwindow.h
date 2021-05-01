#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void browseFile();
    void deleteFile();

private:
    Ui::MainWindow *ui;
    QLineEdit* filePath;
    QPushButton* browseButton;
    QPushButton* deleteButton;
};
#endif // MAINWINDOW_H
