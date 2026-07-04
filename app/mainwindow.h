#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "musiclibrary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onSongClicked();
    void onPlayClicked();
    void onPauseClicked();
    void onSearchTextChanged(const QString &text);
    void onGenreFilterChanged(const QString &genre);
    void onArtistFilterChanged(const QString &artist);

    // the playback signal handlers
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);

private:
    Ui::MainWindow *ui;
    MusicLibrary m_library;
    QVector<Song> m_currentDisplayedSongs; 

    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    int currentIndex;

    void refreshSongList(const QVector<Song> &songs);
    void populateFilterBoxes();
    void initializeConnections();
    void updateSongDisplay();
};
#endif 