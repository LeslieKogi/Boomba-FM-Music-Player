#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentIndex(-1)
{
    ui->setupUi(this);

   // songs
    QDir songsDir("songs");
    QStringList mp3Files = songsDir.entryList(QStringList() << "*.mp3", QDir::Files);

    for (const QString &fileName : mp3Files)
    {
        
        QString nameWithoutExtension = fileName;
        nameWithoutExtension.chop(4); 

        QString artist = "Unknown Artist";
        QString title = nameWithoutExtension;

        
        int separatorIndex = nameWithoutExtension.indexOf(" - ");
        if (separatorIndex != -1)
        {
            artist = nameWithoutExtension.left(separatorIndex);
            title = nameWithoutExtension.mid(separatorIndex + 3); 
        }

        
        Song newSong(title, artist, "Unknown", 0);
        newSong.setFilePath("songs/" + fileName);
        m_library.addSong(newSong);
    }

    m_currentDisplayedSongs = m_library.getAllSongs();
    refreshSongList(m_currentDisplayedSongs);
    populateFilterBoxes();

    // playback 
    audioOutput = new QAudioOutput(this);
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);

    initializeConnections();
}

MainWindow::~MainWindow()
{
    if (mediaPlayer) mediaPlayer->stop();
    delete ui;
}

void MainWindow::initializeConnections()
{
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayClicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseClicked);
    connect(ui->songListWidget, &QListWidget::itemClicked, this, &MainWindow::onSongClicked);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->genreComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onGenreFilterChanged);
    connect(ui->artistComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onArtistFilterChanged);

    connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::onMediaStatusChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);

    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, [this](int position) {
        mediaPlayer->setPosition(position * 1000);
    });
}

void MainWindow::refreshSongList(const QVector<Song> &songs)
{
    m_currentDisplayedSongs = songs;
    ui->songListWidget->clear();
    for (const Song &s : songs) {
        ui->songListWidget->addItem(s.getTitle() + " — " + s.getArtist());
    }
}

void MainWindow::populateFilterBoxes()
{
    ui->genreComboBox->clear();
    ui->artistComboBox->clear();
    ui->genreComboBox->addItem("All Genres");
    ui->artistComboBox->addItem("All Artists");

    QSet<QString> genres, artists;
    for (const Song &s : m_library.getAllSongs()) {
        genres.insert(s.getGenre());
        artists.insert(s.getArtist());
    }
    for (const QString &g : genres) ui->genreComboBox->addItem(g);
    for (const QString &a : artists) ui->artistComboBox->addItem(a);
}

void MainWindow::onSongClicked()
{
    currentIndex = ui->songListWidget->currentRow();
    if (currentIndex < 0 || currentIndex >= m_currentDisplayedSongs.size()) return;

    QString filePath = m_currentDisplayedSongs[currentIndex].getFilePath();
    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
}

void MainWindow::onPlayClicked()
{
    if (mediaPlayer->source().isValid()) {
        mediaPlayer->play();
    }
}

void MainWindow::onPauseClicked()
{
    mediaPlayer->pause();
}

void MainWindow::onSearchTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        refreshSongList(m_library.getAllSongs());
        return;
    }
    refreshSongList(m_library.searchByTitle(text));
}

void MainWindow::onGenreFilterChanged(const QString &genre)
{
    if (genre == "All Genres") { refreshSongList(m_library.getAllSongs()); return; }
    refreshSongList(m_library.searchByGenre(genre));
}

void MainWindow::onArtistFilterChanged(const QString &artist)
{
    if (artist == "All Artists") { refreshSongList(m_library.getAllSongs()); return; }
    refreshSongList(m_library.searchByArtist(artist));
}

void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    Q_UNUSED(status);
}

void MainWindow::onDurationChanged(qint64 duration)
{
    ui->horizontalSlider->setMaximum(duration / 1000);
}

void MainWindow::onPositionChanged(qint64 position)
{
    ui->horizontalSlider->setValue(position / 1000);
}