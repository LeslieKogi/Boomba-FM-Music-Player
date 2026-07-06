#include <QDebug>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QStringList>
#include <QMap>
#include <QFileDialog>
#include <QFileInfo>
#include <QCoreApplication>
#include <QMessageBox>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentIndex(-1)
        
{
    ui->setupUi(this);
    this->setStyleSheet(R"(
        QMainWindow{
            background-color: #0d0b14;
            }
        QLabel{
            color: #e1dfeb;
            } 
        QLineEdit{
            background-color: #161224;
            color: #ffffff;
            border: 1px solid #8a2be2;
            border-radius: 6px;
            padding: 4px;
            }
        QComboBox{
            background-color: #161224;
            color: #ffffff;
            border: 1px solid #8a2be2;
            border-radius: 4px;
            padding: 2px;
            } 
        QListWidget, QListView{
            background-color: #161224;
            color: #e1dfeb
            bordedr: 1px solid #443c5c;
            border-radius:8px;
            outline: none;
            }
        QListWidget::item:hover{
            background-color: #251f3b;
            }
        QListWidget::item:selcted{
            background-color: #8a2be2;
            color: #ffffff;
            }
        QSlider::groove:horizontal{
            height: 4px;
            background: #251f3b;
            border-radius: 2px;
            }
        QSlider::sub-page:horizontal{
            background: #8a2be2;
            border-radius: 2px;
            }  
        QSlider::handle:horizontal{
            background: #ffffff;
            width: 12px;
            margin: -4px 0;
            border-radius: 6px;
            }
        QPushButton#playButton {
            background-color: #b61db9;
            color: #8a2eb2;
            border: 2px solid #8a2be2;
            border-radius: 25px;
            image: url(images/play.png);
            }
        QPushButton:hover{
            background-color: #8a2be2;
            color: #ffffff;
            }
    )");
    QPixmap pix("images/default.png");
    if (!pix.isNull()) {
        pix.load("../images/default.png");
    }
    if (!pix.isNull()){
        ui->ImageLabel->setText("");
        ui->ImageLabel->setPixmap(pix.scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else{
        qDebug() << "Boomba FM Error: Cannot find default.png in images/ or.../images/";
    }
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
}

MainWindow::~MainWindow()
{
    if (mediaPlayer) mediaPlayer->stop();
    delete ui;
}

void MainWindow::initializeConnections()
{
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::onPlayClicked);
    connect(ui->prevButton, &QPushButton::clicked, this, &MainWindow::onPrevClicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &MainWindow::onNextClicked);
    connect(ui->songListWidget, &QListWidget::itemClicked, this, &MainWindow::onSongClicked);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->genreComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onGenreFilterChanged);
    connect(ui->artistComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onArtistFilterChanged);

    connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::onMediaStatusChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::updateDuration);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::updatePosition);

    connect(ui->horizontalSlider, &QSlider::sliderReleased, this, &MainWindow::setTrackPosition);
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::setVolume);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::onOpenClicked);
    connect(ui->songListWidget, &QListWidget::itemClicked, this, &MainWindow::onSongClicked);
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
    int currentIndex = ui->songListWidget->currentRow();
    if (currentIndex < 0 || currentIndex >= m_currentDisplayedSongs.size()) return;

    QString filePath = m_currentDisplayedSongs[currentIndex].getFilePath();
    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
    mediaPlayer->play();
    ui->playButton->setChecked(true);

    QString appDir = QCoreApplication::applicationDirPath();

    QFileInfo songInfo(filePath);
    QString songName = songInfo.completeBaseName();

    QString imagePathJpg = appDir + "/images/" + songName + ".jpg";
    QString imagePathPng = appDir + "/images/" + songName + ".png";
    QString defaultPath = appDir + "/images/default.png";

    QString finalImagePath = defaultPath;

    if (QFileInfo::exists(imagePathJpg)){
        finalImagePath = imagePathJpg;
    }
    else if(QFileInfo::exists(imagePathPng)){
        finalImagePath = imagePathPng;
    }
    
     qDebug() << "==================================================";
    qDebug() << "Looking for JPG at:" << imagePathJpg << " | Found:" << QFileInfo::exists(imagePathJpg);
    qDebug() << "Looking for PNG at:" << imagePathPng << " | Found:" << QFileInfo::exists(imagePathPng);
    qDebug() << "Displaying image from path:" << finalImagePath;
    qDebug() << "==================================================";

    QPixmap pixmap(finalImagePath);
    if(!pixmap.isNull()){
        ui->ImageLabel->setPixmap(pixmap.scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    
}

void MainWindow::onPlayClicked()
{
    if (mediaPlayer->source().isValid()) {
        if (ui->playButton->isChecked())  {
            mediaPlayer->play();
        }
        else{
            mediaPlayer->pause();
        }
    }
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
void MainWindow::updateDuration(qint64 duration){
    ui->horizontalSlider->setRange(0, duration);

    int seconds = (duration / 1000) % 60;
    int minutes = (duration / 1000) / 60;

    QString timeText = QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));

    ui->totalTimeLabel->setText(timeText);    
}
void MainWindow::updatePosition(qint64 position){
    if (!ui->horizontalSlider->isSliderDown()) {
        ui->horizontalSlider->setValue(position);
    }
    int seconds = (position / 1000) % 60;
    int minutes = (position / 60000) % 60;
    
    QString timeText = QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));

    ui->currentTimeLabel->setText(timeText);
}
void MainWindow::setTrackPosition(){
    mediaPlayer->setPosition(ui->horizontalSlider->value());
}
void MainWindow::setVolume(int volume) {
    audioOutput->setVolume(volume / 100.0);
}
void MainWindow::onOpenClicked(){
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Select a Song"),
        defaultPath,
        tr("Audio Files (*.mp3 *.wav *.m4a *.ogg *.flac)")
    );
    if (filePath.isEmpty()) {
        return;
    }
    for (const QString &filePath : filePath) {
        QFileInfo fileInfo(filePath);
        QString cleanSongTitle = fileInfo.completeBaseName();

        QListWidgetItem *item = new QListWidgetItem(cleanSongTitle, ui->songListWidget);
        item->setData(Qt::UserRole, filePath);
    }
    if (!filePath.isEmpty()) {
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        mediaPlayer->play();
        QString songTitle = QFileInfo(filePath).baseName();
        ui->label->setText("Playing: " + songTitle);
    }
}
void MainWindow::on_songListWidget_itemClicked(QListWidgetItem *item){
    Q_UNUSED(item);

    int currentRow = ui->songListWidget->currentRow();

    if (currentRow >= 0 && currentRow < m_currentDisplayedSongs.size()){
        Song selectedSong = m_currentDisplayedSongs[currentRow];
        QString filePath = selectedSong.getFilePath();
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        mediaPlayer->play();
        ui->label->setText("Playing: " + selectedSong.getTitle() + " — " + selectedSong.getArtist());
    }
}
void MainWindow::applyFilters() {
    QString searchText = ui->searchLineEdit->text().trimmed().toLower();
    QString selectedGenre = ui->genreComboBox->currentText().trimmed().toLower();
    QString selectedArtist = ui->artistComboBox->currentText();

    qDebug() << "SEARCH : "<< searchText << "|GENRE : " << selectedGenre << "|ARTIST : " << selectedArtist;

    QVector<Song> filteredSongs;
    for (const Song &song : m_library.getAllSongs()) {
        bool matchesSearch = searchText.isEmpty() || song.getTitle().toLower().contains(searchText)||song.getArtist().toLower().contains(searchText);
        bool matchesGenre = (selectedGenre == "all genres") || (selectedGenre == "all")||selectedGenre.isEmpty()|| (song.getGenre().toLower() == selectedGenre);
        bool matchesArtist = (selectedArtist == "all artists") || (selectedArtist == "all")||selectedArtist.isEmpty()|| (song.getArtist().toLower() == selectedArtist);

        if (matchesSearch && matchesGenre && matchesArtist) {
            filteredSongs.append(song);
        }
    }
    refreshSongList(filteredSongs);
}
void MainWindow::onPrevClicked(){
    int currentRow = ui->songListWidget->currentRow();
    if (currentRow > 0) {
        ui->songListWidget->setCurrentRow(currentRow - 1);
        emit ui->songListWidget->itemClicked(ui->songListWidget->currentItem());
    }
}
void MainWindow::onNextClicked() {
    int currentRow = ui->songListWidget->currentRow();
    if (currentRow < ui->songListWidget->count() - 1) {
        ui->songListWidget->setCurrentRow(currentRow + 1);
        emit ui->songListWidget->itemClicked(ui->songListWidget->currentItem());
    }
}
