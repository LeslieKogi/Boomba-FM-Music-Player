#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QListWidget>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mediaPlayer(nullptr)
    , audioOutput(nullptr)
    , currentIndex(-1)
    , isSliderBeingDragged(false)
{
    ui->setupUi(this);
    
    // Initialize media player
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);
    
    // Set window title and size
    setWindowTitle("Music Player");
    resize(900, 700);
    
    // Initialize connections
    initializeConnections();
}

MainWindow::~MainWindow()
{
    if (mediaPlayer) {
        mediaPlayer->stop();
    }
    delete ui;
}

void MainWindow::initializeConnections()
{
    // Player control buttons
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayClick);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseClick);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopClick);
    connect(ui->nextButton, &QPushButton::clicked, this, &MainWindow::onNextClick);
    connect(ui->previousButton, &QPushButton::clicked, this, &MainWindow::onPreviousClick);
    
    // Playlist controls
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddSongsClick);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveSongClick);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearPlaylistClick);
    connect(ui->playlistWidget, QOverload<QListWidgetItem*>::of(&QListWidget::itemDoubleClicked),
            this, [this](QListWidgetItem *item) {
        currentIndex = ui->playlistWidget->row(item);
        mediaPlayer->setSource(QUrl::fromLocalFile(playlist[currentIndex]));
        mediaPlayer->play();
        updateSongDisplay();
    });
    
    // Media player signals
    connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::onMediaStatusChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);
    
    // Volume and seek controls
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::onVolumeChanged);
    connect(ui->seekSlider, &QSlider::sliderMoved, this, &MainWindow::onSeekSliderMoved);
    connect(ui->seekSlider, &QAbstractSlider::sliderPressed, this, [this]() { isSliderBeingDragged = true; });
    connect(ui->seekSlider, &QAbstractSlider::sliderReleased, this, [this]() { isSliderBeingDragged = false; });
    
    // Set initial volume
    ui->volumeSlider->setValue(100);
}

void MainWindow::onPlayClick()
{
    if (currentIndex < 0 && !playlist.isEmpty()) {
        currentIndex = 0;
        mediaPlayer->setSource(QUrl::fromLocalFile(playlist[currentIndex]));
    }
    
    if (mediaPlayer->source().isValid()) {
        mediaPlayer->play();
        updateSongDisplay();
    }
}

void MainWindow::onPauseClick()
{
    mediaPlayer->pause();
}

void MainWindow::onStopClick()
{
    mediaPlayer->stop();
    mediaPlayer->setPosition(0);
    ui->seekSlider->setValue(0);
    ui->statusLabel->setText("Stopped");
}

void MainWindow::onNextClick()
{
    if (!playlist.isEmpty()) {
        currentIndex = (currentIndex + 1) % playlist.count();
        mediaPlayer->setSource(QUrl::fromLocalFile(playlist[currentIndex]));
        mediaPlayer->play();
        updateSongDisplay();
    }
}

void MainWindow::onPreviousClick()
{
    if (!playlist.isEmpty()) {
        currentIndex = (currentIndex - 1 + playlist.count()) % playlist.count();
        mediaPlayer->setSource(QUrl::fromLocalFile(playlist[currentIndex]));
        mediaPlayer->play();
        updateSongDisplay();
    }
}

void MainWindow::onAddSongsClick()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
        "Add Music Files", QStandardPaths::writableLocation(QStandardPaths::MusicLocation),
        "Audio Files (*.mp3 *.wav *.flac *.ogg *.m4a);;All Files (*)");
    
    for (const QString &file : files) {
        if (!playlist.contains(file)) {
            playlist.append(file);
            ui->playlistWidget->addItem(file.split('/').last());
        }
    }
    
    ui->playlistCountLabel->setText(QString("Songs: %1").arg(playlist.count()));
}

void MainWindow::onRemoveSongClick()
{
    QModelIndexList selected = ui->playlistWidget->selectionModel()->selectedIndexes();
    for (int i = selected.count() - 1; i >= 0; --i) {
        int row = selected.at(i).row();
        playlist.removeAt(row);
        ui->playlistWidget->takeItem(row);
    }
    ui->playlistCountLabel->setText(QString("Songs: %1").arg(playlist.count()));
    
    if (currentIndex >= playlist.count()) {
        currentIndex = -1;
    }
}

void MainWindow::onClearPlaylistClick()
{
    playlist.clear();
    ui->playlistWidget->clear();
    mediaPlayer->stop();
    mediaPlayer->setPosition(0);
    ui->seekSlider->setValue(0);
    currentIndex = -1;
    ui->playlistCountLabel->setText("Songs: 0");
    ui->statusLabel->setText("Playlist cleared");
}

void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        onNextClick();
    }
}

void MainWindow::onDurationChanged(qint64 duration)
{
    ui->seekSlider->setMaximum(duration / 1000); // Convert to seconds
    int seconds = duration / 1000;
    int minutes = seconds / 60;
    seconds = seconds % 60;
    ui->durationLabel->setText(QString("%1:%2").arg(minutes).arg(seconds, 2, 10, QChar('0')));
}

void MainWindow::onPositionChanged(qint64 position)
{
    if (!isSliderBeingDragged) {
        ui->seekSlider->setValue(position / 1000); // Convert to seconds
    }
    
    int seconds = position / 1000;
    int minutes = seconds / 60;
    seconds = seconds % 60;
    ui->timeLabel->setText(QString("%1:%2").arg(minutes).arg(seconds, 2, 10, QChar('0')));
    
    // Update status
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        ui->statusLabel->setText("Playing");
    } else if (mediaPlayer->playbackState() == QMediaPlayer::PausedState) {
        ui->statusLabel->setText("Paused");
    }
}

void MainWindow::onVolumeChanged(int volume)
{
    audioOutput->setVolume(volume / 100.0);
    ui->volumeLabel->setText(QString("%1%").arg(volume));
}

void MainWindow::onSeekSliderMoved(int position)
{
    mediaPlayer->setPosition(position * 1000); // Convert to milliseconds
}

void MainWindow::updateSongDisplay()
{
    if (currentIndex >= 0 && currentIndex < playlist.count()) {
        QString filePath = playlist[currentIndex];
        QString fileName = filePath.split('/').last();
        ui->currentSongLabel->setText("Now Playing: " + fileName);
        ui->playlistWidget->setCurrentRow(currentIndex);
    }
}
