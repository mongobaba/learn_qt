#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

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
    void saveFile();

private:
    Ui::MainWindow *ui;
    QPushButton* browseButton;
    QPushButton* saveButton;
    QTextEdit* edit;
    QTextEdit* content;
};
#endif // MAINWINDOW_H
