#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
<<<<<<< HEAD
#include <QFileInfo>
#include <QStringList>
=======
#include <QStringList>
#include <QMap>
>>>>>>> main

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentIndex(-1)
{
    ui->setupUi(this);
<<<<<<< HEAD
    connect(ui->songListWidget, &QListWidget::currentRowChanged, this, &MainWindow::onSongSelected); // Connect the currentRowChanged signal to the onSongSelected slot.

    ui->songListWidget->clear();
musicLibrary.clear();

QDir songsDir("songs");
if (!songsDir.exists()) {
    songsDir = QDir("../songs");
}

QStringList mp3Files = songsDir.entryList(QStringList() << "*.mp3", QDir::Files);

// THE ONLY LOOP YOU NEED
for (const QString &fileName : mp3Files) {
    Song track;
    track.filePath = "songs/" + fileName;

    QString cleanName = fileName;
    cleanName.chop(4); // Remove ".mp3"

    QList<QString> nameParts = cleanName.split("- ");

    // Split Artist and Title safely
    if (nameParts.size() >= 2) {
        track.artist = nameParts[0].trimmed();
        track.title = nameParts[1].trimmed();
    } else {
        track.artist = "Unknown Artist";
        track.title = cleanName.trimmed();
    }

    track.genre = "My Music";

    // Handle Album Art Paths cleanly
    QString customImagePath = "images/" + track.title + ".jpg";
    if (QFileInfo::exists(customImagePath)) {
        track.imagePath = customImagePath;
    } else {
        track.imagePath = "images/default.png"; // Fallback image
    }

    // Job 1: Save it to your backend library vector
    musicLibrary.append(track);

    // Job 2: Display it on the UI immediately
    ui->songListWidget->addItem(track.artist + " - " + track.title);
}
=======

    //hardcoded genre mapping 
    QMap<QString, QString> genreLookup;
    genreLookup["21 Savage - Bank Account.mp3"] = "Hip Hop";
    genreLookup["21 Savage, Doja Cat - n.h.i.e..mp3"] = "Hip Hop";
    genreLookup["Am I Dreaming - Metro Boomin ft ASAP Rocky.mp3"] = "Hip Hop";
    genreLookup["Babyboy AV - Quick Question.mp3"] = "Afrobeats";
    genreLookup["Central Cee x Dave - Our 25th Birthday.mp3"] = "UK Rap";
    genreLookup["Chris Kaiga - I Want ft. Mutoriah.mp3"] = "Afrobeats";
    genreLookup["Davido - Aye.mp3"] = "Afrobeats";
    genreLookup["Drake - Finesse.mp3"] = "Hip Hop";
    genreLookup["Eminem - Business.mp3"] = "Hip Hop";
    genreLookup["Eminem - Mockingbird.mp3"] = "Hip Hop";
    genreLookup["Faith Kimani - Ode to the Lovers.mp3"] = "R&B";
    genreLookup["JayO - 22.mp3"] = "Afrobeats";
    genreLookup["Jorja Smith - Be Honest ft. Burna Boy.mp3"] = "R&B";
    genreLookup["Jorja Smith - Bussdown Audio ft. Shaybo.mp3"] = "R&B";
    genreLookup["Jorja Smith - Come Over (feat. Popcaan).mp3"] = "R&B";
    genreLookup["Joshua Baraka - NANA.mp3"] = "Afrobeats";
    genreLookup["Juice WRLD - All Girls Are The Same.mp3"] = "Hip Hop";
    genreLookup["Juice WRLD - Robbery.mp3"] = "Hip Hop";
    genreLookup["Justin Timberlake - Mirrors.mp3"] = "Pop";
    genreLookup["Kehlani & G Eazy - Good Life.mp3"] = "R&B";
    genreLookup["Lil Peep - Star Shopping.mp3"] = "Emo Rap";
    genreLookup["Lil Uzi Vert, Oh Wonder - The Way Life Goes.mp3"] = "Hip Hop";
    genreLookup["Lil Wayne feat. Bruno Mars - Mirror.mp3"] = "Hip Hop";
    genreLookup["Little Mix - Touch.mp3"] = "Pop";
    genreLookup["Mac Miller - Weekend (feat. Miguel).mp3"] = "Hip Hop";
    genreLookup["Nasty C - SMA ft. Rowlene.mp3"] = "Hip Hop";
    genreLookup["Nelly Furtado - Say It Right.mp3"] = "Pop";
    genreLookup["Njerae - OTD.mp3"] = "Afrobeats";
    genreLookup["One Step At A Time - Jordin Sparks.mp3"] = "Pop";
    genreLookup["Post Malone, Swae Lee - Sunflower.mp3"] = "Pop";
    genreLookup["Sauti Sol - Midnight train.mp3"] = "Afropop";
    genreLookup["Sean Paul, Dua Lipa - No Lie.mp3"] = "Pop";
    genreLookup["Shiloh Dynasty - Novacaine.mp3"] = "Lo-fi";
    genreLookup["Steve Lacy - Some.mp3"] = "R&B";
    genreLookup["T-Pain - Up Down.mp3"] = "Hip Hop";
    genreLookup["Tayc - Encorps.mp3"] = "Afrobeats";
    genreLookup["The Chainsmokers - Closer ft. Halsey.mp3"] = "Pop";
    genreLookup["Travis Scott - I Know.mp3"] = "Hip Hop";
    genreLookup["Twenty one pilots - Chlorine.mp3"] = "Alternative Rock";
    genreLookup["Twenty one pilots - Heathens.mp3"] = "Alternative Rock";

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

        
        QString genre = genreLookup.value(fileName, "Unknown"); 
        Song newSong(title, artist, genre, 0);
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
>>>>>>> main
}

MainWindow::~MainWindow()
{
    if (mediaPlayer) mediaPlayer->stop();
    delete ui;
}

<<<<<<< HEAD
void MainWindow::onSongSelected(int currentRow) {
    if (currentRow <0 || currentRow >=musicLibrary.size())
    return; // If the selected row is out of bounds, do nothing.

    Song selectedTrack = musicLibrary [currentRow]; // Get the selected song from the music library based on the current row.
    
    QPixmap pix(selectedTrack.imagePath); // Load the album art image for the selected song.
    if (!pix.isNull()) {
        ui-> coverLabel->setPixmap(pix.scaled(ui->coverLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // If the image is valid, display it in the cover label. 
    }
=======
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
>>>>>>> main
}