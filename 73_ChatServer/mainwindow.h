#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"

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
    void updateServer(QString message, qint64 length);

    void on_startButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
    TcpServer* server;
};
#endif // MAINWINDOW_H
