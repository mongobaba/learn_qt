#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widget = new QVideoWidget();
    widget->setStyleSheet("background-color:black");
    // 使用前请确保安装了DirectShow解码器，例如https://github.com/Nevcairiel/LAVFilters/releases
    player = new QMediaPlayer(this);
    player->setVideoOutput(widget);
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(onStateChanged(QMediaPlayer::State)));
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));

    openButton = new QToolButton();
    openButton->setText(tr("浏览"));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

    pauseButton = new QToolButton();
    pauseButton->setText(tr("暂停"));
    pauseButton->setEnabled(false);

    stopButton = new QToolButton();
    stopButton->setText(tr("停止"));
    stopButton->setEnabled(false);
    connect(stopButton, SIGNAL(clicked()), player, SLOT(stop()));

    slider = new QSlider(Qt::Horizontal);
    slider->setEnabled(false);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));

    timeLabel = new QLabel();
    // 频繁变化，所以单独显示
    timeLabel->setText("00:00");
    totalTimeLabel = new QLabel();
    totalTimeLabel->setText(" / 00:00");

    // 三个按钮横向布局
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(stopButton);

    // 进度条和时间横向布局
    QHBoxLayout* sliderLayout = new QHBoxLayout();
    sliderLayout->addWidget(slider);
    sliderLayout->addWidget(timeLabel);
    sliderLayout->addWidget(totalTimeLabel);

    // 整体纵向布局
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(widget);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(sliderLayout);
    // 调整各部分比例
    mainLayout->setStretchFactor(widget, 5);
    mainLayout->setStretchFactor(buttonLayout, 1);
    mainLayout->setStretchFactor(sliderLayout, 1);

    // 显示布局控件
    QWidget* center = new QWidget();
    center->setLayout(mainLayout);
    this->setCentralWidget(center);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStateChanged(QMediaPlayer::State state)
{
    switch (state)
    {
    case QMediaPlayer::State::PlayingState:
        pauseButton->setText(tr("暂停"));
        pauseButton->disconnect(player);
        connect(pauseButton, SIGNAL(clicked()), player, SLOT(pause()));
        // 开始播放之后这三个控件才可用
        pauseButton->setEnabled(true);
        stopButton->setEnabled(true);
        slider->setEnabled(true);
        break;
    case QMediaPlayer::State::PausedState:
        // PausedState只会从PlayingState属性变化而来，而进入暂停时，
        // pauseButton、stopButton和slider三个控件的状态不会发生变
        // 化，因此不需要setEnabled
        pauseButton->setText(tr("继续"));
        pauseButton->disconnect(player);
        connect(pauseButton, SIGNAL(clicked()), player, SLOT(play()));
        break;
    case QMediaPlayer::State::StoppedState:
        pauseButton->setText(tr("暂停"));
        // 一旦停止，这三个控件都无法使用
        pauseButton->setEnabled(false);
        stopButton->setEnabled(false);
        slider->setEnabled(false);
        // 停止视频后清零总时长
        totalTimeLabel->setText(" / 00:00");
        break;
    }
}

void MainWindow::onDurationChanged(qint64 duration)
{
    // 单位转换为秒
    int total = static_cast<int>(duration / 1000);
    int minute = total / 60;
    int second = total % 60;
    QString time = QString::asprintf(" / %02d:%02d", minute, second);
    totalTimeLabel->setText(time);
    // 以秒为单位进行设置，下面要与此保持一致
    slider->setMaximum(total);
}

void MainWindow::onPositionChanged(qint64 position)
{
    // 如果slider被按下，则说明正在拖动进度，那么不更新slider，避免循环设置
    if (!slider->isSliderDown())
    {
        // 单位转换为秒
        int pos = static_cast<int>(position / 1000);
        int minute = pos / 60;
        int second = pos % 60;
        QString time = QString::asprintf("%02d:%02d", minute, second);
        timeLabel->setText(time);
        QSignalBlocker blocker(slider);
        slider->setValue(pos);
    }
}

void MainWindow::onSliderValueChanged(int value)
{
    player->setPosition(static_cast<qint64>(value) * 1000);
}

void MainWindow::openFile()
{
    const QString filter = tr("视频文件(*.mpg *.mpeg *.avi *.wmv *.mp4);;所有文件(*.*)");
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"), "/", filter);
    if (!fileName.isEmpty())
    {
        player->setMedia(QUrl::fromLocalFile(fileName));
        player->play();
    }
}

