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

    QDir songsDir("songs"); // Direct to song folder.
    QStringList mp3Files = songsDir.entryList(QStringList() << "*.mp3", QDir::Files); //Look for only mp3 files.
    for (const QString &fileName : mp3Files) { // Loop through every single mp3 file in the folder.
        Song track;
        track.filePath = "songs/"+ fileName; // Set file path automatically.
        QString cleanName = fileName;
        cleanName.chop(4); // Remove the '.mp3 from the end offile name.
        QStringList nameParts = cleanName.split(" - "); // Split the file name into parts based on the " - " separator.
        if (nameParts.size() >=2){
            track.artist = nameParts[0].trimmed(); // Set the artist name from the first part of the file name.
            track.title = nameParts[1].trimmed(); // Set the song title from the second part of the file name.

        }
        else {
            track.artist = "Unknown Artist"; // If the file name doesn't follow the expected format, set artist as "Unknown Artist".
            track.title = cleanName; // Set the song title as the cleaned file name.
        }
        track.genre = "My Music";
        track.imagePath = "images/default.png"; // Set a default image path for the song.

        musicLibrary.append(track);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}