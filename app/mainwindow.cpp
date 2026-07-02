#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QFileInfo>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSongSelected(int currentRow) {
    if (currentRow <0 || currentRow >=musicLibrary.size())
    return; // If the selected row is out of bounds, do nothing.

    Song selectedTrack = musicLibrary [currentRow]; // Get the selected song from the music library based on the current row.
    
    QPixmap pix(selectedTrack.imagePath); // Load the album art image for the selected song.
    if (!pix.isNull()) {
        ui-> coverLabel->setPixmap(pix.scaled(ui->coverLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // If the image is valid, display it in the cover label. 
    }
}