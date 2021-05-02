#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QProcess>
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
    void executeCommand();
    void readOutput();

private:
    Ui::MainWindow *ui;
    QLineEdit* command;
    QPlainTextEdit* output;
    QPushButton* execute;
    QProcess* process;
    QString result;
    QLabel* label;
};
#endif // MAINWINDOW_H
