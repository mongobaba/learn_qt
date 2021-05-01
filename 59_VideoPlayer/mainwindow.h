#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QToolButton>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QLabel>

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
    void onStateChanged(QMediaPlayer::State state);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onSliderValueChanged(int value);
    void openFile();

private:
    Ui::MainWindow *ui;
    QVideoWidget* widget;
    QMediaPlayer* player;
    QToolButton* openButton;
    QToolButton* pauseButton;
    QToolButton* stopButton;
    QSlider* slider;
    QLabel* timeLabel;
    QLabel* totalTimeLabel;
};
#endif // MAINWINDOW_H
