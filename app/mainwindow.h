#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onPlayClick();
    void onPauseClick();
    void onStopClick();
    void onNextClick();
    void onPreviousClick();
    void onAddSongsClick();
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onVolumeChanged(int volume);
    void onSeekSliderMoved(int position);
    void onRemoveSongClick();
    void onClearPlaylistClick();

private:
    void initializeConnections();
    void updateSongDisplay();
    void loadPlaylist();
    
    Ui::MainWindow *ui;
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    QStringList playlist;
    int currentIndex;
    bool isSliderBeingDragged;
};
#endif // MAINWINDOW_H
