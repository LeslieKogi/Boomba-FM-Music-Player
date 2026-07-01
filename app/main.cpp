#include <QApplication>
#include <QAudioOutput>
#include <QMediaPlayer>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *output = new QAudioOutput;

    player->setAudioOutput(output);
    player->setSource(QUrl::fromLocalFile("C:/Users/bridg/Downloads/time.mp3"));
    output->setVolume(0.8);
    player->play();

    return a.exec();
}
